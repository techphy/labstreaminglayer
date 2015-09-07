//  Boost compiler configuration selection header file

//  (C) Copyright John Maddock 2001 - 2002. 
//  (C) Copyright Jens Maurer 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)

//  See http://www.lslboost.org for most recent version.

// locate which platform we are on and define BOOST_PLATFORM_CONFIG as needed.
// Note that we define the headers to include using "header_name" not
// <header_name> in order to prevent macro expansion within the header
// name (for example "linux" is a macro on linux systems).

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
// linux, also other platforms (Hurd etc) that use GLIBC, should these really have their own config headers though?
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/linux.hpp"

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
// BSD:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/bsd.hpp"

#elif defined(sun) || defined(__sun)
// solaris:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/solaris.hpp"

#elif defined(__sgi)
// SGI Irix:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/irix.hpp"

#elif defined(__hpux)
// hp unix:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/hpux.hpp"

#elif defined(__CYGWIN__)
// cygwin is not win32:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/cygwin.hpp"

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
// win32:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/win32.hpp"

#elif defined(__HAIKU__)
// Haiku
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/haiku.hpp"

#elif defined(__BEOS__)
// BeOS
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/beos.hpp"

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
// MacOS
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/macos.hpp"

#elif defined(__IBMCPP__) || defined(_AIX)
// IBM
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/aix.hpp"

#elif defined(__amigaos__)
// AmigaOS
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/amigaos.hpp"

#elif defined(__QNXNTO__)
// QNX:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/qnxnto.hpp"

#elif defined(__VXWORKS__)
// vxWorks:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/vxworks.hpp"

#elif defined(__SYMBIAN32__) 
// Symbian: 
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/symbian.hpp" 

#elif defined(_CRAYC)
// Cray:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/cray.hpp" 

#elif defined(__VMS) 
// VMS:
#  define BOOST_PLATFORM_CONFIG "lslboost/config/platform/vms.hpp" 
#else

#  if defined(unix) \
      || defined(__unix) \
      || defined(_XOPEN_SOURCE) \
      || defined(_POSIX_SOURCE)

   // generic unix platform:

#  ifndef BOOST_HAS_UNISTD_H
#     define BOOST_HAS_UNISTD_H
#  endif

#  include <lslboost/config/posix_features.hpp>

#  endif

#  if defined (BOOST_ASSERT_CONFIG)
      // this must come last - generate an error if we don't
      // recognise the platform:
#     error "Unknown platform - please configure and report the results to lslboost.org"
#  endif

#endif

#if 0
//
// This section allows dependency scanners to find all the files we *might* include:
//
#  include "lslboost/config/platform/linux.hpp"
#  include "lslboost/config/platform/bsd.hpp"
#  include "lslboost/config/platform/solaris.hpp"
#  include "lslboost/config/platform/irix.hpp"
#  include "lslboost/config/platform/hpux.hpp"
#  include "lslboost/config/platform/cygwin.hpp"
#  include "lslboost/config/platform/win32.hpp"
#  include "lslboost/config/platform/beos.hpp"
#  include "lslboost/config/platform/macos.hpp"
#  include "lslboost/config/platform/aix.hpp"
#  include "lslboost/config/platform/amigaos.hpp"
#  include "lslboost/config/platform/qnxnto.hpp"
#  include "lslboost/config/platform/vxworks.hpp"
#  include "lslboost/config/platform/symbian.hpp" 
#  include "lslboost/config/platform/cray.hpp" 
#  include "lslboost/config/platform/vms.hpp" 
#  include <lslboost/config/posix_features.hpp>



#endif

