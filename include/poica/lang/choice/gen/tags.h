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

#ifndef POICA_LANG_CHOICE_GEN_TAGS_H
#define POICA_LANG_CHOICE_GEN_TAGS_H

#include <poica/lang/private/prefix.h>

#include <poica/lang/choice/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_CHOICE_GEN_TAGS(variants)                                                     \
    BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_CHOICE_GEN_TAG, BOOST_PP_EMPTY(), variants)

#define POICA_P_LANG_CHOICE_GEN_TAG(_r, _data, variant)                                            \
    POICA_P_LANG_CHOICE_VARIANT_NAME_AS_TAG(POICA_VARIANT_NAME(variant)),

#define POICA_P_LANG_CHOICE_VARIANT_NAME_AS_TAG(variant_name)                                      \
    POICA_P_LANG_PREFIX(BOOST_PP_CAT(variant_name, _Tag))

#endif // POICA_LANG_CHOICE_GEN_TAGS_H
