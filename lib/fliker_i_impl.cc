/* -*- c++ -*- */
/* 
 * Copyright 2019 <+YOU OR YOUR COMPANY+>.
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
#include "fliker_i_impl.h"
#include <iostream>
#include <cstdio>
#include "Vfliker.h"
#include "verilated.h"

namespace gr {
  namespace howto {

    fliker_i::sptr
    fliker_i::make()
    {
      return gnuradio::get_initial_sptr
        (new fliker_i_impl());
    }

    /*
     * The private constructor
     */
    fliker_i_impl::fliker_i_impl()
      : gr::sync_block("fliker_i",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(int)))
    {}

    /*
     * Our virtual destructor.
     */
    fliker_i_impl::~fliker_i_impl()
    {
    }

    int
    fliker_i_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      <+OTYPE+> *out = (<+OTYPE+> *) output_items[0];

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace howto */
} /* namespace gr */

