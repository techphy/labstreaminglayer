/* 
   Copyright (c) Marshall Clow 2008-2012.

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
*/

/// \file  none_of.hpp
/// \brief Test ranges to see if no elements match a value or predicate.
/// \author Marshall Clow

#ifndef BOOST_ALGORITHM_NONE_OF_HPP
#define BOOST_ALGORITHM_NONE_OF_HPP

#include <algorithm>    // for std::none_of, if available
#include <lslboost/range/begin.hpp>
#include <lslboost/range/end.hpp>

namespace lslboost { namespace algorithm {

/// \fn none_of ( InputIterator first, InputIterator last, Predicate p )
/// \return true if none of the elements in [first, last) satisfy the predicate 'p'
/// \note returns true on an empty range
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param p     A predicate for testing the elements of the sequence
///
template<typename InputIterator, typename Predicate> 
bool none_of ( InputIterator first, InputIterator last, Predicate p )
{
for ( ; first != last; ++first )
    if ( p(*first)) 
        return false;
    return true;
} 

/// \fn none_of ( const Range &r, Predicate p )
/// \return true if none of the elements in the range satisfy the predicate 'p'
/// \note returns true on an empty range
/// 
/// \param r     The input range
/// \param p     A predicate for testing the elements of the range
///
template<typename Range, typename Predicate> 
bool none_of ( const Range &r, Predicate p )
{
    return lslboost::algorithm::none_of (lslboost::begin (r), lslboost::end (r), p );
} 

/// \fn none_of_equal ( InputIterator first, InputIterator last, const V &val )
/// \return true if none of the elements in [first, last) are equal to 'val'
/// \note returns true on an empty range
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param val   A value to compare against
///
template<typename InputIterator, typename V> 
bool none_of_equal ( InputIterator first, InputIterator last, const V &val ) 
{
    for ( ; first != last; ++first )
        if ( val == *first )
            return false;
    return true; 
} 

/// \fn none_of_equal ( const Range &r, const V &val )
/// \return true if none of the elements in the range are equal to 'val'
/// \note returns true on an empty range
/// 
/// \param r     The input range
/// \param val   A value to compare against
///
template<typename Range, typename V> 
bool none_of_equal ( const Range &r, const V & val ) 
{
    return lslboost::algorithm::none_of_equal (lslboost::begin (r), lslboost::end (r), val);
} 

}} // namespace lslboost and algorithm

#endif // BOOST_ALGORITHM_NONE_OF_HPP
