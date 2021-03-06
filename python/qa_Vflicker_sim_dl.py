#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2019 Bowen Hu.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import mytutorial_swig as mytutorial

class qa_Vflicker_sim_dl (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        # set up fg
        item_number = 10

        expected_result = (31, 0, 31, 0, 31, 0, 31, 0, 31, 0)
        
        vlmodule = mytutorial.Vflicker_sim_dl()
        relay = blocks.head(gr.sizeof_char*1, item_number)
        dst = blocks.vector_sink_b()

        self.tb.connect(vlmodule, relay)
        self.tb.connect(relay, dst)

        self.tb.run ()
        # check data
        result_data = dst.data()
        self.assertTupleEqual(expected_result, result_data)
        self.assertEqual(len(expected_result),len(result_data))


if __name__ == '__main__':
    gr_unittest.run(qa_Vflicker_sim_dl, "qa_Vflicker_sim_dl.xml")
