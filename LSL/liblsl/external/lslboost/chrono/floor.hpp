//  lslboost/chrono/round.hpp  ------------------------------------------------------------//

//  (C) Copyright Howard Hinnant
//  Copyright 2011 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)

//  See http://www.lslboost.org/libs/chrono for documentation.

#ifndef BOOST_CHRONO_FLOOR_HPP
#define BOOST_CHRONO_FLOOR_HPP

#include <lslboost/chrono/duration.hpp>

namespace lslboost
{
  namespace chrono
  {

    /**
     * rounds down
     */
    template <class To, class Rep, class Period>
    To floor(const duration<Rep, Period>& d)
    {
      To t = duration_cast<To>(d);
      if (t>d) --t;
      return t;
    }


  } // namespace chrono
} // namespace lslboost

#endif
