// generate_re2c.hpp
// Copyright (c) 2009 Ben Hanson (http://www.benhanson.net/)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file licence_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
#ifndef LEXERTL_GENERATE_RE2C_HPP
#define LEXERTL_GENERATE_RE2C_HPP

#include "char_traits.hpp"
#include "consts.hpp"
#include "internals.hpp"
#include <iostream>
#include "runtime_error.hpp"
#include "size_t.hpp"
#include "state_machine.hpp"
#include <vector>

namespace lslboost
{
namespace lexer
{
// check whether state0_0 is referenced from any of the other states
template <typename Char>
bool need_label0_0(lslboost::lexer::basic_state_machine<Char> const &sm_)
{
    typedef typename lslboost::lexer::basic_state_machine<Char>::iterator
        iterator_type;
    iterator_type iter_ = sm_.begin();
    std::size_t states_ = iter_->states;

    for (std::size_t state_ = 0; state_ < states_; ++state_)
    {
        if (0 == iter_->bol_index || 0 == iter_->eol_index)
        {
            return true;
        }

        std::size_t const transitions_ = iter_->transitions;
        for (std::size_t t_ = 0; t_ < transitions_; ++t_)
        {
            if (0 == iter_->goto_state)
            {
                return true;
            }
            ++iter_;
        }
        if (transitions_ == 0) ++iter_;
    }
    return false;
}

template<typename CharT>
void generate_re2c (const basic_state_machine<CharT> &state_machine_,
    std::ostream &os_, const bool use_pointers_ = false,
    const bool skip_unknown_ = true, const bool optimise_parameters_ = true,
    const char *name_ = "next_token")
{
    typedef typename lslboost::lexer::basic_string_token<CharT> string_token;
    const detail::internals &sm_ = state_machine_.data ();

    if (sm_._lookup->size () == 0)
    {
        throw runtime_error ("Cannot generate code from an empty "
            "state machine");
    }

    std::string upper_name_ (__DATE__);
    const std::size_t lookups_ = sm_._lookup->front ()->size ();
    typename lslboost::lexer::basic_state_machine<CharT>::iterator iter_ =
        state_machine_.begin();
    typename lslboost::lexer::basic_state_machine<CharT>::iterator end_ =
        state_machine_.end();
    const std::size_t dfas_ = sm_._dfa->size ();
    std::string::size_type pos_ = upper_name_.find (' ');
    const char *iterator_ = 0;

    if (use_pointers_)
    {
        if (lookups_ == 256)
        {
            iterator_ = "const char *";
        }
        else
        {
            iterator_ = "const wchar_t *";
        }
    }
    else
    {
        iterator_ = "Iterator &";
    }

    while (pos_ != std::string::npos)
    {
        upper_name_.replace (pos_, 1, "_");
        pos_ = upper_name_.find (' ', pos_);
    }

    upper_name_ += '_';
    upper_name_ +=  __TIME__;

    pos_ = upper_name_.find (':');

    while (pos_ != std::string::npos)
    {
        upper_name_.erase (pos_, 1);
        pos_ = upper_name_.find (':', pos_);
    }

    upper_name_ = '_' + upper_name_;
    upper_name_ = name_ + upper_name_;
    std::transform (upper_name_.begin (), upper_name_.end (),
        upper_name_.begin (), ::toupper);
    os_ << "#ifndef " << upper_name_ + '\n';
    os_ << "#define " << upper_name_ + '\n';
    os_ << "// Copyright (c) 2008-2009 Ben Hanson\n";
    os_ << "//\n";
    os_ << "// Distributed under the Boost Software License, "
        "Version 1.0. (See accompanying\n";
    os_ << "// file licence_1_0.txt or copy at "
        "http://www.lslboost.org/LICENSE_1_0.txt)\n\n";
    os_ << "// Auto-generated by lslboost::lexer\n";
    os_ << "template<typename Iterator>\n";
    os_ << "std::size_t " << name_  << " (";

    if (dfas_ > 1 || !optimise_parameters_)
    {
        os_ << "std::size_t &start_state_, ";
    }

    if (use_pointers_)
    {
        os_ << iterator_ << " &";
    }
    else
    {
        os_ << iterator_;
    }

    os_ << "start_token_, ";

    if (use_pointers_)
    {
        os_ << iterator_ << " const ";
    }
    else
    {
        os_ << "const " << iterator_;
    }

    os_ << "end_, \n";
    os_ << "    std::size_t &unique_id_";

    if (sm_._seen_BOL_assertion || !optimise_parameters_)
    {
        os_ << ", bool &beg_of_line_";
    }

    os_ << ")\n";
    os_ << "{\n";
    os_ << "    static const std::size_t npos = static_cast"
        "<std::size_t>(~0);\n";
    os_ << "\n    if (start_token_ == end_)\n";
    os_ << "    {\n";
    os_ << "        unique_id_ = npos;\n";
    os_ << "        return 0;\n";
    os_ << "    }\n\n";

    if (dfas_ > 1)
    {
        os_ << "again:\n";
    }

    os_ << "    Iterator curr_ = start_token_;\n";
    os_ << "    bool end_state_ = false;\n";
    os_ << "    std::size_t id_ = npos;\n";
    os_ << "    std::size_t uid_ = npos;\n";

    if (dfas_ > 1)
    {
        os_ << "    std::size_t end_start_state_ = start_state_;\n";
    }

    if (sm_._seen_BOL_assertion)
    {
        os_ << "    bool bol_ = beg_of_line_;\n";
        os_ << "    bool end_bol_ = bol_;\n";
    }

    os_ << "    Iterator end_token_ = start_token_;\n";
    os_ << '\n';

    if (dfas_ > 1)
    {
        os_ << "    switch (start_state_)\n";
        os_ << "    {\n";

        for (std::size_t i_ = 0; i_ < dfas_; ++i_)
        {
            os_ << "    case " << i_ << ":\n";
            os_ << "        goto " << i_ << "_0;\n";
            os_ << "        // Not needed, but to prevent warnings\n";
            os_ << "        break;\n";
        }

        os_ << "    default:\n";
        os_ << "        throw std::runtime_error (\"Invalid start state!\")\n";
        os_ << "        break;\n";
        os_ << "    }\n\n";
    }

    os_ << "    ";

    if (lookups_ == 256)
    {
        os_ << "char";
    }
    else
    {
        os_ << "wchar_t";
    }

    os_ << " ch_ = 0;\n\n";

    bool need_state0_0_label = need_label0_0(state_machine_);

    for (std::size_t dfa_ = 0; dfa_ < dfas_; ++dfa_)
    {
        const std::size_t states_ = iter_->states;

        for (std::size_t state_ = 0; state_ < states_; ++state_)
        {
            const std::size_t transitions_ = iter_->transitions;
            std::size_t t_ = 0;

            if (dfas_ > 1 || dfa_ != 0 || state_ != 0 || need_state0_0_label)
            {
                os_ << "state" << dfa_ << '_' << state_ << ":\n";
            }

            if (iter_->end_state)
            {
                os_ << "    end_state_ = true;\n";
                os_ << "    id_ = " << iter_->id << ";\n";
                os_ << "    uid_ = " << iter_->unique_id << ";\n";
                os_ << "    end_token_ = curr_;\n";

                if (dfas_ > 1)
                {
                    os_ << "    end_start_state_ = " << iter_->goto_dfa <<
                        ";\n";
                }

                if (sm_._seen_BOL_assertion)
                {
                    os_ << "    end_bol_ = bol_;\n";
                }

                if (transitions_) os_ << '\n';
            }

            if (t_ < transitions_ || iter_->bol_index != lslboost::lexer::npos ||
                iter_->eol_index != lslboost::lexer::npos)
            {
                os_ << "    if (curr_ == end_) goto end;\n\n";
                os_ << "    ch_ = *curr_;\n";

                if (iter_->bol_index != lslboost::lexer::npos)
                {
                    os_ << "\n    if (bol_) goto state" << dfa_ << '_' <<
                        iter_->bol_index << ";\n\n";
                }

                if (iter_->eol_index != lslboost::lexer::npos)
                {
                    os_ << "\n    if (ch_ == '\n') goto state" << dfa_ << '_' <<
                        iter_->eol_index << ";\n\n";
                }

                os_ << "    ++curr_;\n";
            }

            for (; t_ < transitions_; ++t_)
            {
                const char *ptr_ = iter_->token._charset.c_str();
                const char *end_ = ptr_ + iter_->token._charset.size();
                char start_char_ = 0;
                char curr_char_ = 0;
                bool range_ = false;
                bool first_char_ = true;

                os_ << "\n    if (";

                while (ptr_ != end_)
                {
                    curr_char_ = *ptr_++;

                    if (*ptr_ == curr_char_ + 1)
                    {
                        if (!range_)
                        {
                            start_char_ = curr_char_;
                        }

                        range_ = true;
                    }
                    else
                    {
                        if (!first_char_)
                        {
                            if (iter_->token._negated)
                            {
                                os_ << " && ";
                            }
                            else
                            {
                                os_ << " || ";
                            }
                        }

                        first_char_ = false;

                        if (range_)
                        {
                            typename string_token::string temp_;

                            if (iter_->token._negated)
                            {
                                os_ << "!";
                            }

                            string_token::escape_char (start_char_, temp_);
                            os_ << "(ch_ >= '" << temp_;
                            temp_.clear ();
                            string_token::escape_char (curr_char_, temp_);
                            os_ << "' && ch_ <= '" << temp_ << "')";
                            range_ = false;
                        }
                        else
                        {
                            typename string_token::string temp_;

                            os_ << "ch_ ";

                            if (iter_->token._negated)
                            {
                                os_ << "!=";
                            }
                            else
                            {
                                os_ << "==";
                            }

                            string_token::escape_char (curr_char_, temp_);
                            os_ << " '" << temp_ << "'";
                        }
                    }
                }

                os_ << ") goto state" << dfa_ << '_' << iter_->goto_state <<
                    ";\n\n";
                ++iter_;
            }

            if (!(dfa_ == dfas_ - 1 && state_ == states_ - 1))
            {
                os_ << "    goto end;\n";
            }

            if (transitions_ == 0) ++iter_;
        }
    }

    os_ << "end:\n";
    os_ << "    if (end_state_)\n";
    os_ << "    {\n";
    os_ << "        // return longest match\n";

    if (dfas_ > 1)
    {
        os_ << "        start_state_ = end_start_state_;\n";
    }

    if (sm_._seen_BOL_assertion && dfas_ < 2)
    {
        os_ << "        beg_of_line_ = end_bol_;\n";
    }

    os_ << "        start_token_ = end_token_;\n";

    if (dfas_ > 1)
    {
        os_ << '\n';
        os_ << "        if (id_ == 0)\n";
        os_ << "        {\n";

        if (sm_._seen_BOL_assertion)
        {
            os_ << "            bol_ = end_bol_;\n";
        }

        os_ << "            goto again;\n";
        os_ << "        }\n";

        if (sm_._seen_BOL_assertion)
        {
            os_ << "        else\n";
            os_ << "        {\n";
            os_ << "            beg_of_line_ = end_bol_;\n";
            os_ << "        }\n";
        }
    }

    os_ << "    }\n";
    os_ << "    else\n";
    os_ << "    {\n";

    if (sm_._seen_BOL_assertion)
    {
        os_ << "        beg_of_line_ = *start_token_ == '\\n';\n";
    }

    if (skip_unknown_)
    {
        os_ << "        // No match causes char to be skipped\n";
        os_ << "        ++start_token_;\n";
    }

    os_ << "        id_ = npos;\n";
    os_ << "        uid_ = npos;\n";
    os_ << "    }\n";
    os_ << '\n';
    os_ << "    unique_id_ = uid_;\n";
    os_ << "    return id_;\n";
    os_ << "}\n";
    os_ << "\n#endif\n";
}
}
}
#endif
