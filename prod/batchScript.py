#!/usr/local/python-2.7.6/bin/python

"""
This is a new and improved job submission/collation script.
The text files read and manipulated by this script will be
valid XML files to ensure robustness
"""
import xml.etree.ElementTree as ET
from optparse import OptionParser
from optparse import OptionGroup
from subprocess import call
import glob
import copy
import os
import sys
import stat
import string
import shutil
import gzip
import re


def main() :

    #================================================================================
    # Command line options
    #================================================================================
    
    optParser = OptionParser(usage = '%prog [options] CONFIG_FILE',
                             description = 'A script to manage Hereward jobs. Python version >= 2.5 needed (setupRelease 0.5.1 should do the trick)')

    # Required
    reqGroup = OptionGroup(optParser, "Required options",
                           "One and only one of these options must be specified together with a mode option")
    reqGroup.add_option("-s", "--submit", action = "store_true", dest = "submit_flag", default = False,
                        help = "Submit one or more jobs to the batch queue");
    reqGroup.add_option("-S", "--submitOnebyOne", action = "store_true", dest = "submitOnebyOne_flag", default = False,
                        help = "Submit one or more jobs to the batch queue one by one");
    reqGroup.add_option("-r", "--resubmit", action = "store_true", dest = "resubmit_flag", default = False,
                        help = "Resubmits jobs which have failed.");
    reqGroup.add_option("-c", "--collate", action = "store_true", dest = "collate_flag", default = False,
                        help = "Collate one or more jobs");
    reqGroup.add_option("-d", "--delete", action = "store_true", dest = "delete_flag", default = False,
                        help = "Delete job folders. Make sure to verify collated results first!!!");
    optParser.add_option_group(reqGroup)

    # Modes
    modeGroup = OptionGroup(optParser, "Mode", "One and only one mode must be specified")
    modeGroup.add_option("-j", "--job", type = "string", nargs = 3, dest = "job",
                         help = "Submit/Collate/Delete one job. Requires 3 arguments: Job name, Number of jobs, Path to Datalist")
    modeGroup.add_option("-m", "--manyJobs", type = "string", nargs = 1, dest = "manyJobs",
                         help = "Submit/Collate/Delete several jobs. Requires 1 argument: a Job list file")
    optParser.add_option_group(modeGroup)

    # Additional
    optGroup = OptionGroup(optParser, "Additional options", "Choose at will :)")
    optGroup.add_option("-l", "--latex", action = "store_true", dest = "latex", default = False,
                        help = "Make Latex tables for cut flow, job summary and run status controller log when collating.")
    optGroup.add_option("-t", "--text", action = "store_true", dest = "text", default = False,
                        help = "Make text tables for cut flow, job summary and run status controller log when collating.")
    optGroup.add_option("-e", "--csv", action = "store_true", dest = "csv", default = False,
                        help = "Make csv files for cut flow, job summary and run status controller log when collating.")
    optGroup.add_option("-n", "--dry-run", action = "store_true", dest = "dry", default = False,
                        help = "Dry run. Will not submit jobs, call hadd or delete files, but it will create directories and copy files.")


    optParser.add_option_group(optGroup)
    
    (options, args) = optParser.parse_args()

    #================================================================================
    # Some basic checks of the options
    #================================================================================

    # Correct number of arguments
    if len(args) != 1 :
        optParser.error( 'Invalid number of arguments! For help type ./batchScript.py -h\n Quitting... ')
        
    # One and only one required option:
    if not ( options.submit_flag ^ options.submitOnebyOne_flag ^ options.collate_flag ^ options.delete_flag ) :
        optParser.error( 'One and only one required option allowed, Quitting... ')
        
    # One and only one mode:
    if not ( (options.job != None) ^ (options.manyJobs != None) ) :
        optParser.error( 'One and only one mode allowed, Quitting... ')

    #================================================================================
    # Let's get down to business
    #================================================================================

    # Dictionary to store Configuration parameters
    cfgPars = {}
    # Dictionary to store Job parameters
    jobPars = {}

    # Verify configuration file and read to memory
    readConfig( cfgDict = cfgPars, filename = args[0] )

    # If single job option is selected:
    if options.job != None :
        #       Job name           Num Jobs        Datalist
        jobPars[options.job[0]] = [options.job[1], options.job[2]]
    # If manyJobs option is selected:
    elif options.manyJobs != None :
        readJobList( jobDict = jobPars, filename = options.manyJobs )

    # Check job parameters:
    checkJobList( jobPars = jobPars, cfgPars = cfgPars, optPars = options )

    # nuff checkin, do something!
    if options.submitOnebyOne_flag :
        submitOnebyOne(cfgPars = cfgPars, jobPars = jobPars, optPars = options)
    if options.submit_flag :
        submit (cfgPars = cfgPars, jobPars = jobPars, optPars = options)
    if options.delete_flag :
        delete (cfgPars = cfgPars, jobPars = jobPars, optPars = options)
    if options.collate_flag :
        collate (cfgPars = cfgPars, jobPars = jobPars, optPars = options)
        writeNiceOutput(cfgPars = cfgPars, jobPars = jobPars, optPars = options)
    if options.resubmit_flag :
        reSubmit(cfgPars = cfgPars, jobPars = jobPars, optPars = options)
    print 'Batch script ends. Cya!'  

