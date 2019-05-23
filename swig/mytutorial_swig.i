/* -*- c++ -*- */

#define MYTUTORIAL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "mytutorial_swig_doc.i"

%{
#include "mytutorial/square_ff.h"
#include "mytutorial/square2_ff.h"
#include "mytutorial/my_qpsk_demod_cb.h"
#include "mytutorial/Vflicker_sim.h"
%}


%include "mytutorial/square_ff.h"
GR_SWIG_BLOCK_MAGIC2(mytutorial, square_ff);
%include "mytutorial/square2_ff.h"
GR_SWIG_BLOCK_MAGIC2(mytutorial, square2_ff);
%include "mytutorial/my_qpsk_demod_cb.h"
GR_SWIG_BLOCK_MAGIC2(mytutorial, my_qpsk_demod_cb);

%include "mytutorial/Vflicker_sim.h"
GR_SWIG_BLOCK_MAGIC2(mytutorial, Vflicker_sim);
