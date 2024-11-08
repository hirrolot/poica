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

#ifndef POICA_LANG_ASSERTIONS_OVERLOAD_ON_KIND_H
#define POICA_LANG_ASSERTIONS_OVERLOAD_ON_KIND_H

#include <poica/lang/private/defer.h>

#include <boost/vmd/vmd.hpp>

#ifdef POICA_ENABLE_ASSERTIONS

#define POICA_P_LANG_ASSERT_IS_OVERLOAD_ON_KIND_DATA(seq)                                          \
    BOOST_PP_IF(BOOST_VMD_IS_EMPTY(seq),                                                           \
                POICA_P_LANG_ASSERT_IS_OVERLOAD_ON_KIND_DATA_EMPTY,                                \
                POICA_P_LANG_ASSERT_IS_OVERLOAD_ON_KIND_DATA_NOT_EMPTY)                            \
    (seq)

#define POICA_P_LANG_ASSERT_IS_OVERLOAD_ON_KIND_DATA_EMPTY(seq) 1

#define POICA_P_LANG_ASSERT_IS_OVERLOAD_ON_KIND_DATA_NOT_EMPTY(seq)                                \
    BOOST_VMD_ASSERT_IS_SEQ(seq)                                                                   \
    BOOST_VMD_ASSERT(BOOST_PP_GREATER_EQUAL(BOOST_PP_SEQ_SIZE(seq), 1))

#else

#define POICA_P_LANG_ASSERT_IS_OVERLOAD_ON_KIND_DATA(_seq) BOOST_PP_EMPTY()

#endif

#endif // POICA_LANG_ASSERTIONS_OVERLOAD_ON_KIND_H
