/* lslboost random/linear_feedback_shift.hpp header file
 *
 * Copyright Jens Maurer 2002
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.lslboost.org/LICENSE_1_0.txt)
 *
 * See http://www.lslboost.org for most recent version including documentation.
 *
 * $Id$
 *
 */

#ifndef BOOST_RANDOM_LINEAR_FEEDBACK_SHIFT_HPP
#define BOOST_RANDOM_LINEAR_FEEDBACK_SHIFT_HPP

#include <iosfwd>
#include <stdexcept>
#include <lslboost/config.hpp>
#include <lslboost/cstdint.hpp>
#include <lslboost/static_assert.hpp>
#include <lslboost/integer/integer_mask.hpp>
#include <lslboost/random/detail/config.hpp>
#include <lslboost/random/detail/seed.hpp>
#include <lslboost/random/detail/operators.hpp>
#include <lslboost/random/detail/seed_impl.hpp>

namespace lslboost {
namespace random {

/**
 * Instatiations of @c linear_feedback_shift model a
 * \pseudo_random_number_generator.  It was originally
 * proposed in
 *
 *  @blockquote
 *  "Random numbers generated by linear recurrence modulo two.",
 *  Tausworthe, R. C.(1965), Mathematics of Computation 19, 201-209.
 *  @endblockquote
 */
template<class UIntType, int w, int k, int q, int s>
class linear_feedback_shift_engine
{
public:
    typedef UIntType result_type;
    BOOST_STATIC_CONSTANT(bool, has_fixed_range = false);
    BOOST_STATIC_CONSTANT(int, word_size = w);
    BOOST_STATIC_CONSTANT(int, exponent1 = k);
    BOOST_STATIC_CONSTANT(int, exponent2 = q);
    BOOST_STATIC_CONSTANT(int, step_size = s);
    BOOST_STATIC_CONSTANT(UIntType, default_seed = 341);

    /** Returns the smallest value that the generator can produce. */
    static result_type min BOOST_PREVENT_MACRO_SUBSTITUTION () { return 0; }
    /** Returns the largest value that the generator can produce. */
    static result_type max BOOST_PREVENT_MACRO_SUBSTITUTION ()
    { return wordmask(); }

    BOOST_STATIC_ASSERT(w > 0);
    BOOST_STATIC_ASSERT(q > 0);
    BOOST_STATIC_ASSERT(k < w);
    BOOST_STATIC_ASSERT(0 < 2*q && 2*q < k);
    BOOST_STATIC_ASSERT(0 < s && s <= k-q);

    /** Constructs a @c linear_feedback_shift_engine, using the default seed. */
    linear_feedback_shift_engine() { seed(); }
    
    /** Constructs a @c linear_feedback_shift_engine, seeding it with s0. */
    BOOST_RANDOM_DETAIL_ARITHMETIC_CONSTRUCTOR(linear_feedback_shift_engine,
        UIntType, s0)
    { seed(s0); }
    
    /** Constructs a @c linear_feedback_shift_engine, seeding it with seq. */
    BOOST_RANDOM_DETAIL_SEED_SEQ_CONSTRUCTOR(linear_feedback_shift_engine,
        SeedSeq, seq)
    { seed(seq); }
    
    /**
     * Constructs a @c linear_feedback_shift_engine, seeding it with 
     * values from the range [first, last).
     */
    template<class It> linear_feedback_shift_engine(It& first, It last)
    { seed(first, last); }
    
    /** Seeds a @c linear_feedback_shift_engine with the default seed. */
    void seed() {  seed(default_seed); }
    
    /** Seeds a @c linear_feedback_shift_engine with @c s0. */
    BOOST_RANDOM_DETAIL_ARITHMETIC_SEED(linear_feedback_shift_engine,
        UIntType, s0)
    {
        value = s0 & wordmask();
        if(value < (1 << (w-k))) {
            value += 1 << (w-k);
        }
    }
    
    /**
     * Seeds a @c linear_feedback_shift_engine with values
     * produced by @c seq.generate().
     */
    BOOST_RANDOM_DETAIL_SEED_SEQ_SEED(linear_feedback_shift_engine,
        SeedSeq, seq)
    { seed(detail::seed_one_int<UIntType, (UIntType(2) << (w - 1))>(seq)); }
    
