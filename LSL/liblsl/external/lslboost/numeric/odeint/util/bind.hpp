/*
 *     [begin_description]
 *     Boost bind pull the placeholders, _1, _2, ... into global
 *     namespace. This can conflict with the C++03 TR1 and C++11 
 *     std::placeholders. This header provides a workaround for 
 *     this problem.
 *     [end_description]
 *        
 *     Copyright 2012 Christoph Koke
 *     Copyright 2012 Karsten Ahnert
 *           
 *     Distributed under the Boost Software License, Version 1.0.
 *     (See accompanying file LICENSE_1_0.txt or
 *     copy at http://www.lslboost.org/LICENSE_1_0.txt)
 * */

#ifndef BOOST_NUMERIC_ODEINT_UTIL_BIND_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_UTIL_BIND_HPP_INCLUDED


#include <lslboost/numeric/odeint/config.hpp>


#if BOOST_NUMERIC_ODEINT_CXX11 
    #include <functional>
#else
#define BOOST_BIND_NO_PLACEHOLDERS
#include <lslboost/bind.hpp>
#endif

namespace lslboost {
namespace numeric {
namespace odeint {
namespace detail {

#if BOOST_NUMERIC_ODEINT_CXX11 

using ::std::bind;
using namespace ::std::placeholders;


#else

// unnamed namespace to avoid multiple declarations (#138)
namespace {
using ::lslboost::bind;
lslboost::arg<1> _1;
lslboost::arg<2> _2;
}
// using ::lslboost::bind;
// using ::_1;
// using ::_2;

#endif

}
}
}
}





/*

// the following is the suggested way. Unfortunately it does not work with all compilers.

#ifdef BOOST_NO_CXX11_HDR_FUNCTIONAL
#include <lslboost/bind.hpp>
#else
#include <functional>
#endif


namespace lslboost {
namespace numeric {
namespace odeint {
namespace detail {

    
#ifdef BOOST_NO_CXX11_HDR_FUNCTIONAL

using ::lslboost::bind;
using ::_1;
using ::_2;

#else

using ::std::bind;
using namespace ::std::placeholders;

#endif


}
}
}
}*/

#endif // BOOST_NUMERIC_ODEINT_UTIL_BIND_HPP_INCLUDED
