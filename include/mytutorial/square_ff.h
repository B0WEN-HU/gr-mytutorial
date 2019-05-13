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


#ifndef INCLUDED_MYTUTORIAL_SQUARE_FF_H
#define INCLUDED_MYTUTORIAL_SQUARE_FF_H

#include <mytutorial/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace mytutorial {

    /*!
     * \brief <+description of block+>
     * \ingroup mytutorial
     *
     */
    class MYTUTORIAL_API square_ff : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<square_ff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of mytutorial::square_ff.
       *
       * To avoid accidental use of raw pointers, mytutorial::square_ff's
       * constructor is in a private implementation
       * class. mytutorial::square_ff::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace mytutorial
} // namespace gr

#endif /* INCLUDED_MYTUTORIAL_SQUARE_FF_H */