#================================================================================
# This function reads a configuration file into a dictionary
#================================================================================
    
def readConfig( cfgDict, filename ) :

    # Check configuration file exists
    print 'Configuration file: '+filename+'\n'
    if not os.path.isfile(filename) :
        print 'Error: Invalid path to configuration file'
        return

    # Open configuration file
    configFile = open(filename, 'r')

    # Read configuration file
    for cfg in configFile:
        cfgList = cfg.split(" ")
        if cfgList[0][:1] == '#' :
            continue
        if len(cfgList) == 2:
            cfgDict[cfgList[0]] = cfgList[1].rstrip()

    # Print configuration file to screen
    for par in cfgDict :
        print string.ljust(par,20), string.ljust(cfgDict[par],100)
    print '\n'

    # Check contents of configuration file
    if not os.path.isfile(cfgDict['RunList']) :
        print 'Error: RunList does not exist'
        sys.exit(-1)
    if not os.path.isfile(cfgDict['SuperNemoConfig']) :
        print 'Error: SuperNemoConfig does not exist'
        sys.exit(-1)
    if not os.path.isdir(cfgDict['RelPath']) :
        print 'Error: RelPath does not exist'
        sys.exit(-1)
    if not os.path.isfile(cfgDict['RelPath']+'bin/'+cfgDict['ExecName']) :
        print 'Error: RelPath/ExecName does not exist'
        sys.exit(-1)
    if not os.path.isdir(cfgDict['OutPath']) :
        print 'Error: OutPath does not exist'
        sys.exit(-1)
    if 'CfgFile' in cfgDict :
        if not os.path.isdir(cfgDict['CfgFile']) :
            print 'Warning: No runtime configuration file path given'
    if cfgDict['Queue'] not in ['short', 'medium', 'long'] :
        print 'Error: Queue must be short, medium or long'
        sys.exit(-1)
    if not os.path.isdir(os.environ['SNSOFT_RELEASES_BASE_DIR']+'/'+cfgDict['RelVer']) :
        print 'Error: invalid release version ', cfgDict['RelVer']
        sys.exit(-1)
    if not cfgDict['Nev'].isdigit() :
        print 'Warning: Nev not provided in configuration file. Using default -1'

        
#================================================================================
# This function reads a file with a list of jobs into a dictionary
#================================================================================
# The lines in the file should have the format:
# JobName SplitNumber Path/to/Datalist
def readJobList( jobDict, filename) :
    
    # Check jobList file exists
    print 'JobList file: '+filename+'\n'
    if not os.path.isfile(filename) :
        print 'Error: Invalid path to JobList file'
        return

    # Open Job list file
    jobFile = open(filename)

    # Read Job list file to memory
    for job in jobFile :
        jobList = job.split(" ")
        if jobList[0][:1] == '#' :
            continue
        if len(jobList) == 3 :
            jobDict[jobList[0]] = []
            jobDict[jobList[0]].append(jobList[1])
            jobDict[jobList[0]].append(jobList[2].rstrip())
    
#================================================================================
# This function checks that the job list makes sense
#================================================================================
def checkJobList( jobPars, optPars , cfgPars ) :

    for job in jobPars :
        if not jobPars[job][0].isdigit() :
            print 'Error: number of jobs must be a number'
            sys.exit(-1)
        for i in range(1, int(jobPars[job][0])+1) :
            if optPars.submit_flag and os.path.isdir(cfgPars['OutPath']+job+'_'+str(i)) :
                print 'Error: Output directories exist'
                print cfgPars['OutPath']+job+'_'+str(i)
                sys.exit(-1)
            elif optPars.collate_flag and not os.path.isdir(cfgPars['OutPath']+job+'_'+str(i)) :
                print 'Error: Directories to be collated do not exist'
                print cfgPars['OutPath']+job+'_'+str(i)
                sys.exit(-1)
            elif optPars.delete_flag and not os.path.isdir(cfgPars['OutPath']+job+'_'+str(i)) :
                print 'Error: Directories to be deleted do not exist'
                print cfgPars['OutPath']+job+'_'+str(i)
                sys.exit(-1)
        if not os.path.isfile(jobPars[job][1]) :
            print 'Error: Datalist does not exist'
            print jobPars[job][1]
            sys.exit(-1)
                        
    # Print job list to screen
    for job in jobPars :
        print string.ljust(job,15), string.rjust(jobPars[job][0],3), string.ljust(jobPars[job][1],100)


