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


#ifndef INCLUDED_MYTUTORIAL_VFLICKER_SIM_DL_H
#define INCLUDED_MYTUTORIAL_VFLICKER_SIM_DL_H

#include <mytutorial/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace mytutorial {

    /*!
     * \brief <+description of block+>
     * \ingroup mytutorial
     *
     */
    class MYTUTORIAL_API Vflicker_sim_dl : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<Vflicker_sim_dl> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of mytutorial::Vflicker_sim_dl.
       *
       * To avoid accidental use of raw pointers, mytutorial::Vflicker_sim_dl's
       * constructor is in a private implementation
       * class. mytutorial::Vflicker_sim_dl::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace mytutorial
} // namespace gr

#endif /* INCLUDED_MYTUTORIAL_VFLICKER_SIM_DL_H */

