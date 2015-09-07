/* Copyright 2003-2013 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.lslboost.org/LICENSE_1_0.txt)
 *
 * See http://www.lslboost.org/libs/multi_index for library home page.
 */

#ifndef BOOST_MULTI_INDEX_DETAIL_HAS_TAG_HPP
#define BOOST_MULTI_INDEX_DETAIL_HAS_TAG_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <lslboost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <lslboost/mpl/contains.hpp>

namespace lslboost{

namespace multi_index{

namespace detail{

/* determines whether an index type has a given tag in its tag list */

template<typename Tag>
struct has_tag
{
  template<typename Index>
  struct apply:mpl::contains<BOOST_DEDUCED_TYPENAME Index::tag_list,Tag>
  {
  }; 
};

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace lslboost */

#endif