#================================================================================
# This function submits the jobs to the queue
#================================================================================
def submit(cfgPars, jobPars, optPars) :

    print "Submitting jobs to farm"

    # Create output directories:
    for job in jobPars :
        for i in range(1, int(jobPars[job][0])+1) :
            print cfgPars['OutPath']+job+'_'+str(i)
            os.makedirs(cfgPars['OutPath']+job+'_'+str(i))

    # Split datalist
    for job in jobPars :
        dataFile = open(jobPars[job][1], 'r')
        dataList = dataFile.readlines()
        filesPerJob = len(dataList)/int(jobPars[job][0])
        remainder = len(dataList)%int(jobPars[job][0])
        for i in range(0, int(jobPars[job][0])) :
            # Split datalists into approximately equal chunks
            # and write them to the appropriate directories:
            splitFile = open(cfgPars['OutPath']+job+'_'+str(i+1)+"/aDataList.lst" , 'w')
            if i < remainder :
                for j in range(i*(filesPerJob+1), (i+1)*(filesPerJob+1)) :
                    splitFile.write(dataList[j])
            else :
                for j in range(remainder + i*filesPerJob, remainder + (i+1)*filesPerJob) :
                    splitFile.write(dataList[j])
            splitFile.close()

    # Look at reco logs, if available, and make list of number of events assigned to runs
    for job in jobPars :
        # First find out if there are reco logs for this sample:
        dataListFile = open(cfgPars['OutPath']+job+'_'+str(1)+"/aDataList.lst" , 'r')
        recoPath = dataListFile.readline()

        #                                  reco base path             log dir  reco file basename                             log ext
        if not os.path.isfile(os.path.join(os.path.split(recoPath)[0], 'log', os.path.splitext(os.path.split(recoPath)[1])[0]+'.log.gz')) :
            continue

        # We want to match two patterns in the log files:
        # 'JUMP' to find out what the first event number in the log is:
        jumpPattern =  'DATA CARD CONTENT     JUMP(?P<jump>.*?)\n'
        jumpP = re.compile(jumpPattern)

        # And the sequence where the number of events attributed to each run is written
        masterPattern = 'FOR NEXT (?P<nEvs>.*?) EVENTS THE CONDITIONS OF RUN (?P<runN>.*?) WILL BE USED.*\n.*IEVENT=(?P<ievent>.*?)NLAST=(?P<nlas>.*?)\n'
        masterP = re.compile(masterPattern)

        # Loop through all jobs in sample
        for i in range (1, int(jobPars[job][0]) + 1) :
            # A dictionary to keep our numbers
            assignedEvents = {}

            # Get our datalist
            dataListFile = open(cfgPars['OutPath']+job+'_'+str(i)+"/aDataList.lst" , 'r')
            dataList = dataListFile.readlines()

            # Loop through reco files in dataList:
            for dataFile in dataList :
                # Open the log file

                # Check this doesn't contain 'betabeta'
                if 'betabeta' in os.path.splitext(os.path.split(dataFile)[1])[0].split('_') :
                    print 'This is a data file. Ignoring logs and creating a dummy RecoAssignedEvents file.'
                    assignedEvents[-1] = -1
                    continue


                if not os.path.isfile(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents', os.path.splitext(os.path.split(dataFile)[1])[0]+'.txt')) :

                    # This dictionary is for writing the events assigned to runs in a particular
                    # MC file to disk so we don't have to scan through the logs everytime we
                    # do this
                    assignedEventsFile = {}
                
                    log = gzip.open(os.path.join(os.path.split(dataFile)[0], 'log', os.path.splitext(os.path.split(dataFile)[1])[0]+'.log.gz'), 'r')
                    logContent = log.read()

                    # Find the 'JUMP' number
                    jump = jumpP.findall(logContent)

                    # Find all runs and assigned events
                    runs = masterP.findall(logContent)

                    # Loop through runs
                    # The last run is always duplicated in the logs, so we'll ignore it
                    for j in range(0, len(runs) - 1) :
                        run        = int(runs[j][1])
                        firstEvent = int(runs[j][2])
                        lastEvent  = int(runs[j][3])

                        # Replace event '1' by 'JUMP'
                        if firstEvent == 1 :
                            firstEvent = int(jump[0])

                        # Check if run is already in our dictionary
                        if run not in assignedEvents :
                            # Add new run to dict
                            assignedEvents[run] = (lastEvent - firstEvent)
                        else :
                            # Increment event count
                            assignedEvents[run] += (lastEvent - firstEvent)

                        # This is in principle not necessary, but just in case
                        if run not in assignedEventsFile :
                            assignedEventsFile[run] = (lastEvent - firstEvent)
                        else :
                            assignedEventsFile[run] += (lastEvent - firstEvent)

                    # Now write this to disk
                    if not os.path.isdir(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents') ) :
                        os.makedirs(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents') )
                        st = os.stat(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents'))
                        os.chmod(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents'), st.st_mode | stat.S_IWGRP)

                        
                    processedLogFile = open(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents', os.path.splitext(os.path.split(dataFile)[1])[0]+'.txt') , 'w')
                    st = os.stat(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents', os.path.splitext(os.path.split(dataFile)[1])[0]+'.txt'))
                    os.chmod(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents', os.path.splitext(os.path.split(dataFile)[1])[0]+'.txt'),st.st_mode | stat.S_IWGRP)
                    for run in assignedEventsFile :
                        processedLogFile.write(str(run).rjust(7)+str(assignedEventsFile[run]).rjust(9)+'\n')

                # If this log file has already been scanned :
                else :
                    processedLogFileIn = open(os.path.join(os.path.split(dataFile)[0], 'RecoAssignedEvents', os.path.splitext(os.path.split(dataFile)[1])[0]+'.txt'), 'r')
                    processedAssgnEvs = processedLogFileIn.readlines()
                    for line in processedAssgnEvs :
                        lineList = line.split()
                        run = int(lineList[0])
                        assEvs = int(lineList[1])
                        if run not in assignedEvents :
                            # Add new run to dict
                            assignedEvents[run] = assEvs
                        else :
                            # Increment event count
                            assignedEvents[run] += assEvs
                            
                    
            # We've got all we need now. Write to disc.
            recoAssignedEvsFile = open(cfgPars['OutPath']+job+'_'+str(i)+"/RecoAssignedEvents.txt", 'w')
            for run in assignedEvents :
                recoAssignedEvsFile.write(str(run).rjust(7)+str(assignedEvents[run]).rjust(9)+'\n')

    # Copy over the runtime configuration file if it exists
    if 'CfgFile' in cfgPars :
        for job in jobPars :
            for i in range (1, int(jobPars[job][0]) + 1) :
                shutil.copy(cfgPars['CfgFile'], cfgPars['OutPath']+job+'_'+str(i)+'/aConfigFile.txt')

    # Copy over the runList
    for job in jobPars :
        for i in range(1, int(jobPars[job][0]) + 1) :
            shutil.copy(cfgPars['RunList'], cfgPars['OutPath']+job+'_'+str(i)+'/aRunList.lst')

    # Write job scripts
    for job in jobPars :
        for i in range(1, int(jobPars[job][0]) + 1) :
            scriptFile = open(cfgPars['OutPath']+job+'_'+str(i)+'/'+job+'_'+str(i)+'.sh', 'w')
            scriptFile.write('#/bin/bash\n\n')
            scriptFile.write('# Set up environment\n')
            scriptFile.write('source '+cfgPars['SuperNemoConfig']+'\n')
            scriptFile.write('cd '+cfgPars['RelPath']+'\n')
            scriptFile.write('setupRelease '+cfgPars['RelVer']+'\n')
            scriptFile.write('source config.sh'+'\n')
            scriptFile.write('cd '+cfgPars['OutPath']+job+'_'+str(i)+'\n\n')
            scriptFile.write('# Make working directory in local machine \n')
            scriptFile.write('mkdir -p '+'/work/HerewardTmp_$(whoami)/'+job+'_'+str(i)+'\n')
            scriptFile.write('# Let\'s not move this file while the script is running \n')
            scriptFile.write('GLOBIGNORE=\"'+job+'_'+str(i)+'.sh'+'\"'+'\n\n')
            scriptFile.write('# Move all lists to working directory\n')
            scriptFile.write('cp * '+'/work/HerewardTmp_$(whoami)/'+job+'_'+str(i)+'\n')
            scriptFile.write('# Change to working directory\n')
            scriptFile.write('cd '+'/work/HerewardTmp_$(whoami)/'+job+'_'+str(i)+'\n\n')
#            scriptFile.write('# Copy data files to working directory\n')
#            scriptFile.write('mkdir dataTemp\n')
#            scriptFile.write('while read dataLine; do mv $dataLine dataTemp/; done < aDataList.lst\n')
#            scriptFile.write('# Make new datalist and backup old one\n')
#            scriptFile.write('mv aDataList.lst aDataList.lst.backup\n')
#            scriptFile.write('ls dataTemp/* >> aDataList.lst\n\n')
            scriptFile.write('# RUN Hereward !\n')
            scriptFile.write('echo Running '+cfgPars['ExecName']+' from `pwd`'+'\n')
            if not cfgPars['Nev'].isdigit() :
                scriptFile.write(cfgPars['ExecName']+' -nev -1 > Output'+'\n\n')
            else :
                scriptFile.write(cfgPars['ExecName']+' -nev ' + cfgPars['Nev'] + ' > Output'+'\n\n')

#            scriptFile.write('# Hereward finished. Delete local copy of data\n')
#            scriptFile.write('rm -r dataTemp\n')
#            scriptFile.write('mv aDataList.lst.backup aDataList.lst\n')
            scriptFile.write('# Move output to ouput directory\n')
            scriptFile.write('mv * '+cfgPars['OutPath']+job+'_'+str(i)+'\n')
            scriptFile.write('# Remove temporary directories.\n')
            scriptFile.write('# Job-specific dir should be empty, but HerewardTmp might not be if other jobs are running on the same machine. We want to leave this alone.\n')
            scriptFile.write('rmdir '+'/work/HerewardTmp_$(whoami)/'+job+'_'+str(i)+'\n')
            scriptFile.write('rmdir '+'/work/HerewardTmp_$(whoami)/'+'\n')            
            scriptFile.close()

    # And finally submit jobs
    currentDir = os.getcwd()
    for job in jobPars :
        for i in range(1, int(jobPars[job][0]) + 1) :
            os.chdir(cfgPars['OutPath']+job+'_'+str(i))
            print 'qsub -q', cfgPars['Queue'],job+'_'+str(i)+'.sh'
            if not optPars.dry :
                call(['qsub', '-q',cfgPars['Queue'], job+'_'+str(i)+'.sh'])
    os.chdir(currentDir)

#================================================================================
# This function submits a jobList to the queue job by job
#================================================================================
def submitOnebyOne(cfgPars, jobPars, optPars) :
    for job in jobPars :
        singleJobPars = {}

        singleJobPars[job] = [jobPars[job][0], jobPars[job][1]]

        submit(cfgPars = cfgPars, optPars = optPars, jobPars = singleJobPars)

        
#================================================================================
# This function collates jobs and associated metadata
#================================================================================
def collate(cfgPars, jobPars, optPars) :

    # Check that directory to put collated files in does not exist
    for job in jobPars :
        if os.path.isdir(cfgPars['OutPath']+job) :
            print 'Error: ouput directory exists\n'+cfgPars['OutPath']+job
            sys.exit(-1)

    # Go into directories and check that jobs finished OK
    # This is done by reading the .sh.e* file and looking at the last
    # line. This must be changed if, e.g., the output statements of the
    # database change.  

#    dbSignOff = '  Thank you to choose C++ database interface of NEMO-3 project ! See you later.\n'
#    dbSignOffPos = -2

# Just look for the output root file, since error files are sometimes unreliable    
    for job in jobPars :
        failedJobs = []
        for i in range(1, int(jobPars[job][0])+1):
            if not os.path.isfile(cfgPars['OutPath']+job+'_'+str(i)+'/'+cfgPars['ExecName']+'_output.root') :
                failedJobs.append(cfgPars['OutPath']+job+'_'+str(i)+'/'+cfgPars['ExecName']+'_output.root')

        if len(failedJobs) > 0 :
            print 'The following jobs failed. Run them again before collating:'
            for job in failedJobs :
                print job
            sys.exit(-1)
#            errorFiles = glob.glob(cfgPars['OutPath']+job+'_'+str(i)+'/'+job+'_'+str(i)+'.sh.e*')
#            if len(errorFiles) == 0 :
#                print 'Error: no farm error file found.', job, i
#                sys.exit(-1)
#            batchRet = open(errorFiles[-1])
#            batchRetLines = batchRet.readlines()
#            if len(batchRetLines) == 0 :
#                print 'Error: invalid farm error file.', job, i
#                sys.exit(-1)
#            if batchRetLines[dbSignOffPos] != dbSignOff :
#                print 'Error: Unexpected error file termination\n', errorFiles[-1]
#                sys.exit(-1)

    # If all jobs ok create directory to write collated stuff to
    for job in jobPars :
        os.makedirs(cfgPars['OutPath']+job)
        
        # hadd root files
        haddArgsList = []
        haddArgsList.append('hadd')
        haddArgsList.append(cfgPars['OutPath']+job+'/'+cfgPars['ExecName']+'_output.root')
        for i in range(1, int(jobPars[job][0])+1) :
            haddArgsList.append(cfgPars['OutPath']+job+'_'+str(i)+'/'+cfgPars['ExecName']+'_output.root')
        print 'calling hadd', haddArgsList
        if not optPars.dry :
            call(haddArgsList)

    # Collate RunStatusControllerResult files
    # Read in first RunStatusControllerResult file
    for job in jobPars :
        runStatCtrlTree = ET.parse(cfgPars['OutPath']+job+'_1/RunStatusControllerResult.xml')
        runStatCtrlRoot = runStatCtrlTree.getroot()

        # Look at the other files
        for i in range(2, int(jobPars[job][0])+1) :
            tempRunStatCtrlTree = ET.parse(cfgPars['OutPath']+job+'_'+str(i)+'/RunStatusControllerResult.xml')
            tempRunStatCtrlRoot = tempRunStatCtrlTree.getroot()

            # Make list of runs currently in RunStatCtrlRoot
            currentRunList = [run.find('number').text for run in runStatCtrlRoot.findall('run')]

            # Add runs that are not in RunStatCtrlRoot
            for run in tempRunStatCtrlRoot.findall('run') :
                if ( run.findtext('number') not in currentRunList ) :
                    runStatCtrlRoot.append(copy.deepcopy(run))
        runStatCtrlTree.write(cfgPars['OutPath']+job+'/RunStatusControllerResult.xml')                   

    # Collate CutFlow
    for job in jobPars :
        cutFlowTree = ET.parse(cfgPars['OutPath']+job+'_1/CutFlow.xml')
        cutFlowRoot = cutFlowTree.getroot()

        for i in range(2, int(jobPars[job][0]) + 1) :
            tempCutFlowTree = ET.parse(cfgPars['OutPath']+job+'_'+str(i)+'/CutFlow.xml')
            tempCutFlowRoot = tempCutFlowTree.getroot()


            for tempCut in tempCutFlowRoot.findall('cut') :
                cutFound = False
                for cut in cutFlowRoot.findall('cut') :
                    if cut.findtext('name') == tempCut.findtext('name') :
                        cut.find('passEvents').text = str(float(cut.findtext('passEvents')) + float(tempCut.findtext('passEvents')))
                        cutFound = True
                        break
                if not cutFound :
                    cutFlowRoot.append(copy.deepcopy(tempCut))

        cutFlowTree.write(cfgPars['OutPath']+job+'/CutFlow.xml')
        
    # Do sums for JobSummary from RunstatusConroller
    for job in jobPars :
        runStatCtrlTree = ET.parse(cfgPars['OutPath']+job+'/RunStatusControllerResult.xml')
        runStatCtrlRoot = runStatCtrlTree.getroot()
                      
        jobSummaryTree = ET.parse(cfgPars['OutPath']+job+'_1/JobSummary.xml')
        jobSummaryRoot = jobSummaryTree.getroot()

        totalRunTime = 0
        totalDeadTime = 0.

        accptRunTime = 0
        accptDeadTime = 0.

        accptRunTimeP1 = 0
        accptRunTimeP2 = 0

        accptDeadTimeP1 = 0.
        accptDeadTimeP2 = 0.
        
        recoRunTime = 0
        recoAccptTime = 0

        for run in runStatCtrlRoot :
            # All runs
            totalRunTime  += int(run.findtext('length'))
            totalDeadTime += float(run.findtext('deadTime'))

            # Accepted runs
            if int(run.findtext('accepted')) == 1 :
                accptRunTime  += int(run.findtext('length'))
                accptDeadTime += float(run.findtext('deadTime'))

                # Phase 1
                if int(run.findtext('number')) < 3396 :
                    accptRunTimeP1  += int(run.findtext('length'))
                    accptDeadTimeP1 += float(run.findtext('deadTime'))
                else :
                    accptRunTimeP2  += int(run.findtext('length'))
                    accptDeadTimeP2 += float(run.findtext('deadTime'))

            
        jobSummaryRoot.find('totalRunTime').text = str(totalRunTime)
        jobSummaryRoot.find('totalDeadTime').text = str(totalDeadTime)

        jobSummaryRoot.find('totalAcceptedRunTime').text = str(accptRunTime)
        jobSummaryRoot.find('totalAcceptedDeadTime').text = str(accptDeadTime)

        jobSummaryRoot.find('totalAcceptedRunTimeP1').text = str(accptRunTimeP1)
        jobSummaryRoot.find('totalAcceptedDeadTimeP1').text = str(accptDeadTimeP1)

        jobSummaryRoot.find('totalAcceptedRunTimeP2').text = str(accptRunTimeP2)
        jobSummaryRoot.find('totalAcceptedDeadTimeP2').text = str(accptDeadTimeP2)

        # If this is monteCarlo Go into Job summaries and collate number of events generated

        if ( jobSummaryRoot.find('Data') == None and jobSummaryRoot.find('MC') != None ) :
            # is MC
            for i in range(2, int(jobPars[job][0]) + 1) :
                tempJobSummaryTree = ET.parse(cfgPars['OutPath']+job+'_'+str(i)+'/JobSummary.xml')
                tempJobSummaryRoot = tempJobSummaryTree.getroot()

                jobSummaryRoot.find('totGenEvents').text = str(float(jobSummaryRoot.findtext('totGenEvents')) + float(tempJobSummaryRoot.findtext('totGenEvents')))
                jobSummaryRoot.find('totAssignedEvents').text = str(float(jobSummaryRoot.findtext('totAssignedEvents')) + float(tempJobSummaryRoot.findtext('totAssignedEvents')))
                jobSummaryRoot.find('totAccAssignedEvents').text = str(float(jobSummaryRoot.findtext('totAccAssignedEvents')) + float(tempJobSummaryRoot.findtext('totAccAssignedEvents')))

        elif ( jobSummaryRoot.find('Data') != None and jobSummaryRoot.find('MC') == None ) :
            # Is Data, do nothing
            True
        else :
            # Is dodgy
            print 'ERROR: collate: I don\'t understand if this is data or MC'
        jobSummaryTree.write(cfgPars['OutPath']+job+'/JobSummary.xml')


#================================================================================
# This function resubmits failed jobs
#================================================================================
def reSubmit(cfgPars, jobPars, optPars) :

    currentDir = os.getcwd()

    for job in jobPars :
        for i in range (1, int(jobPars[job][0]) + 1) :
            if not os.path.isdir(cfgPars['OutPath']+job+'_'+str(i)) :
                print 'Warning: directory', cfgPars['OutPath']+job+'_'+str(i), 'does not exist. Ignoring.'
                continue

            fail = False

            # If there is no .root file
            if not os.path.isfile(cfgPars['OutPath']+job+'_'+str(i)+'/'+cfgPars['ExecName']+'_output.root') :
                fail = True
                # If farm error file doesn't exist
            errorFiles = glob.glob(cfgPars['OutPath']+job+'_'+str(i)+'/'+job+'_'+str(i)+'.sh.e*')
            if len(errorFiles) == 0 :
                fail = True
            batchRet = open(errorFiles[-1])
            batchRetLines = batchRet.readlines()
            # Farm error file is empty (has happened!)
            if len(batchRetLines) == 0 :
                fail = True
            # Unexpected ending of error file
            dbSignOff = '  Thank you to choose C++ database interface of NEMO-3 project ! See you later.\n'
            dbSignOffPos = -2
            if batchRetLines[dbSignOffPos] != dbSignOff :
                fail = True

            # If job has failed, resubmit it
            if fail :
                os.chdir(cfgPars['OutPath']+job+'_'+str(i))
                print 'Job Failed! resubmitting', job+'_'+str(i)+'.sh'
                if not optPars.dry :
                    call(['qsub', '-q',cfgPars['Queue'], job+'_'+str(i)+'.sh'])

    os.chdir(currentDir)

#================================================================================
# This function writes out nicely formatted things
#================================================================================
def writeNiceOutput(cfgPars, jobPars, optPars) :

    if not (optPars.latex or optPars.csv or optPars.text) :
        return
    

    jobList = []
    for job in jobPars :
        jobList.append(cfgPars['OutPath']+job)
        for i in range(1, int(jobPars[job][0]) + 1) :
            jobList.append(cfgPars['OutPath']+job+'_'+str(i))

    # Run status controller result
    for job in jobList :
        if os.path.isfile(job+'/RunStatusControllerResult.xml') :
            runStatCtrlTree = ET.parse(job+'/RunStatusControllerResult.xml')
            runStatCtrlRoot = runStatCtrlTree.getroot()

            # Write headers
            if optPars.latex :
                latexRSC = open(job+'/RunStatusControllerResult.tex', 'w')
                latexRSC.write('\\begin{tabular}[r r r r r r r r]\n')
                latexRSC.write('Number & Length & DeadTime & AssgnEvts & Status & Accepted \\\\ \\hline\n')
            if optPars.text :
                textRSC = open(job+'/RunStatusControllerResult.txt', 'w')
                textRSC.write('Number'.rjust(7)+'Length'.rjust(7)+'DeadTime'.rjust(12)+'AssgnEvts'.rjust(12)+'Status'.rjust(12)+'Accepted'.rjust(9)+'\n')
            if optPars.csv :
                csvRSC = open(job+'/RunStatusControllerResult.csv', 'w')
                csvRSC.write('Number,Length,DeadTime,AssgnEvts,Status,Accepted\n')

            # Write entries
            for run in runStatCtrlRoot :
                if optPars.latex :
                    latexRSC.write(run.find('number').text +' & '+run.find('length').text+' & '+run.find('deadTime').text+' & '+run.find('assignedEvents').text+' & '+run.find('status').text+' & '+run.find('accepted').text+' \\\\ \n')
                if optPars.text :
                    textRSC.write(run.find('number').text.rjust(7)+run.find('length').text.rjust(7)+run.find('deadTime').text.rjust(12)+run.find('assignedEvents').text.rjust(12)+run.find('status').text.rjust(12)+run.find('accepted').text.rjust(9)+'\n')
                if optPars.csv :
                    csvRSC.write(run.find('number').text +','+run.find('length').text+','+run.find('deadTime').text+','+run.find('assignedEvents').text+','+run.find('status').text+','+run.find('accepted').text+'\n')

            # Write end of files
            if optPars.latex :
                latexRSC.write('\\end{tabular}\n')

        else :
            print 'writeNiceOutput: no '+job+'/RunStatusControllerResult.xml found'

        # Cut flow
        if os.path.isfile(job+'/CutFlow.xml') :
            cutFlowTree = ET.parse(job+'/CutFlow.xml')
            cutFlowRoot = cutFlowTree.getroot()

            # Write headers
            if optPars.latex :
                latexCF = open(job+'/CutFlow.tex', 'w')
                latexCF.write('\\begin{tabular}[l r r]\n')
                latexCF.write('Criterion & Events & Efficiency \\\\ \\hline\n')
            if optPars.text :
                textCF = open(job+'/CutFlow.txt', 'w')
                textCF.write('Criterion'.ljust(60)+'Events'.rjust(12)+'Efficiency'.rjust(12)+'\n')
            if optPars.csv :
                csvCF = open(job+'/CutFlow.csv', 'w')
                csvCF.write('Criterion,Events,Efficiency\n')


            # Get Job summary to check if this is data or MC
            denom = 1

            if os.path.isfile(job+'/JobSummary.xml') :
                tempJobSummaryTree = ET.parse(job+'/JobSummary.xml')
                tempJobSummaryRoot = tempJobSummaryTree.getroot()

                if ( tempJobSummaryRoot.find('Data') == None and tempJobSummaryRoot.find('MC') != None ) :
                    # is MC
                    totGenEvs = float(tempJobSummaryTree.find('totGenEvents').text)
                    totAssEvs = float(tempJobSummaryTree.find('totAssignedEvents').text)
                    accAssEvs = float(tempJobSummaryTree.find('totAccAssignedEvents').text)

                    totRunTime = float(tempJobSummaryTree.find('totalRunTime').text)
                    totAccRunTime = float(tempJobSummaryTree.find('totalAcceptedRunTime').text)

                    # If number of assigned events and number of accepted assigned events is available

                    if (totAssEvs > 0 and accAssEvs > 0) :
                        denom = 1. / (totAssEvs / totGenEvs * 1 / accAssEvs)
                        print denom, totAssEvs, totGenEvs, accAssEvs
                    elif (totRunTime > 0) :
                        # If not scale by the accepted time
                        denom = totGenEvs * totAccRunTime / totRunTime
                        print denom, totGenEvs, totAccRunTime, totRunTime
                    else :
                        denom = -1
                        print 'Invalid Assigned events and run time info. Efficiency will not be calculated'
                                     
                elif ( tempJobSummaryRoot.find('Data') != None and tempJobSummaryRoot.find('MC') == None ) :
                    #is Data
                    # Hopefully this will return the number for the zeroth cut
                    denom = float(cutFlowRoot.find('cut/passEvents').text)
                else :
                    print 'writeNiceOutput: Cut flow: I\'m not sure whether I\'m looking at Data or MC....... Will treat as Data'
                    denom = float(cutFlowRoot.find('passEvents').text)
                
            else :
                print 'writeNiceOutput: Cut flow: Job summary not found. Efficiency denominator set to 1'
            if (denom == 0.) :
                denom = -1
                print 'Denominator was zero. set to -1'
                
            for cut in cutFlowRoot :
                nEvs = float(cut.find('passEvents').text)
                eff = nEvs/denom

                if optPars.latex :
                    latexCF.write(latexify(cut.find('name').text) + ' & ' + '%.0f' % nEvs + ' & ' +' %.2f' % (eff*100) + ' \\\\ \n')
                if optPars.text :
                    textCF.write(cut.find('name').text.ljust(60)+('%.0f' % nEvs).rjust(12)   +('%.2f'  % (eff*100)).rjust(12)+'\n')
                if optPars.csv :
                    csvCF.write('\"'+cut.find('name').text+'\",'+str(nEvs)+','+str(eff*100)+'\n')

            # Write end of files
            if optPars.latex :
                latexCF.write('\\end{tabular}\n')

            
        else :
            print 'writeNiceOutput: no '+job+'/CutFlow.xml found'

        # Print JobSummary
        if os.path.isfile(job+'/JobSummary.xml') :
            jobSummaryTree = ET.parse(job+'/JobSummary.xml')
            jobSummaryRoot = jobSummaryTree.getroot()

            if optPars.latex :
                latexJS = open(job+'/JobSummary.tex', 'w')
                latexJS.write('\\begin{tabular}[l r]\n')
            if optPars.text :
                textJS = open(job+'/JobSummary.txt', 'w')
            if optPars.csv :
                csvJS = open(job+'/JobSummary.csv', 'w')
                
            for field in jobSummaryRoot :
                if field.text == None :
                    continue
                if optPars.latex:
                    latexJS.write(field.tag + ' & ' + field.text + '\\\\ \n')
                if optPars.text : 
                    textJS.write(field.tag.ljust(30)  + field.text.rjust(20) + '\n')
                if optPars.csv :
                    csvJS.write(field.tag+','+field.text+'\n')

            # Write end of files
            if optPars.latex :
                latexJS.write('\\end{tabular}\n')

                    

#================================================================================
# This function deletes temporary job folders
#================================================================================
def delete(cfgPars, jobPars, optPars) :

    # Make sure user knows what's going to happen
    print 'About to remove folders: '
    for job in jobPars :
        for i in range(1, int(jobPars[job][0]) + 1) :
            print cfgPars['OutPath']+job+'_'+str(i)
    print 'Are you sure you want to remove the folders listed above?'
    decision = raw_input("Enter \'yes\': ")

    # Delete folders
    if( decision.lower() == 'yes') :
        for job in jobPars :
            for i in range(1, int(jobPars[job][0]) + 1) :
                print 'removing', cfgPars['OutPath']+job+'_'+str(i)
                if not optPars.dry :
                    shutil.rmtree( cfgPars['OutPath']+job+'_'+str(i)  )
    else :
        print 'Doing nothing.'
    

#================================================================================
# Prepares string for latex
#================================================================================
def latexify ( sometext ) :
    sometext = sometext.replace('>=', '$\ge$')
    sometext = sometext.replace('<=', '$\le$')
    sometext = sometext.replace('>', '$\>$')
    sometext = sometext.replace('<', '$\<$')
    return sometext


if __name__ == '__main__':
    main()

