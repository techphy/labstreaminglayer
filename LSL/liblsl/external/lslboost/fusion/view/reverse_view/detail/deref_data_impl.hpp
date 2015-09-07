/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_DEREF_DATA_IMPL_HPP
#define BOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_DEREF_DATA_IMPL_HPP

#include <lslboost/fusion/support/config.hpp>
#include <lslboost/fusion/iterator/deref_data.hpp>

namespace lslboost { namespace fusion { namespace extension
{
    template <typename>
    struct deref_data_impl;

    template <>
    struct deref_data_impl<reverse_view_iterator_tag>
    {
        template <typename It>
        struct apply
        {
            typedef typename
                result_of::deref_data<typename It::first_type>::type
            type;

            BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
            static type
            call(It const& it)
            {
                return fusion::deref_data(it.first);
            }
        };
    };
}}}

#endif
