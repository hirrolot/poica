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

#ifndef ENUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_KIND_MANY_H
#define ENUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_KIND_MANY_H

#include <boost/preprocessor.hpp>

// Generate nothing because we already generate a product type for
// POICA_VARIANT_KIND_MANY with a name
// POICA_P_ENUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name).
#define POICA_P_ENUM_GEN_REDIRECT_VARIANT_TO_INNER_TYPE_VARIANT_KIND_MANY(     \
    _data, _variant_name, _fields)

#endif // ENUM_GEN_REDIRECTS_TO_INNER_TYPE_VARIANT_KIND_MANY_H
