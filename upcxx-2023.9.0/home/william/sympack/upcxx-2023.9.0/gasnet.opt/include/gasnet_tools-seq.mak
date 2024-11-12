# Description: Makefile fragment for GASNet_tools, GASNET_SEQ mode
# WARNING: This file is automatically generated - do NOT edit directly
# other/gasnet_tools-fragment.mak.  Generated from gasnet_tools-fragment.mak.in by configure.
# Copyright 2011, Dan Bonachea <bonachea@cs.berkeley.edu>
# Terms of use are as specified in license.txt

# ----------------------------------------------------------------------
# Usage instructions:
#
# Clients should include this file in their Makefile, using: (no leading '#')
#     include $(GASNET_PREFIX)/include/gasnet_tools-seq.mak
# or alternatively, just:
#     include gasnet_tools-seq.mak  
# and use a -I$(GASNET_PREFIX)/include
# command-line option when invoking make
#
# Then in the Makefile, use a compile line something like this:
#  $(GASNETTOOLS_CC) $(GASNETTOOLS_CPPFLAGS) $(GASNETTOOLS_CFLAGS) -c myfile.c
#
# and a link line something like this:
#  $(GASNETTOOLS_LD) $(GASNETTOOLS_LDFLAGS) -o myfile myfile.o $(GASNETTOOLS_LIBS)
# ----------------------------------------------------------------------

GASNET_PREFIX = /home/william/sympack/upcxx-2023.9.0/home/william/sympack/upcxx-2023.9.0/gasnet.opt

GASNETTOOLS_INCLUDES = -I$(GASNET_PREFIX)/include

GASNETTOOLS_LIBDIR = $(GASNET_PREFIX)/lib

GASNETTOOLS_DEBUGFLAGS = -DNDEBUG

GASNETTOOLS_THREADFLAGS_PAR = -DGASNETT_THREAD_SAFE -D_REENTRANT
GASNETTOOLS_THREADFLAGS_SEQ = -DGASNETT_THREAD_SINGLE
GASNETTOOLS_THREADFLAGS = $(GASNETTOOLS_THREADFLAGS_SEQ)

GASNETTOOLS_THREADLIBS_PAR = -lpthread 
GASNETTOOLS_THREADLIBS_SEQ = 
GASNETTOOLS_THREADLIBS = $(GASNETTOOLS_THREADLIBS_SEQ)

GASNETTOOLS_TOOLLIB_NAME = gasnet_tools-seq

GASNETTOOLS_CC = /usr/bin/mpicc
GASNETTOOLS_CPPFLAGS = $(GASNETTOOLS_DEBUGFLAGS) $(GASNETTOOLS_THREADFLAGS) -D_GNU_SOURCE=1  $(GASNETTOOLS_INCLUDES) $(MANUAL_DEFINES)
GASNETTOOLS_CFLAGS = -O3 --param max-inline-insns-single=35000 --param inline-unit-growth=10000 --param large-function-growth=200000  -Wno-array-bounds -Wno-stringop-overflow -Wno-dangling-pointer -Wno-use-after-free -Wno-unused -Wunused-result -Wno-unused-parameter -Wno-address $(KEEPTMP_CFLAGS) $(MANUAL_CFLAGS)
GASNETTOOLS_LD = /usr/bin/mpicc
GASNETTOOLS_LDFLAGS = -O3 --param max-inline-insns-single=35000 --param inline-unit-growth=10000 --param large-function-growth=200000  -Wno-array-bounds -Wno-stringop-overflow -Wno-dangling-pointer -Wno-use-after-free -Wno-unused -Wunused-result -Wno-unused-parameter -Wno-address -Wl,--build-id $(MANUAL_LDFLAGS)
GASNETTOOLS_LIBS = -L$(GASNETTOOLS_LIBDIR) -l$(GASNETTOOLS_TOOLLIB_NAME) $(GASNETTOOLS_THREADLIBS)  -lm $(MANUAL_LIBS)
GASNETTOOLS_CXX = /usr/bin/mpicxx
GASNETTOOLS_CXXFLAGS = -O2  -Wno-array-bounds -Wno-stringop-overflow -Wno-dangling-pointer -Wno-use-after-free -Wno-unused -Wunused-result -Wno-unused-parameter -Wno-address $(MANUAL_CXXFLAGS)

