#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/bowen/Documents/GR_learn/gr-mytutorial/python
export PATH=/home/bowen/Documents/GR_learn/gr-mytutorial/build/python:$PATH
export LD_LIBRARY_PATH=/home/bowen/Documents/GR_learn/gr-mytutorial/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/bowen/Documents/GR_learn/gr-mytutorial/build/swig:$PYTHONPATH
/usr/bin/python2 /home/bowen/Documents/GR_learn/gr-mytutorial/python/qa_Vflicker_sim.py 
