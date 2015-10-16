# Check if cmake has the required version
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

project(NEMO3Ana)

include(FindROOT.cmake)

#Check the compiler and set the compile and link flags
set(CMAKE_BUILD_TYPE Debug)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

set(INCLUDE_DIRECTORIES ${ROOT_INCLUDE_DIR})
include_directories( ${INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES ${ROOT_LIBRARY_DIR})
link_directories( ${LINK_DIRECTORIES})

if (CMAKE_SYSTEM_NAME MATCHES Darwin)
   EXEC_PROGRAM("sw_vers -productVersion | cut -d . -f 1-2" OUTPUT_VARIABLE MAC_OS_VERSION)
   MESSAGE("--- Found a Mac OS X System ${MAC_OS_VERSION}")
   if (CMAKE_COMPILER_IS_GNUCXX)
      MESSAGE("--- Found GNU compiler collection")

      STRING(COMPARE EQUAL "10.5" "${MAC_OS_VERSION}" MAC_OS_10_5)
      IF(MAC_OS_10_5)
        SET(CMAKE_CXX_FLAGS "-m64")
        SET(CMAKE_Fortran_FLAGS "-m64")
      ENDIF(MAC_OS_10_5)

      SET(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS} -flat_namespace -single_module -undefined dynamic_lookup")
      SET(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -flat_namespace -single_module -undefined dynamic_lookup")

      # Select flags.
      set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
      set(CMAKE_CXX_FLAGS_RELEASE        "-O2")
      set(CMAKE_CXX_FLAGS_DEBUG          "-g -O2 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
      set(CMAKE_CXX_FLAGS_DEBUGFULL      "-g3 -fno-inline -Wnon-virtual-dtor -Wno-long-long -ansi -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -fno-exceptions -fno-check-new -fno-common")
      set(CMAKE_CXX_FLAGS_PROFILE        "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
      set(CMAKE_C_FLAGS_RELWITHDEBINFO   "-O2 -g")
      set(CMAKE_C_FLAGS_RELEASE          "-O2")
      set(CMAKE_C_FLAGS_DEBUG            "-g -O2 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
      set(CMAKE_C_FLAGS_DEBUGFULL        "-g3 -fno-inline -Wno-long-long -std=iso9899:1990 -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
      set(CMAKE_C_FLAGS_PROFILE          "-g3 -fno-inline -ftest-coverage -fprofile-arcs")

      
      
      endif (CMAKE_COMPILER_IS_GNUCXX)

endif (CMAKE_SYSTEM_NAME MATCHES Darwin) 

# Retry project header and source files
#file(GLOB CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
#file(GLOB HPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

# fill list of source files 
set(CPP_FILES 
${CMAKE_CURRENT_SOURCE_DIR}/src/Fit.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/DataManagement.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/ProcessChannel.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/Observable.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/Component.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/Group.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/Parameter.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/DataSet.cc
${CMAKE_CURRENT_SOURCE_DIR}/src/HistoCollection.cc
)

# fill list of header files 
set(HPP_FILES 
${CMAKE_CURRENT_SOURCE_DIR}/src/Fit.h
${CMAKE_CURRENT_SOURCE_DIR}/src/DataManagement.h
${CMAKE_CURRENT_SOURCE_DIR}/src/ProcessChannel.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Observable.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Component.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Group.h
${CMAKE_CURRENT_SOURCE_DIR}/src/Parameter.h
${CMAKE_CURRENT_SOURCE_DIR}/src/DataSet.h
${CMAKE_CURRENT_SOURCE_DIR}/src/HistoCollection.h
)


# set everything needed for the root dictonary and create the dictionary
set(LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/src/LinkDef.h )
set(DICTIONARY ${CMAKE_CURRENT_BINARY_DIR}/Dict.cxx) 
ROOT_GENERATE_DICTIONARY("${HPP_FILES}" "${LINKDEF}" "${DICTIONARY}" "${INCLUDE_DIRECTORIES}")

# add the LinkDef to the list of header files
SET(HPP_FILES ${HPP_FILES} ${LINKDEF})

# add the dictionary to the list of source files
SET(CPP_FILES ${CPP_FILES} ${DICTIONARY}) 

# Set the library version in the main CMakeLists.txt
#SET(Event_MAJOR_VERSION 0)
#SET(Event_MINOR_VERSION 0)
#SET(Event_PATCH_VERSION 0)
#SET(Event_VERSION "${Event_MAJOR_VERSION}.${Event_MINOR_VERSION}.${Event_PATCH_VERSION}")
#SET(Event_LIBRARY_PROPERTIES ${Event_LIBRARY_PROPERTIES}
#    VERSION "${Event_VERSION}"
#    SOVERSION "${Event_MAJOR_VERSION}"
#    SUFFIX ".so"
#)

############### build the library #####################
add_library(NEMO3Ana SHARED ${CPP_FILES} ${HPP_FILES})
target_link_libraries(NEMO3Ana ${ROOT_LIBRARIES})
#set_target_properties(KalmanTrackFit PROPERTIES ${Event_LIBRARY_PROPERTIES})

############### install the library ###################
install(TARGETS NEMO3Ana DESTINATION ${CMAKE_BINARY_DIR}/lib)

############### Executable to be linked to Collie  ###################

find_library (ISCOLLIE CollieIO /afs/in2p3.fr/throng/nemo/users/remoto/work/collie/lib/)

IF (ISCOLLIE)
	
	add_library(CollieCLHEP SHARED IMPORTED)
	set_property(TARGET CollieCLHEP PROPERTY IMPORTED_LOCATION /afs/in2p3.fr/throng/nemo/users/remoto/work/collie/CLHEP/lib/libCollieCLHEP.so)
	add_library(CollieIO SHARED IMPORTED)
	set_property(TARGET CollieIO PROPERTY IMPORTED_LOCATION /afs/in2p3.fr/throng/nemo/users/remoto/work/collie/lib/libCollieIO.so)
	add_library(CollieLimit SHARED IMPORTED)
	set_property(TARGET CollieLimit PROPERTY IMPORTED_LOCATION /afs/in2p3.fr/throng/nemo/users/remoto/work/collie/lib/libCollieLimit.so)
	
	include_directories(/afs/in2p3.fr/throng/nemo/users/remoto/work/collie/CLHEP/Units)
	include_directories(/afs/in2p3.fr/throng/nemo/users/remoto/work/collie/io/include)
	include_directories(/afs/in2p3.fr/throng/nemo/users/remoto/work/collie/limit/include)
	
	add_executable(collieIO_EXAMPLE ${CMAKE_CURRENT_SOURCE_DIR}/src/collieIO_EXAMPLE.cc)
	target_link_libraries(collieIO_EXAMPLE CollieCLHEP CollieIO CollieLimit ${ROOT_LIBRARIES})
	add_executable(collieIO_BDT ${CMAKE_CURRENT_SOURCE_DIR}/src/collieIO_BDT.cc)
	target_link_libraries(collieIO_BDT CollieCLHEP CollieIO CollieLimit ${ROOT_LIBRARIES})

	#install_files(${EXECUTABLE_OUTPUT_PATH} FILES collieIOexample)

ENDIF (ISCOLLIE)
