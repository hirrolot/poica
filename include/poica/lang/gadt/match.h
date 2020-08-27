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
#ifndef POICA_LANG_GADT_MATCH_H

#define POICA_LANG_GADT_MATCH_H

#include <poica/lang/private/defer.h>
#include <poica/lang/private/map.h>

#include <poica/lang/choice/pattern_matching.h>
#include <poica/lang/gadt/pattern_matching/arms_to_map.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#ifdef POICA_USE_PREFIX
#define poicaMatchGadt POICA_P_LANG_MATCH_GADT
#else
#define matchGadt POICA_P_LANG_MATCH_GADT
#endif

#define BOOST_VMD_REGISTER_gadtOf     (gadtOf)
#define BOOST_VMD_REGISTER_gadtOfMany (gadtOfMany)
#define BOOST_VMD_REGISTER_do         (do)

#define BOOST_VMD_DETECT_gadtOf_gadtOf
#define BOOST_VMD_DETECT_gadtOfMany_gadtOfMany
#define BOOST_VMD_DETECT_do_do

#define POICA_P_LANG_MATCH_GADT(val, ...)                                                          \
    POICA_P_LANG_EXPAND(POICA_P_LANG_EXPAND(POICA_P_LANG_EXPAND(                                   \
        BOOST_PP_SEQ_FOR_EACH(POICA_P_LANG_MATCH_GADT_VISIT,                                       \
                              (val),                                                               \
                              POICA_P_LANG_GADT_PATTERN_MATCHING_ARMS_TO_MAP(__VA_ARGS__)))))

#define POICA_P_LANG_MATCH_GADT_VISIT(_r, val, arms)                                               \
    POICA_P_LANG_DEFER(POICA_P_LANG_MATCH_GADT_VISIT_AUX)                                          \
    (POICA_P_LANG_MAP_ITEM_KEY((arms)), val, arms)

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX(arm_types, val, arms)                                    \
    POICA_P_LANG_MATCH(val) {                                                                      \
        POICA_P_LANG_DEFER(BOOST_PP_SEQ_FOR_EACH)                                                  \
        (POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM,                                                \
         arm_types,                                                                                \
         POICA_P_LANG_MAP_ITEM_VALUE((arms)))                                                      \
    }

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM(_r, arm_types, arm)                              \
    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_AUX(arm_types, arm)

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_EXPAND(...) __VA_ARGS__

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_AUX(arm_types, arm)                              \
    BOOST_PP_CAT(POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_, BOOST_PP_SEQ_ELEM(0, arm))            \
    (arm_types, BOOST_PP_SEQ_ELEM(1, arm)) {                                                       \
        POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_AUX_EXPAND                                       \
        BOOST_PP_SEQ_ELEM(2, arm)                                                                  \
    }

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_AUX_EXPAND(...) __VA_ARGS__

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_gadtOf                                           \
    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOf
#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_gadtOfMany                                       \
    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOfMany
#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_gadtOfMut                                        \
    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOfMut
#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_gadtOfManyMut                                    \
    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOfManyMut

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOf(arm_types, arm_params)               \
    POICA_P_LANG_DEFER(POICA_P_LANG_OF)                                                            \
    (const,                                                                                        \
     POICA_P_LANG_P(BOOST_PP_TUPLE_ELEM(0, arm_params),                                            \
                    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_SPECIALISED arm_types),              \
     BOOST_PP_TUPLE_ELEM(1, arm_params))

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOfMany(arm_types, arm_params)           \
    POICA_P_LANG_DEFER(POICA_P_LANG_OF_MANY)                                                       \
    (const,                                                                                        \
     POICA_P_LANG_P(BOOST_PP_TUPLE_ELEM(0, arm_params),                                            \
                    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_SPECIALISED arm_types),              \
     BOOST_PP_TUPLE_ELEM(1, arm_params))

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOfMut(arm_types, arm_params)            \
    POICA_P_LANG_DEFER(POICA_P_LANG_OF)                                                            \
    (,                                                                                             \
     POICA_P_LANG_P(BOOST_PP_TUPLE_ELEM(0, arm_params),                                            \
                    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_SPECIALISED arm_types),              \
     BOOST_PP_TUPLE_ELEM(1, arm_params))

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_poicaGadtOfManyMut(arm_types, arm_params)        \
    POICA_P_LANG_DEFER(POICA_P_LANG_OF_MANY)                                                       \
    (,                                                                                             \
     POICA_P_LANG_P(BOOST_PP_TUPLE_ELEM(0, arm_params),                                            \
                    POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_SPECIALISED arm_types),              \
     BOOST_PP_TUPLE_ELEM(1, arm_params))

#define POICA_P_LANG_MATCH_GADT_VISIT_AUX_GEN_ARM_SPECIALISED(...) __VA_ARGS__

#define POICA_P_LANG_MATCH_GADT_GET_ARM_VARIANT(arm)                                               \
    (BOOST_VMD_ELEM(0, POICA_P_LANG_EXPAND arm))(BOOST_VMD_ELEM(1, POICA_P_LANG_EXPAND arm))
#define POICA_P_LANG_MATCH_GADT_GET_ARM_TYPES(arm) BOOST_VMD_ELEM(4, POICA_P_LANG_EXPAND arm)
#define POICA_P_LANG_MATCH_GADT_GET_ARM_BLOCK(arm) BOOST_VMD_ELEM(6, POICA_P_LANG_EXPAND arm)
#define POICA_P_LANG_MATCH_GADT_GET_ARM_REST(arm)                                                  \
    (POICA_P_LANG_MATCH_GADT_GET_ARM_VARIANT(arm)(POICA_P_LANG_MATCH_GADT_GET_ARM_BLOCK(arm)))

#endif // POICA_LANG_GADT_MATCH_H
