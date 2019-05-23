# Copyright 2011,2012,2016 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
list(APPEND mytutorial_sources
    square_ff_impl.cc
    square2_ff_impl.cc
    my_qpsk_demod_cb_impl.cc
    Vflicker_sim_impl.cc )

set(mytutorial_sources "${mytutorial_sources}" PARENT_SCOPE)
if(NOT mytutorial_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT mytutorial_sources)

add_library(gnuradio-mytutorial SHARED ${mytutorial_sources})
target_link_libraries(gnuradio-mytutorial ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-mytutorial PROPERTIES DEFINE_SYMBOL "gnuradio_mytutorial_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-mytutorial PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-mytutorial RUNTIME_COMPONENT "mytutorial_runtime" DEVEL_COMPONENT "mytutorial_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_mytutorial_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_mytutorial.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_mytutorial.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_my_qpsk_demod_cb.cc
)

add_executable(test-mytutorial ${test_mytutorial_sources})

target_link_libraries(
  test-mytutorial
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  gnuradio-mytutorial
)

GR_ADD_TEST(test_mytutorial test-mytutorial)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

