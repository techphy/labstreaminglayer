#ifndef BOOST_SERIALIZATION_FORWARD_LIST_HPP
#define BOOST_SERIALIZATION_FORWARD_LIST_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// forward_list.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.lslboost.org/LICENSE_1_0.txt)

//  See http://www.lslboost.org for updates, documentation, and revision history.

#include <forward_list>
#include <iterator>  // distance

#include <lslboost/serialization/collections_save_imp.hpp>
#include <lslboost/serialization/collections_load_imp.hpp>
#include <lslboost/archive/detail/basic_iarchive.hpp>
#include <lslboost/serialization/nvp.hpp>
#include <lslboost/serialization/collection_size_type.hpp>
#include <lslboost/serialization/item_version_type.hpp>
#include <lslboost/serialization/split_free.hpp>
#include <lslboost/serialization/detail/stack_constructor.hpp>
#include <lslboost/serialization/detail/is_default_constructible.hpp>

namespace lslboost { 
namespace serialization {

template<class Archive, class U, class Allocator>
inline void save(
    Archive & ar,
    const std::forward_list<U, Allocator> &t,
    const unsigned int file_version
){
    const collection_size_type count(std::distance(t.cbegin(), t.cend()));
    lslboost::serialization::stl::save_collection<
        Archive,
        std::forward_list<U, Allocator>
    >(ar, t, count);
}

namespace stl {

template<
    class Archive,
    class T,
    class Allocator
>
typename lslboost::disable_if<
    typename detail::is_default_constructible<
        typename std::forward_list<T, Allocator>::value_type
    >,
    void
>::type
collection_load_impl(
    Archive & ar,
    std::forward_list<T, Allocator> &t,
    collection_size_type count,
    item_version_type item_version
){
    t.clear();
    lslboost::serialization::detail::stack_construct<Archive, T> u(ar, item_version);
    ar >> lslboost::serialization::make_nvp("item", u.reference());
    t.push_front(u.reference());
    typename std::forward_list<T, Allocator>::iterator last;
    last = t.begin();
    ar.reset_object_address(&(*t.begin()) , & u.reference());
    while(--count > 0){
        detail::stack_construct<Archive, T> u(ar, item_version);
        ar >> lslboost::serialization::make_nvp("item", u.reference());
        last = t.insert_after(last, u.reference());
        ar.reset_object_address(&(*last) , & u.reference());
    }
}

} // stl

template<class Archive, class U, class Allocator>
inline void load(
    Archive & ar,
    std::forward_list<U, Allocator> &t,
    const unsigned int file_version
){
    const lslboost::archive::library_version_type library_version(
        ar.get_library_version()
    );
    // retrieve number of elements
    item_version_type item_version(0);
    collection_size_type count;
    ar >> BOOST_SERIALIZATION_NVP(count);
    if(lslboost::archive::library_version_type(3) < library_version){
        ar >> BOOST_SERIALIZATION_NVP(item_version);
    }
    stl::collection_load_impl(ar, t, count, item_version);
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class U, class Allocator>
inline void serialize(
    Archive & ar,
    std::forward_list<U, Allocator> &t,
    const unsigned int file_version
){
    lslboost::serialization::split_free(ar, t, file_version);
}

} // serialization
} // namespace lslboost

#include <lslboost/serialization/collection_traits.hpp>

BOOST_SERIALIZATION_COLLECTION_TRAITS(std::forward_list)

#endif  // BOOST_SERIALIZATION_FORWARD_LIST_HPP
