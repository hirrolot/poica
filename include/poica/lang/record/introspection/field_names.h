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

#ifndef POICA_LANG_RECORD_INTROSPECTION_FIELD_NAMES_H
#define POICA_LANG_RECORD_INTROSPECTION_FIELD_NAMES_H

#include <poica/lang/assertions/fields.h>
#include <poica/lang/private/defer.h>
#include <poica/lang/record/introspection/aux.h>

#include <boost/preprocessor.hpp>

#define POICA_FIELD_NAME(field)                                                                    \
    POICA_ASSERT_IS_FIELD(field)                                                                   \
                                                                                                   \
    BOOST_PP_SEQ_ELEM(0, POICA_P_LANG_EXPAND field)

#define POICA_RECORD_FIELD_NAMES_SEQ(fields)                                                       \
    POICA_ASSERT_ARE_FIELDS(fields)                                                                \
                                                                                                   \
    POICA_P_LANG_RECORD_FIELD_X_SEQ(POICA_P_LANG_RECORD_GEN_FIELD_NAMES_SEQ_VISIT, fields)

#define POICA_P_LANG_RECORD_GEN_FIELD_NAMES_SEQ_VISIT(_r, _data, field) (POICA_FIELD_NAME((field)))

#define POICA_RECORD_FIELD_NAMES_TUPLE(fields)                                                     \
    POICA_ASSERT_ARE_FIELDS(fields)                                                                \
                                                                                                   \
    POICA_P_LANG_RECORD_FIELD_X_TUPLE(POICA_P_LANG_RECORD_GEN_FIELD_NAMES_TUPLE_VISIT,             \
                                      POICA_P_LANG_RECORD_GEN_FIELD_NAMES_TUPLE_VISIT_LAST,        \
                                      fields)

#define POICA_P_LANG_RECORD_GEN_FIELD_NAMES_TUPLE_VISIT(_r, _data, field) POICA_FIELD_NAME((field)),
#define POICA_P_LANG_RECORD_GEN_FIELD_NAMES_TUPLE_VISIT_LAST(field)       POICA_FIELD_NAME((field))

#endif // POICA_LANG_RECORD_INTROSPECTION_FIELD_NAMES_H
