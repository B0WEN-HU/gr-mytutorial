/* -*- c++ -*- */
/* 
 * Copyright 2019 Bowen Hu.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "Vflicker_impl.h"

// Verilator related header file
# include <cstdlib>
# include "Vflicker.h"
# include "verilated.h"

namespace gr {
  namespace mytutorial {

    Vflicker::sptr
    Vflicker::make()
    {
      return gnuradio::get_initial_sptr
        (new Vflicker_impl());
    }

    /*
     * The private constructor
     */
    Vflicker_impl::Vflicker_impl()
      : gr::sync_block("Vflicker",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(char))),
        cycles(0), tb(NULL)
    {
      // Initialize Verilators variables
      int argc = 0;
      char** argv = NULL;
      Verilated::commandArgs(argc, argv);

      // Create an instance of out module under simulation
      this->tb = new Vflicker;

      this->cycles = 0;

      // Reset the module
      this->tb->clk = 0;
      this->tb->rst_n = 0;
      this->tb->eval();
      this->tb->clk = 1;
      this->tb->eval();
      this->tb->rst_n = 1;
      this->tb->clk = 0;
      this->tb->eval();

      ++(this->cycles);
    }

    /*
     * Our virtual destructor.
     */
    Vflicker_impl::~Vflicker_impl()
    {
      this->tb->final();
      delete (this->tb);
    }

    int
    Vflicker_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      unsigned char *out = (unsigned char *) output_items[0];

      // Do Vflicker simulation
      for(int i = 0; i < noutput_items; i++)
      {
        this->tb->clk = 1;
        this->tb->eval();
        ++(this->cycles);
        out[i] = (unsigned char)tb->dout;
        this->tb->clk = 0;
        this->tb->eval();
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace mytutorial */
} /* namespace gr */

