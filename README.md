NEMO3Ana
========

NEMO-3 Experiment data analysis tools. Implement event reconstruction, selection and histogramming. Implement a Boosted Decision Tree (BDT) strategy to improve signal/background separation and maximise experimental sensitivity to neutrino-less double beta decay searches. 

Reference code used for the following results:

"Measurement of the 2νββ Decay Half-Life and Search for the 0νββ Decay of 116Cd with the NEMO-3 Detector"

Phys. Rev. D 95, 012007 (2017)
ArXiv:1610.03226

Install
-------
```bash
mkdir build && cd build
cmake ../
make
```
The package depends only on [ROOT](http://root.cern.ch/).

Usage
-----
The `macro` directory contain some ROOT macros for basic usage.

```bash
root macro/<macroname>.C+
```
