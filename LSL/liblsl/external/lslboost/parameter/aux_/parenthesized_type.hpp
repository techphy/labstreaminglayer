// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
#ifndef BOOST_PARAMETER_AUX_PARENTHESIZED_TYPE_DWA2006414_HPP
# define BOOST_PARAMETER_AUX_PARENTHESIZED_TYPE_DWA2006414_HPP

# include <lslboost/config.hpp>
# include <lslboost/detail/workaround.hpp>

namespace lslboost { namespace parameter { namespace aux { 

// A macro that takes a parenthesized C++ type name (T) and transforms
// it into an un-parenthesized type expression equivalent to T.
#  define BOOST_PARAMETER_PARENTHESIZED_TYPE(x)                    \
    lslboost::parameter::aux::unaryfunptr_arg_type< void(*)x >::type

// A metafunction that transforms void(*)(T) -> T
template <class UnaryFunctionPointer>
struct unaryfunptr_arg_type;

template <class Arg>
struct unaryfunptr_arg_type<void(*)(Arg)>
{
    typedef Arg type;
};

template <>
struct unaryfunptr_arg_type<void(*)(void)>
{
    typedef void type;
};
    
}}} // namespace lslboost::parameter::aux

#endif // BOOST_PARAMETER_AUX_PARENTHESIZED_TYPE_DWA2006414_HPP
