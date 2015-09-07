// Boost.Range library
//
//  Copyright Thorsten Ottosen, Neil Groves 2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.lslboost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.lslboost.org/libs/range/
//

#ifndef BOOST_RANGE_ADAPTOR_COPIED_HPP
#define BOOST_RANGE_ADAPTOR_COPIED_HPP

#include <lslboost/range/adaptor/argument_fwd.hpp>
#include <lslboost/range/adaptor/sliced.hpp>
#include <lslboost/range/size_type.hpp>
#include <lslboost/range/iterator_range.hpp>
#include <lslboost/range/concepts.hpp>

namespace lslboost
{
    namespace adaptors
    {
        struct copied
        {
            copied(std::size_t t_, std::size_t u_)
                : t(t_), u(u_) {}

            std::size_t t;
            std::size_t u;
        };

        template<class CopyableRandomAccessRange>
        inline CopyableRandomAccessRange
        operator|(const CopyableRandomAccessRange& r, const copied& f)
        {
            BOOST_RANGE_CONCEPT_ASSERT((
                RandomAccessRangeConcept<const CopyableRandomAccessRange>));

            iterator_range<
                BOOST_DEDUCED_TYPENAME range_iterator<
                    const CopyableRandomAccessRange
                >::type
            > temp(adaptors::slice(r, f.t, f.u));

            return CopyableRandomAccessRange(temp.begin(), temp.end());
        }

        template<class CopyableRandomAccessRange>
        inline CopyableRandomAccessRange
        copy(const CopyableRandomAccessRange& rng, std::size_t t, std::size_t u)
        {
            BOOST_RANGE_CONCEPT_ASSERT((
                RandomAccessRangeConcept<const CopyableRandomAccessRange>));

            iterator_range<
                BOOST_DEDUCED_TYPENAME range_iterator<
                    const CopyableRandomAccessRange
                >::type
            > temp(adaptors::slice(rng, t, u));

            return CopyableRandomAccessRange( temp.begin(), temp.end() );
        }
    } // 'adaptors'

}

#endif // include guard
