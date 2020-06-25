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

#ifndef POICA_BUILTIN_MAYBE_H
#define POICA_BUILTIN_MAYBE_H

#include <poica/private/force_semicolon.h>
#include <poica/private/monomorphize.h>

#include <poica/choice.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define PoicaDefMaybe POICA_P_MAYBE_DEF
#define PoicaMaybe    POICA_P_MAYBE
#define PoicaJust     POICA_P_MAYBE_JUST
#define PoicaNothing  POICA_P_MAYBE_NOTHING

#define poicaIsJust    POICA_P_MAYBE_IS_JUST
#define poicaIsNothing POICA_P_MAYBE_IS_NOTHING

#define poicaMaybeExtractOr     POICA_P_MAYBE_EXTRACT_OR
#define poicaMaybeLazyExtractOr POICA_P_MAYBE_LAZY_EXTRACT_OR

#else

#define DefMaybe POICA_P_MAYBE_DEF
#define Maybe    POICA_P_MAYBE
#define Just     POICA_P_MAYBE_JUST
#define Nothing  POICA_P_MAYBE_NOTHING

#define isJust    POICA_P_MAYBE_IS_JUST
#define isNothing POICA_P_MAYBE_IS_NOTHING

#define maybeExtractOr     POICA_P_MAYBE_EXTRACT_OR
#define maybeLazyExtractOr POICA_P_MAYBE_LAZY_EXTRACT_OR

#endif

#define POICA_P_MAYBE_DEF(type)                                                \
    choice(POICA_P_MAYBE(type),                                                \
           variant(POICA_P_MAYBE_JUST(type), type)                             \
               variant(POICA_P_MAYBE_NOTHING(type)));                          \
                                                                               \
    inline static POICA_P_MAYBE_IS_JUST(type)(const POICA_P_MAYBE(type) *      \
                                              restrict maybe) {                \
        return POICA_P_MATCHES(maybe, POICA_P_MAYBE_JUST(type));               \
    }                                                                          \
                                                                               \
    inline static POICA_P_MAYBE_IS_NOTHING(type)(const POICA_P_MAYBE(type) *   \
                                                 restrict maybe) {             \
        return POICA_P_MATCHES(maybe, POICA_P_MAYBE_NOTHING(type));            \
    }                                                                          \
                                                                               \
    inline static POICA_P_MAYBE_EXTRACT_OR(type)(                              \
        const POICA_P_MAYBE(type) * restrict maybe,                            \
        const type *restrict default_val) {                                    \
        POICA_P_MATCH(*maybe) {                                                \
            POICA_P_OF(POICA_P_MAYBE_JUST(type), val) {                        \
                return *val;                                                   \
            }                                                                  \
            POICA_P_OF(POICA_P_MAYBE_NOTHING(type)) {                          \
                return *default_val                                            \
            }                                                                  \
        }                                                                      \
    }                                                                          \
                                                                               \
    inline static POICA_P_MAYBE_LAZY_EXTRACT_OR(type)(                         \
        const POICA_P_MAYBE(type) * restrict maybe,                            \
        const type(default_fn *)(void)) {                                      \
        POICA_P_MATCH(*maybe) {                                                \
            POICA_P_OF(POICA_P_MAYBE_JUST(type), val) {                        \
                return *val;                                                   \
            }                                                                  \
            POICA_P_OF(POICA_P_MAYBE_NOTHING(type)) {                          \
                return default_fn();                                           \
            }                                                                  \
        }                                                                      \
    }                                                                          \
                                                                               \
    POICA_P_FORCE_SEMICOLON

#define POICA_P_MAYBE(type)         POICA_P_MONOMORPHIZE(Maybe, type)
#define POICA_P_MAYBE_JUST(type)    POICA_P_MONOMORPHIZE(MaybeJust, type)
#define POICA_P_MAYBE_NOTHING(type) POICA_P_MONOMORPHIZE(MaybeNothing, type)

#define POICA_P_MAYBE_IS_JUST(type) POICA_P_MONOMORPHIZE(maybeIsJust, type)
#define POICA_P_MAYBE_IS_NOTHING(type)                                         \
    POICA_P_MONOMORPHIZE(maybeIsNothing, type)

#define POICA_P_MAYBE_EXTRACT_OR(type)                                         \
    POICA_P_MONOMORPHIZE(maybeExtractOr, type)
#define POICA_P_MAYBE_LAZY_EXTRACT_OR(type)                                    \
    POICA_P_MONOMORPHIZE(maybeLazyExtractOr, type)

#endif // POICA_BUILTIN_MAYBE_H
