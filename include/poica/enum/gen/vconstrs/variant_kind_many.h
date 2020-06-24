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

#ifndef POICA_ENUM_GEN_VCONSTRS_VARIANT_KIND_MANY_H
#define POICA_ENUM_GEN_VCONSTRS_VARIANT_KIND_MANY_H

#include <poica/private/defer.h>

#include <poica/record/introspection.h>

#include <poica/enum/gen/tags.h>

#include <boost/preprocessor.hpp>

#define POICA_P_ENUM_GEN_VCONSTR_VARIANT_KIND_MANY(                            \
    enum_name, variant_name, fields)                                           \
    inline static enum_name variant_name(                                      \
        POICA_P_DEFER(POICA_RECORD_FIELDS_AS_PARAMS)(fields)) {                \
        return (enum_name){                                                    \
            .tag = POICA_P_ENUM_VARIANT_NAME_AS_TAG(variant_name),             \
            .data.variant_name = {POICA_P_DEFER(                               \
                POICA_P_ENUM_VCONSTR_VARIANT_KIND_MANY_INIT)(fields)},         \
        };                                                                     \
    }

#define POICA_P_ENUM_VCONSTR_VARIANT_KIND_MANY_INIT(fields)                    \
    POICA_P_ENUM_GEN_VCONSTR_VARIANT_KIND_MANY_EXPAND_ARGS                     \
    POICA_RECORD_FIELD_NAMES_TUPLE(fields)

#define POICA_P_ENUM_GEN_VCONSTR_VARIANT_KIND_MANY_EXPAND_ARGS(...) __VA_ARGS__

#endif // POICA_ENUM_GEN_VCONSTRS_VARIANT_KIND_MANY_H
