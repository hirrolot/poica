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

#ifndef POICA_LANG_GADT_H
#define POICA_LANG_GADT_H

#include <poica/lang/private/call_macro.h>
#include <poica/lang/private/map.h>
#include <poica/lang/private/variadic_to_seq.h>

#include <poica/lang/choice.h>
#include <poica/lang/force_semicolon.h>

#include <poica/lang/gadt/construct_variants.h>
#include <poica/lang/gadt/match.h>
#include <poica/lang/gadt/variant.h>
#include <poica/lang/gadt/variants_to_map.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define poicaGadt POICA_P_LANG_GADT

#else

#define gadt POICA_P_LANG_GADT

#endif

#define POICA_P_LANG_GADT(name, ...)                                                               \
    POICA_P_LANG_GADT_EXPAND(BOOST_PP_SEQ_FOR_EACH(                                                \
        POICA_P_LANG_GADT_VISIT,                                                                   \
        name,                                                                                      \
        POICA_P_LANG_GADT_VARIANTS_TO_MAP(                                                         \
            POICA_P_LANG_GADT_CONSTRUCT_VARIANTS(POICA_P_LANG_VARIADIC_TO_SEQ(__VA_ARGS__)))))     \
                                                                                                   \
    POICA_FORCE_SEMICOLON

#define POICA_P_LANG_GADT_VISIT(_r, gadt_name, variants)                                           \
    POICA_P_LANG_GADT_DEFER(POICA_P_LANG_GADT_VISIT_AUX)(gadt_name, (variants))

#define POICA_P_LANG_GADT_VISIT_AUX(gadt_name, variants)                                           \
    POICA_P_LANG_CHOICE(POICA_P_LANG_GADT_CHOICE_NAME(gadt_name, variants),                        \
                        BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_GADT_VISIT_GEN_VARIANT,                 \
                                              POICA_P_LANG_MAP_ITEM_KEY(variants),                 \
                                              POICA_P_LANG_MAP_ITEM_VALUE(variants)));

#define POICA_P_LANG_GADT_CHOICE_NAME(gadt_name, variants)                                         \
    POICA_P_LANG_P(gadt_name, BOOST_PP_TUPLE_REM() POICA_P_LANG_MAP_ITEM_KEY(variants))

#define POICA_P_LANG_GADT_VISIT_GEN_VARIANT(_r, variant_self_types, variant)                       \
    (BOOST_PP_SEQ_REPLACE(                                                                         \
        variant,                                                                                   \
        1,                                                                                         \
        POICA_P_LANG_P(POICA_VARIANT_NAME(variant), POICA_P_LANG_EXPAND variant_self_types)))

#define POICA_P_LANG_GADT_EMPTY()
#define POICA_P_LANG_GADT_DEFER(op)   op POICA_P_LANG_GADT_EMPTY()
#define POICA_P_LANG_GADT_EXPAND(...) __VA_ARGS__

#endif // POICA_LANG_GADT_H
