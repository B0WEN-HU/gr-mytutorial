#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/bowen/Documents/GR_learn/gr-mytutorial/lib
export PATH=/home/bowen/Documents/GR_learn/gr-mytutorial/build/lib:$PATH
export LD_LIBRARY_PATH=/home/bowen/Documents/GR_learn/gr-mytutorial/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-mytutorial 
