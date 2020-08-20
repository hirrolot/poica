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

#ifndef POICA_LANG_RECORD_H
#define POICA_LANG_RECORD_H

#include <poica/lang/record/field.h>
#include <poica/lang/record/gen/fields.h>
#include <poica/lang/record/introspection.h>

#include <poica/lang/assertions/fields.h>
#include <poica/lang/unit.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#ifdef POICA_USE_PREFIX
#define poicaRecord POICA_P_LANG_RECORD
#else
#define record POICA_P_LANG_RECORD
#endif

#define POICA_P_LANG_RECORD(...)                                               \
    BOOST_PP_OVERLOAD(POICA_P_LANG_RECORD_, __VA_ARGS__)(__VA_ARGS__)

#define POICA_P_LANG_RECORD_1(name)                                            \
    typedef struct name {                                                      \
        Unit _;                                                                \
    } name

#define POICA_P_LANG_RECORD_2(name, fields)                                    \
    POICA_P_LANG_OPT_ASSERT_ARE_FIELDS(fields)                                 \
                                                                               \
    typedef struct name {                                                      \
        POICA_P_LANG_RECORD_GEN_FIELDS(fields)                                 \
    } name

#endif // POICA_LANG_RECORD_H