    /**
     * Seeds a @c linear_feedback_shift_engine with values
     * from the range [first, last).
     */
    template<class It> void seed(It& first, It last)
    {
        seed(detail::get_one_int<UIntType, (UIntType(2) << (w - 1))>(first, last));
    }

    /** Returns the next value of the generator. */
    result_type operator()()
    {
        const UIntType b = (((value << q) ^ value) & wordmask()) >> (k-s);
        const UIntType mask = (wordmask() << (w-k)) & wordmask();
        value = ((value & mask) << s) ^ b;
        return value;
    }
  
    /** Fills a range with random values */
    template<class Iter>
    void generate(Iter first, Iter last)
    { detail::generate_from_int(*this, first, last); }

    /** Advances the state of the generator by @c z. */
    void discard(lslboost::uintmax_t z)
    {
        for(lslboost::uintmax_t j = 0; j < z; ++j) {
            (*this)();
        }
    }
    
    /**
     * Writes the textual representation of the generator to a @c std::ostream.
     */
    BOOST_RANDOM_DETAIL_OSTREAM_OPERATOR(os, linear_feedback_shift_engine, x)
    {
        os << x.value;
        return os;
    }
    
    /**
     * Reads the textual representation of the generator from a @c std::istream.
     */
    BOOST_RANDOM_DETAIL_ISTREAM_OPERATOR(is, linear_feedback_shift_engine, x)
    {
        is >> x.value;
        return is;
    }

    /**
     * Returns true if the two generators will produce identical
     * sequences of outputs.
     */
    BOOST_RANDOM_DETAIL_EQUALITY_OPERATOR(linear_feedback_shift_engine, x, y)
    { return x.value == y.value; }
    
    /**
     * Returns true if the two generators will produce different
     * sequences of outputs.
     */
    BOOST_RANDOM_DETAIL_INEQUALITY_OPERATOR(linear_feedback_shift_engine)

private:
    /// \cond show_private
    static UIntType wordmask() { return lslboost::low_bits_mask_t<w>::sig_bits; }
    /// \endcond
    UIntType value;
};

#ifndef BOOST_NO_INCLASS_MEMBER_INITIALIZATION
//  A definition is required even for integral static constants
template<class UIntType, int w, int k, int q, int s>
const bool linear_feedback_shift_engine<UIntType, w, k, q, s>::has_fixed_range;
template<class UIntType, int w, int k, int q, int s>
const int linear_feedback_shift_engine<UIntType, w, k, q, s>::word_size;
template<class UIntType, int w, int k, int q, int s>
const int linear_feedback_shift_engine<UIntType, w, k, q, s>::exponent1;
template<class UIntType, int w, int k, int q, int s>
const int linear_feedback_shift_engine<UIntType, w, k, q, s>::exponent2;
template<class UIntType, int w, int k, int q, int s>
const int linear_feedback_shift_engine<UIntType, w, k, q, s>::step_size;
template<class UIntType, int w, int k, int q, int s>
const UIntType linear_feedback_shift_engine<UIntType, w, k, q, s>::default_seed;
#endif

/// \cond show_deprecated

/** Provided for backwards compatibility. */
template<class UIntType, int w, int k, int q, int s, UIntType v = 0>
class linear_feedback_shift :
    public linear_feedback_shift_engine<UIntType, w, k, q, s>
{
    typedef linear_feedback_shift_engine<UIntType, w, k, q, s> base_type;
public:
    linear_feedback_shift() {}
    BOOST_RANDOM_DETAIL_SEED_SEQ_CONSTRUCTOR(linear_feedback_shift,
        SeedSeq, seq)
    { seed(seq); }
    BOOST_RANDOM_DETAIL_ARITHMETIC_CONSTRUCTOR(linear_feedback_shift,
        UIntType, val)
    { seed(val); }
    template<class It>
    linear_feedback_shift(It& first, It last) : base_type(first, last) {}
};

/// \endcond

} // namespace random
} // namespace lslboost

#endif // BOOST_RANDOM_LINEAR_FEEDBACK_SHIFT_HPP
