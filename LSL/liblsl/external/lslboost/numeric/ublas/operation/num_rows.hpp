/**
 * -*- c++ -*-
 *
 * \file num_rows.hpp
 *
 * \brief The \c num_rows operation.
 *
 * Copyright (c) 2009-2012, Marco Guazzone
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.lslboost.org/LICENSE_1_0.txt)
 *
 * \author Marco Guazzone, marco.guazzone@gmail.com
 */

#ifndef BOOST_NUMERIC_UBLAS_OPERATION_NUM_ROWS_HPP
#define BOOST_NUMERIC_UBLAS_OPERATION_NUM_ROWS_HPP


#include <lslboost/numeric/ublas/detail/config.hpp>
#include <lslboost/numeric/ublas/expression_types.hpp>
#include <lslboost/numeric/ublas/traits.hpp>


namespace lslboost { namespace numeric { namespace ublas {

    /**
     * \brief Return the number of rows.
     * \tparam MatrixExprT A type which models the matrix expression concept.
     * \param m A matrix expression.
     * \return The number of rows.
     */
    template <typename MatrixExprT>
    BOOST_UBLAS_INLINE
    typename matrix_traits<MatrixExprT>::size_type num_rows(matrix_expression<MatrixExprT> const& me)
    {
        return me().size1();
    }

}}} // Namespace lslboost::numeric::ublas


#endif // BOOST_NUMERIC_UBLAS_OPERATION_NUM_ROWS_HPP
