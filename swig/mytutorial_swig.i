/* -*- c++ -*- */

#define MYTUTORIAL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "mytutorial_swig_doc.i"

%{
#include "mytutorial/square_ff.h"
#include "mytutorial/square2_ff.h"
%}


%include "mytutorial/square_ff.h"
GR_SWIG_BLOCK_MAGIC2(mytutorial, square_ff);
%include "mytutorial/square2_ff.h"
GR_SWIG_BLOCK_MAGIC2(mytutorial, square2_ff);
