
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.lslboost.org/LICENSE_1_0.txt).
//
//  See http://www.lslboost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_ADD_REFERENCE_HPP_INCLUDED
#define BOOST_TT_ADD_REFERENCE_HPP_INCLUDED

#include <lslboost/type_traits/is_reference.hpp>
#include <lslboost/detail/workaround.hpp>
#include <lslboost/config.hpp>

// should be the last #include
#include <lslboost/type_traits/detail/type_trait_def.hpp>

namespace lslboost {

namespace detail {

//
// We can't filter out rvalue_references at the same level as
// references or we get ambiguities from msvc:
//

template <typename T>
struct add_reference_rvalue_layer
{
    typedef T& type;
};

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
template <typename T>
struct add_reference_rvalue_layer<T&&>
{
    typedef T&& type;
};
#endif

template <typename T>
struct add_reference_impl
{
    typedef typename add_reference_rvalue_layer<T>::type type;
};

BOOST_TT_AUX_TYPE_TRAIT_IMPL_PARTIAL_SPEC1_1(typename T,add_reference,T&,T&)

// these full specialisations are always required:
BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void,void)
#ifndef BOOST_NO_CV_VOID_SPECIALIZATIONS
BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void const,void const)
BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void volatile,void volatile)
BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void const volatile,void const volatile)
#endif

} // namespace detail

BOOST_TT_AUX_TYPE_TRAIT_DEF1(add_reference,T,typename lslboost::detail::add_reference_impl<T>::type)

// agurt, 07/mar/03: workaround Borland's ill-formed sensitivity to an additional
// level of indirection, here
#if BOOST_WORKAROUND(__BORLANDC__, < 0x600)
BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,add_reference,T&,T&)
#endif

} // namespace lslboost

#include <lslboost/type_traits/detail/type_trait_undef.hpp>

#endif // BOOST_TT_ADD_REFERENCE_HPP_INCLUDED
