// Copyright (C) 2014 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
//
// 2014/10 Vicente J. Botet Escriba
//   Creation.

#ifndef BOOST_CSBL_MEMORY_SHARED_PTR_HPP
#define BOOST_CSBL_MEMORY_SHARED_PTR_HPP

#include <lslboost/thread/csbl/memory/config.hpp>

#if defined BOOST_NO_CXX11_SMART_PTR

#include <lslboost/smart_ptr/shared_ptr.hpp>
#include <lslboost/smart_ptr/make_shared.hpp>

namespace lslboost
{
  namespace csbl
  {
    using ::lslboost::shared_ptr;
    using ::lslboost::make_shared;
  }
}

#else

#include <lslboost/shared_ptr.hpp>

namespace lslboost
{
  namespace csbl
  {
    using std::shared_ptr;
    using std::make_shared;
  }
}

#endif
#endif // header
