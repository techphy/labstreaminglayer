/*
(c) 2014 Glen Joseph Fernandes
glenjofe at gmail dot com

Distributed under the Boost Software
License, Version 1.0.
http://lslboost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_MIN_SIZE_HPP
#define BOOST_ALIGN_DETAIL_MIN_SIZE_HPP

#include <lslboost/align/detail/integral_constant.hpp>
#include <cstddef>

namespace lslboost {
namespace alignment {
namespace detail {

template<std::size_t A, std::size_t B>
struct min_size
    : integral_constant<std::size_t, (A < B) ? A : B> {
};

} /* :detail */
} /* :alignment */
} /* :lslboost */

#endif
