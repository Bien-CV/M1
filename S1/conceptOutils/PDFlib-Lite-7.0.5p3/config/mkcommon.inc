# Template to be included from every makefile that creates libs/progs
# $Id: mkcommon.inc.in,v 1.40.2.15 2009/12/03 11:35:15 rjs Exp $
# vim: syntax=make noexpandtab
#
#
# The Makefile that uses this template has to set
# top_builddir	= ...
# before including $(top_builddir)/config/mkcommon.inc
#

srcdir		= .
OO		= .
PATHSEP		= /

topbuilddir	= $(top_builddir)

# general stuff (configure)

VERSION		= 7.0.5
SHELL		= /bin/sh
INSTALL		= $(top_builddir)/config/install-sh -c
INSTALL_DATA	= ${INSTALL} -m 644
EXE		= 
OBJ		= o
CC		= gcc
CXX		= g++
STDCPP		= -lstdc++
RM		= rm -rf
MKDIR		= mkdir
MOVE		= mv
BINDINGS	= c cpp
PLOPBINDINGS	= c
TETBINDINGS	= c cpp
PCOSBINDINGS	= c cpp
LIBTARGETS	=  pdcore font flate png tiff jpeg pdflib
BINDTARGETS	=  pdflib
PROGTARGETS	=  pdflib
ATSDIR		= @ATSDIR@
PROGSDIR	= progs
STDDIRS		= libs bind
PDFFONT_TOOL	= @PDFFONT_TOOL@
INTERNDIR	= 

# build related stuff (configure)
LDFLAGS		= 
NO_O		= 
PDFOPTIMIZE     = -O2
NOOCFLAGS	= -g -D__NO_CTYPE -DPDC_PF_LINUX_X86_64 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -DPDF_PLATFORM=\""Linux-x86_64"\" -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1  $(PDFWALL) $(PDFPEDANTIC) $(MYCFLAGS) 
CFLAGS		= $(PDFOPTIMIZE) $(NOOCFLAGS)
CPPFLAGS	=  $(INCLUDES)
CXXFLAGS	= -g -O2
PDFWALL		= -Wall
PDFPEDANTIC	= 
PDFCPEDANTIC	= 
TIFFWRITE	= 
FLATE_ASM_OBJ   = 

# libtool specific
LA                 = .la
DLL                = $(LA)
LIB_PREFIX	   = lib
LO                 = .lo
WITH_SHARED        = yes
RPATH              = -rpath $(libdir) -version-info $(LTVERSIONINFO)

LIBTOOL            = $(top_builddir)/libtool --silent
LIBTOOL_CC         = $(LIBTOOL) --mode=compile
LIBTOOL_LD         = $(LIBTOOL) --mode=link
LIBTOOL_EXE        = $(LIBTOOL) --mode=execute -dlopen $(LIBNAME)

# Java
JAVA_COMPATIBILITY	= -source 1.4

# Perl
PERLLIBDIR	= /usr/local/lib/perl/5.18.2
PERLINCLUDE	= -I/usr/lib/perl/5.18/CORE
PERLLINK	= 
PERL		= perl
PERLBOOLDEF	= -Dbool=char -DHAS_BOOL

PYTHONLIBDIR	= 
PYINCLUDE	= nope

RUBYINCLUDE	= nope
RUBYLIBDIR	= 
RUBY       	= ruby

TCLINCLUDE	= -Inope
TCLPACKAGEDIR	= nope
TCLBIN		= nope

# PDFlib includes
PDFLIBINC	= -I$(top_builddir)/libs/pdflib
TIFFLIBINC	= -I$(top_builddir)/libs/tiff
JPEGLIBINC	= -I$(top_builddir)/libs/jpeg
ZLIBINC		= -I$(top_builddir)/libs/flate
FLATELIBINC	= -I$(top_builddir)/libs/flate
FONTLIBINC	= -I$(top_builddir)/libs/font
PNGLIBINC	= -I$(top_builddir)/libs/png
PDCORELIBINC	= -I$(top_builddir)/libs/pdcore
PDILIBINC	= 
PDPAGELIBINC	= 
PDULIBINC	= @PDULIBINC@
TETLIBINC	= 
PCOSLIBINC	= 
PLOPLIBINC	= 
CLLIBINC        = 
EXPATLIBINC     = 
OPENSSLLIBINC   = 
JAVAINCLUDE	= 
UTILLIBINC      = 
ATSLIBINC       = 
ICULIBINC       = 
ICUTLELIBINC    = 

# libs stuff
EXTERNALLIBS    =  -lm
PDFLIBNAME	= pdf
PDFLIB_LTVERSION= 6:5:0
PLOP_LTVERSION  = 1:0:0
TET_LTVERSION   = 2:0:1
PCOS_LTVERSION  = 1:0:0
LTVERSIONINFO   = $(PDFLIB_LTVERSION)
PDFLIBCONVENIENT= $(top_builddir)/libs/pdflib/libpdf_$(LA) $(top_builddir)/libs/pdflib/$(OO)/pdflib$(LO) $(top_builddir)/libs/pdcore/libpdcore$(LA) $(top_builddir)/libs/png/libpng$(LA) $(top_builddir)/libs/flate/libz$(LA) $(top_builddir)/libs/tiff/libtiff$(LA)  $(top_builddir)/libs/jpeg/libjpeg$(LA)  $(top_builddir)/libs/font/libfont$(LA)  
CONVENIENT	= $(PDFLIBCONVENIENT)

# libs
PDFLIBLINK	= $(top_builddir)/libs/pdflib/libs_libpdf$(LA)
PDFLIB_LINK	= $(top_builddir)/libs/pdflib/libpdf_$(LA)
TIFFLIBLINK	= $(top_builddir)/libs/tiff/libtiff$(LA)
JPEGLIBLINK	= $(top_builddir)/libs/jpeg/libjpeg$(LA)
FLATELIBLINK	= $(top_builddir)/libs/flate/libz$(LA)
FONTLIBLINK	= $(top_builddir)/libs/font/libfont$(LA)
PNGLIBLINK	= $(top_builddir)/libs/png/libpng$(LA)
PDCORELIBLINK	= $(top_builddir)/libs/pdcore/libpdcore$(LA)
PDILIBLINK	= 
PDPAGELIBLINK	= 
EXPATLIBLINK    = 
OPENSSLLIBLINK  = 
ICULIBLINK      = 
ICUTLELIBLINK   = 

# TET libs
TETLIBLINK	= 
TETLIB_LINK	= 

# PLOP libs
PLOPLIBLINK	= 
PLOPLIB_LINK	= 

# PCOS libs
PCOSLIBLINK	= 
PCOSLIB_LINK	= 

# commandline lib
CLLIBLINK       = 

# utility lib
UTILLIBLINK     = 

# ATS lib
ATSLIBLINK     = 

PDULIBLINK	= @PDULIBLINK@

# libraries to link a shared library for the binding; this is special
# for USS but on normal platforms this defaults to the standard shared libs
BIND_PDFLIBLINK = $(PDFLIBLINK)
BIND_PLOPLIBLINK = $(PLOPLIBLINK)
BIND_PCOSLIBLINK = $(PCOSLIBLINK)
BIND_TETLIBLINK = $(TETLIBLINK)

# installation directories (configure)
prefix          = /usr/local
exec_prefix     = ${prefix}
libdir          = ${exec_prefix}/lib
includedir      = ${prefix}/include
bindir          = ${exec_prefix}/bin
