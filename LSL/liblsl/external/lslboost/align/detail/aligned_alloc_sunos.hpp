/*
(c) 2014 Glen Joseph Fernandes
glenjofe at gmail dot com

Distributed under the Boost Software
License, Version 1.0.
http://lslboost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_SUNOS_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_SUNOS_HPP

#include <lslboost/assert.hpp>
#include <lslboost/config.hpp>
#include <lslboost/align/detail/is_alignment.hpp>
#include <cstddef>
#include <stdlib.h>

namespace lslboost {
namespace alignment {

inline void* aligned_alloc(std::size_t alignment, std::size_t size)
    BOOST_NOEXCEPT
{
    BOOST_ASSERT(detail::is_alignment(alignment));
    return ::memalign(alignment, size);
}

inline void aligned_free(void* ptr) BOOST_NOEXCEPT
{
    ::free(ptr);
}

} /* :alignment */
} /* :lslboost */

#endif
