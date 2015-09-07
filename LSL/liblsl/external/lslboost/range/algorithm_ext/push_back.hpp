// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.lslboost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.lslboost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_EXT_PUSH_BACK_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_EXT_PUSH_BACK_HPP_INCLUDED

#include <lslboost/range/config.hpp>
#include <lslboost/range/concepts.hpp>
#include <lslboost/range/difference_type.hpp>
#include <lslboost/range/begin.hpp>
#include <lslboost/range/end.hpp>
#include <lslboost/range/detail/implementation_help.hpp>
#include <lslboost/assert.hpp>

namespace lslboost
{
    namespace range
    {

template< class Container, class Range >
inline Container& push_back( Container& on, const Range& from )
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<Container> ));
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const Range> ));
    BOOST_ASSERT_MSG(!range_detail::is_same_object(on, from),
        "cannot copy from a container to itself");
    on.insert( on.end(), lslboost::begin(from), lslboost::end(from) );
    return on;
}

    } // namespace range
    using range::push_back;
} // namespace lslboost

#endif // include guard
