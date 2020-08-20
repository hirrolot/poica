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

#ifndef POICA_LANG_CHOICE_INTROSPECTION_OVERLOAD_ON_VARIANT_H
#define POICA_LANG_CHOICE_INTROSPECTION_OVERLOAD_ON_VARIANT_H

#include <poica/lang/assertions/variants.h>
#include <poica/lang/choice/introspection.h>
#include <poica/lang/private/defer.h>
#include <poica/lang/private/overload_on_kind.h>

#include <boost/preprocessor.hpp>

#define POICA_OVERLOAD_ON_VARIANT(macro, data, variant)                        \
    POICA_P_LANG_OPT_ASSERT_IS_VARIANT(variant)                                \
                                                                               \
    POICA_P_LANG_OVERLOAD_ON_KIND(                                             \
        macro, POICA_P_LANG_OVERLOAD_ON_VARIANT_TRANSFORM_SEQ(data, variant))

#define POICA_P_LANG_OVERLOAD_ON_VARIANT_TRANSFORM_SEQ(data, variant)          \
    (BOOST_PP_CAT(POICA_P_LANG_CHOICE_RENAME_,                                 \
                  BOOST_PP_SEQ_HEAD(POICA_P_LANG_EXPAND variant)))(data)       \
        BOOST_PP_SEQ_TAIL(POICA_P_LANG_EXPAND variant)

#define POICA_P_LANG_CHOICE_RENAME_POICA_VARIANT_KIND_EMPTY  VARIANT_KIND_EMPTY
#define POICA_P_LANG_CHOICE_RENAME_POICA_VARIANT_KIND_SINGLE VARIANT_KIND_SINGLE
#define POICA_P_LANG_CHOICE_RENAME_POICA_VARIANT_KIND_MANY   VARIANT_KIND_MANY

#endif // POICA_LANG_CHOICE_INTROSPECTION_OVERLOAD_ON_VARIANT_H
