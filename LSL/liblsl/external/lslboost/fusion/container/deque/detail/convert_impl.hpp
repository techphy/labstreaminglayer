/*=============================================================================
    Copyright (c) 2005-2012 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_CONVERT_IMPL_20061213_2207)
#define FUSION_CONVERT_IMPL_20061213_2207

#include <lslboost/fusion/support/config.hpp>
#include <lslboost/fusion/container/deque/convert.hpp>
#include <lslboost/fusion/container/deque/deque.hpp>
#include <lslboost/fusion/sequence/intrinsic/begin.hpp>
#include <lslboost/fusion/sequence/intrinsic/size.hpp>

namespace lslboost { namespace fusion
{
    struct deque_tag;

    namespace result_of
    {
        template <typename Sequence>
        struct as_deque;
    }

    namespace extension
    {
        template <typename T>
        struct convert_impl;

        template <>
        struct convert_impl<deque_tag>
        {
            template <typename Sequence>
            struct apply
            {
                typedef result_of::as_deque<Sequence> gen;
                typedef typename gen::type type;

                BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
                static type call(Sequence& seq)
                {
                    return gen::call(seq);
                }
            };
        };
    }
}}

#endif
