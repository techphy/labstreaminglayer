/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_END_10022005_1619)
#define FUSION_END_10022005_1619

#include <lslboost/fusion/support/config.hpp>
#include <lslboost/mpl/begin_end.hpp>
#include <lslboost/fusion/sequence/intrinsic/end.hpp>
#include <lslboost/fusion/adapted/mpl/detail/end_impl.hpp>
#include <lslboost/fusion/iterator/mpl/fusion_iterator.hpp>

namespace lslboost { namespace mpl
{
    template <typename Tag>
    struct end_impl;

    template <>
    struct end_impl<fusion::fusion_sequence_tag>
    {
        template <typename Sequence>
        struct apply
        {
            typedef fusion_iterator<typename fusion::result_of::end<Sequence>::type> type;
        };
    };
}}

#endif
