/*
 * MIT License
 *
 *
 * Copyright (c) 2020 hirrolot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef POICA_CHOICE_GEN_REDIRECTS_TO_OUTER_CHOICE_TYPE_H
#define POICA_CHOICE_GEN_REDIRECTS_TO_OUTER_CHOICE_TYPE_H

#include <poica/private/prefix.h>

#include <poica/choice/introspection.h>
#include <poica/choice/variant.h>

#include <boost/preprocessor.hpp>

#define POICA_P_CHOICE_GEN_REDIRECTS_VARIANT_TO_OUTER_CHOICE_TYPE(choice_name, \
                                                                  variants)    \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_CHOICE_GEN_REDIRECT_VARIANT_TO_OUTER_CHOICE_TYPE,              \
        choice_name,                                                           \
        variants)

#define POICA_P_CHOICE_GEN_REDIRECT_VARIANT_TO_OUTER_CHOICE_TYPE(              \
    _r, choice_name, variant)                                                  \
    typedef choice_name POICA_P_CHOICE_REDIRECT_VARIANT_TO_OUTER_CHOICE_TYPE(  \
        POICA_VARIANT_NAME(variant));

#define POICA_P_CHOICE_REDIRECT_VARIANT_TO_OUTER_CHOICE_TYPE(variant_name)     \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToOuterSumType))

#endif // POICA_CHOICE_GEN_REDIRECTS_TO_OUTER_CHOICE_TYPE_H
