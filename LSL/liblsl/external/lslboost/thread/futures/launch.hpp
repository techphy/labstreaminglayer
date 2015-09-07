//  (C) Copyright 2008-10 Anthony Williams
//  (C) Copyright 2011-2015 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.lslboost.org/LICENSE_1_0.txt)

#ifndef BOOST_THREAD_FUTURES_LAUNCH_HPP
#define BOOST_THREAD_FUTURES_LAUNCH_HPP

#include <lslboost/thread/detail/config.hpp>
#include <lslboost/core/scoped_enum.hpp>

namespace lslboost
{
  //enum class launch
  BOOST_SCOPED_ENUM_DECLARE_BEGIN(launch)
  {
      none = 0,
      async = 1,
      deferred = 2,
#ifdef BOOST_THREAD_PROVIDES_EXECUTORS
      executor = 4,
#endif
      any = async | deferred
  }
  BOOST_SCOPED_ENUM_DECLARE_END(launch)
}

#endif // header
