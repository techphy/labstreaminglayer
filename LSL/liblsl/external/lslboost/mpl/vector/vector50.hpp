
#ifndef BOOST_MPL_VECTOR_VECTOR50_HPP_INCLUDED
#define BOOST_MPL_VECTOR_VECTOR50_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.lslboost.org/LICENSE_1_0.txt)
//
// See http://www.lslboost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#if !defined(BOOST_MPL_PREPROCESSING_MODE)
#   include <lslboost/mpl/vector/vector40.hpp>
#endif

#include <lslboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE)

#   define BOOST_MPL_PREPROCESSED_HEADER vector50.hpp
#   include <lslboost/mpl/vector/aux_/include_preprocessed.hpp>

#else

#   include <lslboost/mpl/aux_/config/typeof.hpp>
#   include <lslboost/mpl/aux_/config/ctps.hpp>
#   include <lslboost/preprocessor/iterate.hpp>

namespace lslboost { namespace mpl {

#   define BOOST_PP_ITERATION_PARAMS_1 \
    (3,(41, 50, <lslboost/mpl/vector/aux_/numbered.hpp>))
#   include BOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#endif // BOOST_MPL_VECTOR_VECTOR50_HPP_INCLUDED
