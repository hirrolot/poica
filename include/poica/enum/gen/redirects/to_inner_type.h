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

#ifndef POICA_ENUM_GEN_REDIRECTS_TO_INNER_TYPE_H
#define POICA_ENUM_GEN_REDIRECTS_TO_INNER_TYPE_H

#include <poica/private/aux.h>

#include <poica/enum/gen/redirects/to_inner_type/variant_empty.h>
#include <poica/enum/gen/redirects/to_inner_type/variant_many.h>
#include <poica/enum/gen/redirects/to_inner_type/variant_single.h>

#include <poica/enum/gen/records_for_many.h>
#include <poica/enum/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_P_ENUM_GEN_REDIRECTS_VARIANT_TO_INNER_TYPE(variants)             \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_ENUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE, _data, variants)

#define POICA_P_ENUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE(_r, _data, variant)    \
    POICA_OVERLOAD_ON_VARIANT(                                                 \
        POICA_P_ENUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_, _data, variant)

#define POICA_P_ENUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name)              \
    POICA_P_PREFIX(BOOST_PP_CAT(variant_name, _RedirectToInnerType))

#endif // POICA_ENUM_GEN_REDIRECTS_TO_INNER_TYPE_H
