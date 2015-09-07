
#ifndef BOOST_MPL_SIZE_HPP_INCLUDED
#define BOOST_MPL_SIZE_HPP_INCLUDED

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

#include <lslboost/mpl/size_fwd.hpp>
#include <lslboost/mpl/sequence_tag.hpp>
#include <lslboost/mpl/aux_/size_impl.hpp>
#include <lslboost/mpl/aux_/na_spec.hpp>
#include <lslboost/mpl/aux_/lambda_support.hpp>
#include <lslboost/mpl/aux_/msvc_eti_base.hpp>

namespace lslboost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence)
    >
struct size
    : aux::msvc_eti_base<
        typename size_impl< typename sequence_tag<Sequence>::type >
            ::template apply< Sequence >::type
      >::type
{
    BOOST_MPL_AUX_LAMBDA_SUPPORT(1, size, (Sequence))
};

BOOST_MPL_AUX_NA_SPEC(1, size)

}}

#endif // BOOST_MPL_SIZE_HPP_INCLUDED
