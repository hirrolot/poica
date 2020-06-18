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

#ifndef POICA_SUM_GEN_VCONSTRS_H
#define POICA_SUM_GEN_VCONSTRS_H

#include <poica/private/defer.h>

#include <poica/sum/introspection.h>

#include <poica/sum/gen/vconstrs/variant_empty.h>
#include <poica/sum/gen/vconstrs/variant_many.h>
#include <poica/sum/gen/vconstrs/variant_single.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VCONSTRS(sum_name, variants)                           \
    POICA_P_EXPAND(POICA_P_EXPAND(                                             \
        BOOST_PP_SEQ_FOR_EACH(POICA_P_SUM_GEN_VCONSTR, sum_name, variants)))

#define POICA_P_SUM_GEN_VCONSTR(_r, sum_name, variant)                         \
    OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_VCONSTR_, sum_name, variant)

#endif // POICA_SUM_GEN_VCONSTRS_H
