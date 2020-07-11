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

#ifndef POICA_BUILTIN_EITHER_H
#define POICA_BUILTIN_EITHER_H

#include <poica/force_semicolon.h>
#include <poica/p.h>

#include <poica/choice.h>

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX
#define PoicaDefEither POICA_P_EITHER_DEF
#else
#define DefEither POICA_P_EITHER_DEF
#endif

#define POICA_P_EITHER_DEF(left_type, right_type)                              \
    choice(POICA_P_P(Either, left_type, right_type),                           \
           variant(POICA_P_P(Left, left_type, right_type), left_type)          \
               variant(POICA_P_P(Right, left_type, right_type), right_type));  \
                                                                               \
    inline static bool POICA_P_P(isLeft, left_type, right_type)(               \
        POICA_P_P(Either, left_type, right_type) either) {                     \
        return POICA_P_MATCHES(either,                                         \
                               POICA_P_P(Left, left_type, right_type));        \
    }                                                                          \
                                                                               \
    inline static bool POICA_P_P(isRight, left_type, right_type)(              \
        POICA_P_P(Either, left_type, right_type) either) {                     \
        return POICA_P_MATCHES(either,                                         \
                               POICA_P_P(Right, left_type, right_type));       \
    }                                                                          \
                                                                               \
    POICA_FORCE_SEMICOLON

#endif // POICA_BUILTIN_EITHER_H
