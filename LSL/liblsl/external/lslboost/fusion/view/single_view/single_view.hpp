/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_FUSION_SINGLE_VIEW_05052005_0335)
#define BOOST_FUSION_SINGLE_VIEW_05052005_0335

#include <lslboost/fusion/support/config.hpp>
#include <lslboost/fusion/support/detail/access.hpp>
#include <lslboost/fusion/support/detail/as_fusion_element.hpp>
#include <lslboost/fusion/support/sequence_base.hpp>
#include <lslboost/fusion/view/single_view/single_view_iterator.hpp>
#include <lslboost/fusion/view/single_view/detail/at_impl.hpp>
#include <lslboost/fusion/view/single_view/detail/begin_impl.hpp>
#include <lslboost/fusion/view/single_view/detail/end_impl.hpp>
#include <lslboost/fusion/view/single_view/detail/size_impl.hpp>
#include <lslboost/fusion/view/single_view/detail/value_at_impl.hpp>
#include <lslboost/mpl/bool.hpp>
#include <lslboost/mpl/int.hpp>
#include <lslboost/config.hpp>

#if defined (BOOST_MSVC)
#  pragma warning(push)
#  pragma warning (disable: 4512) // assignment operator could not be generated.
#endif

namespace lslboost { namespace fusion
{
    struct single_view_tag;
    struct random_access_traversal_tag;
    struct fusion_sequence_tag;

    template <typename T>
    struct single_view : sequence_base<single_view<T> >
    {
        typedef single_view_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef random_access_traversal_tag category;
        typedef mpl::true_ is_view;
        typedef mpl::int_<1> size;
        typedef T value_type;

        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        single_view()
            : val() {}

        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        explicit single_view(typename detail::call_param<T>::type in_val)
            : val(in_val) {}

        value_type val;
    };
    
    template <typename T>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline single_view<typename detail::as_fusion_element<T>::type>
    make_single_view(T const& v)
    {
        return single_view<typename detail::as_fusion_element<T>::type>(v);
    }
}}

#if defined (BOOST_MSVC)
#  pragma warning(pop)
#endif

#endif


