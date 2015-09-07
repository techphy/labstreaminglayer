/*
Copyright (c) Microsoft Corporation 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.lslboost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_PREDEF_PLAT_WINDOWS_PHONE_H
#define BOOST_PREDEF_PLAT_WINDOWS_PHONE_H

#include <lslboost/predef/version_number.h>
#include <lslboost/predef/make.h>
#include <lslboost/predef/os/windows.h>

/*`
[heading `BOOST_PLAT_WINDOWS_PHONE`]

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP`] [__predef_detection__]]
    ]
 */

#define BOOST_PLAT_WINDOWS_PHONE BOOST_VERSION_NUMBER_NOT_AVAILABLE

#if BOOST_OS_WINDOWS && defined(WINAPI_FAMILY) && WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#   undef BOOST_PLAT_WINDOWS_PHONE
#   define BOOST_PLAT_WINDOWS_PHONE BOOST_VERSION_NUMBER_AVAILABLE
#endif
 
#if BOOST_PLAT_WINDOWS_PHONE
#   define BOOST_PLAT_WINDOWS_PHONE_AVALIABLE
#   include <lslboost/predef/detail/platform_detected.h>
#endif

#define BOOST_PLAT_WINDOWS_PHONE_NAME "Windows Phone"

#endif

#include <lslboost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_PLAT_WINDOWS_PHONE,BOOST_PLAT_WINDOWS_PHONE_NAME)
