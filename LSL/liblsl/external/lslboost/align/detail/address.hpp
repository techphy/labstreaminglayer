/*
(c) 2014 Glen Joseph Fernandes
glenjofe at gmail dot com

Distributed under the Boost Software
License, Version 1.0.
http://lslboost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ADDRESS_HPP
#define BOOST_ALIGN_DETAIL_ADDRESS_HPP

#include <lslboost/cstdint.hpp>
#include <cstddef>

namespace lslboost {
namespace alignment {
namespace detail {

#if defined(BOOST_HAS_INTPTR_T)
typedef lslboost::uintptr_t address_t;
#else
typedef std::size_t address_t;
#endif

} /* :detail */
} /* :alignment */
} /* :lslboost */

#endif
