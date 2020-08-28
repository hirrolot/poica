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

#ifndef POICA_LANG_CHOICE_H
#define POICA_LANG_CHOICE_H

#include <poica/lang/assertions/variants.h>
#include <poica/lang/force_semicolon.h>

#include <poica/lang/record/field.h>

#include <poica/lang/choice/gen/fields.h>
#include <poica/lang/choice/gen/records_for_many.h>
#include <poica/lang/choice/gen/redirects.h>
#include <poica/lang/choice/gen/tags.h>
#include <poica/lang/choice/gen/vconstrs.h>
#include <poica/lang/choice/is_empty_struct.h>
#include <poica/lang/choice/pattern_matching.h>
#include <poica/lang/choice/variant.h>
#include <poica/lang/choice/variant_tag.h>

#include <boost/preprocessor.hpp>

#ifndef POICA_USE_PREFIX
#define choice poicaChoice
#endif

// This macro is variadic because, due to type introspection, it must work
// correctly if actual sum type data is transferred through a macro:
// choice(MY_CHOICE);
#define poicaChoice(...) POICA_P_LANG_CHOICE_AUX(__VA_ARGS__)

#define POICA_P_LANG_CHOICE_AUX(name, variants)                                                    \
    POICA_ASSERT_ARE_VARIANTS(variants)                                                            \
                                                                                                   \
    POICA_P_LANG_CHOICE_GEN_RECORDS_FOR_MANY(variants)                                             \
                                                                                                   \
    typedef struct name {                                                                          \
        enum { POICA_P_LANG_CHOICE_GEN_TAGS(variants) } tag;                                       \
        BOOST_PP_IF(POICA_P_LANG_IS_EMPTY_STRUCT(variants), BOOST_PP_EMPTY(),                      \
                    struct {POICA_P_LANG_CHOICE_GEN_FIELDS(variants)} data;)                       \
    } name;                                                                                        \
                                                                                                   \
    POICA_P_LANG_CHOICE_GEN_REDIRECTS_VARIANT_TO_INNER_TYPE(variants)                              \
    POICA_P_LANG_CHOICE_GEN_REDIRECTS_VARIANT_TO_OUTER_CHOICE_TYPE(name, variants)                 \
    POICA_P_LANG_CHOICE_GEN_VCONSTRS(name, variants)                                               \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#endif // POICA_LANG_CHOICE_H
