/*=============================================================================
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_ADT_DETAIL_ADAPT_BASE_ATTR_FILLER_HPP
#define BOOST_FUSION_ADAPTED_ADT_DETAIL_ADAPT_BASE_ATTR_FILLER_HPP

#include <lslboost/config.hpp>
#include <lslboost/fusion/adapted/struct/detail/preprocessor/is_seq.hpp>

#include <lslboost/preprocessor/arithmetic/sub.hpp>
#include <lslboost/preprocessor/control/if.hpp>
#include <lslboost/preprocessor/logical/or.hpp>
#include <lslboost/preprocessor/empty.hpp>
#include <lslboost/preprocessor/tuple/size.hpp>
#include <lslboost/preprocessor/tuple/elem.hpp>
#include <lslboost/preprocessor/facilities/is_empty.hpp>
#include <lslboost/preprocessor/variadic/to_seq.hpp>
#include <lslboost/preprocessor/variadic/to_tuple.hpp>
#include <lslboost/preprocessor/variadic/elem.hpp>
#include <lslboost/preprocessor/seq/for_each.hpp>
#include <lslboost/preprocessor/seq/push_front.hpp>
#include <lslboost/preprocessor/seq/rest_n.hpp>

#include <lslboost/preprocessor/tuple/reverse.hpp>


#define BOOST_FUSION_ADAPT_ADT_WRAPPEDATTR_SIZE(ATTRIBUTE)                      \
  BOOST_PP_TUPLE_ELEM(2, 0, ATTRIBUTE)

#define BOOST_FUSION_ADAPT_ADT_WRAPPEDATTR(ATTRIBUTE)                           \
  BOOST_PP_TUPLE_ELEM(2, 1, ATTRIBUTE)

#if BOOST_PP_VARIADICS

#  define BOOST_FUSION_ADAPT_ADT_FILLER_0(...)                                  \
      BOOST_FUSION_ADAPT_ADT_FILLER(__VA_ARGS__)                                \
      BOOST_FUSION_ADAPT_ADT_FILLER_1

#  define BOOST_FUSION_ADAPT_ADT_FILLER_1(...)                                  \
      BOOST_FUSION_ADAPT_ADT_FILLER(__VA_ARGS__)                                \
      BOOST_FUSION_ADAPT_ADT_FILLER_0

#  define BOOST_FUSION_ADAPT_ADT_FILLER_0_END
#  define BOOST_FUSION_ADAPT_ADT_FILLER_1_END

#  define BOOST_FUSION_ADAPT_ADT_FILLER(...)                                    \
      BOOST_PP_IF(                                                              \
          BOOST_PP_OR(                                                          \
              BOOST_PP_IS_EMPTY(BOOST_PP_VARIADIC_ELEM(0, __VA_ARGS__)),        \
              BOOST_PP_IS_EMPTY(BOOST_PP_VARIADIC_ELEM(1, __VA_ARGS__))),       \
          BOOST_FUSION_ADAPT_ADT_WRAP_ATTR(                                     \
              BOOST_PP_VARIADIC_ELEM(2, __VA_ARGS__),                           \
              BOOST_FUSION_WORKAROUND_VARIADIC_EMPTINESS_LAST_ELEM(__VA_ARGS__) \
          ),                                                                    \
          BOOST_FUSION_ADAPT_ADT_WRAP_ATTR(__VA_ARGS__))

#  define BOOST_FUSION_ADAPT_ADT_WRAP_ATTR(...)                                 \
      ((BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), (__VA_ARGS__)))

#  define BOOST_FUSION_WORKAROUND_VARIADIC_EMPTINESS_LAST_ELEM(...)             \
  BOOST_PP_SEQ_HEAD(BOOST_PP_SEQ_REST_N(                                        \
            BOOST_PP_SUB(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1),               \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

#else // BOOST_PP_VARIADICS

#  define BOOST_FUSION_ADAPT_ADT_FILLER_0(A, B, C, D)                           \
      BOOST_FUSION_ADAPT_ADT_WRAP_ATTR(A,B,C,D)                                 \
      BOOST_FUSION_ADAPT_ADT_FILLER_1

#  define BOOST_FUSION_ADAPT_ADT_FILLER_1(A, B, C, D)                           \
      BOOST_FUSION_ADAPT_ADT_WRAP_ATTR(A,B,C,D)                                 \
      BOOST_FUSION_ADAPT_ADT_FILLER_0

#  define BOOST_FUSION_ADAPT_ADT_FILLER_0_END
#  define BOOST_FUSION_ADAPT_ADT_FILLER_1_END

#  define BOOST_FUSION_ADAPT_ADT_WRAP_ATTR(A, B, C, D)                          \
      BOOST_PP_IF(BOOST_PP_IS_EMPTY(A),                                         \
        ((2, (C,D))),                                                           \
        ((4, (A,B,C,D)))                                                        \
      )

#endif // BOOST_PP_VARIADICS

#endif
