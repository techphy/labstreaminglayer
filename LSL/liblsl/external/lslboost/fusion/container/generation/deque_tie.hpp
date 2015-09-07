/*=============================================================================
    Copyright (c) 2001-2013 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_DEQUE_TIE_01272013_1401)
#define FUSION_DEQUE_TIE_01272013_1401

#include <lslboost/fusion/support/config.hpp>
#include <lslboost/fusion/container/deque/deque.hpp>

#if !defined(BOOST_FUSION_HAS_VARIADIC_DEQUE)
# include <lslboost/fusion/container/generation/detail/pp_deque_tie.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 variadic interface
///////////////////////////////////////////////////////////////////////////////

#include <lslboost/fusion/support/detail/as_fusion_element.hpp>

namespace lslboost { namespace fusion
{
    struct void_;

    namespace result_of
    {
        template <typename ...T>
        struct deque_tie
        {
            typedef deque<T&...> type;
        };
    }

    template <typename ...T>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline deque<T&...>
    deque_tie(T&... arg)
    {
        return deque<T&...>(arg...);
    }
 }}

#endif
#endif

