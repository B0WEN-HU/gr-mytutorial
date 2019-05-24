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
#include "Vflicker_sim_dl_impl.h"

// Shared library header file
#include <stdlib.h>
#include <dlfcn.h>
//#include "Vflicker_sim_dll.h"

#include <iostream>

namespace gr {
  namespace mytutorial {

    Vflicker_sim_dl::sptr
    Vflicker_sim_dl::make()
    {
      return gnuradio::get_initial_sptr
        (new Vflicker_sim_dl_impl());
    }

    /*
     * The private constructor
     */
    Vflicker_sim_dl_impl::Vflicker_sim_dl_impl()
      : gr::sync_block("Vflicker_sim_dl",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(char))),
        pHandle(NULL)
    {
      

      // Load the library
      this->pHandle = dlopen("/home/bowen/Documents/GR_learn/gr-mytutorial/lib/libvl.so", RTLD_LAZY);
      if(NULL == this->pHandle) {
        std::cerr << "ERROR:Cannot load the library" << std::endl;
        //return EXIT_FAILURE
      }
      
      // Find the library symbol
      void (*pInit)();
      pInit = (void (*)()) dlsym(this->pHandle, "init");
      if(NULL == pInit) {
        std::cerr << "ERROR:Cannot find the function" << std::endl;
        dlclose(this->pHandle);
        this->pHandle = NULL;
        //return EXIT_FAILURE;
      }

      // Execute init()
      try {
        pInit();
      } catch(...) {
        // Handle the exception
        std::cerr << "ERROR:Exception raised by function";
        //return EXIT_FAILURE;
      }

      // Find the library symbol
      void (*pReset)();
      pReset = (void (*)()) dlsym(this->pHandle, "reset");
      if(NULL == pReset) {
        std::cerr << "ERROR:Cannot find the function" << std::endl;
        dlclose(this->pHandle);
        this->pHandle = NULL;
        //return EXIT_FAILURE;
      }

      // Execute reset()
      try {
        pReset();
      } catch(...) {
        // Handle the exception
        std::cerr << "ERROR:Exception raised by function";
        //return EXIT_FAILURE;
      }

    }

    /*
     * Our virtual destructor.
     */
    Vflicker_sim_dl_impl::~Vflicker_sim_dl_impl()
    {
      // Find the library symbol
      void (*pRelease)();
      pRelease = (void (*)()) dlsym(this->pHandle, "release");
      if(NULL == pRelease) {
        std::cerr << "ERROR:Cannot find the function" << std::endl;
        dlclose(this->pHandle);
        this->pHandle = NULL;
        //return EXIT_FAILURE;
      }

      // Execute release()
      try {
        pRelease();
      } catch(...) {
        // Handle the exception
        std::cerr << "ERROR:Exception raised by function";
        //return EXIT_FAILURE;
      }

    }

    int
    Vflicker_sim_dl_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      unsigned char *out = (unsigned char *) output_items[0];

      // Do Vflicker simulation

      unsigned char (*pTic)();
      pTic = (unsigned char (*)()) dlsym(this->pHandle, "tic");
      if(NULL == pTic) {
        std::cerr << "ERROR:Cannot find the function" << std::endl;
        dlclose(this->pHandle);
        this->pHandle = NULL;
        //return EXIT_FAILURE;
      }

      for(int i = 0; i < noutput_items; i++)
      {
        // Execute tic()
        try {
          out[i] = pTic();
          // For DEBUG
          /*
          std::cout << (int)out[i] << std::endl;
          */
        } catch (...) {
          // Handle the exception
          std::cerr << "ERROR:Exception raised by function";
          //return EXIT_FAILURE;
        }
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace mytutorial */
} /* namespace gr */

