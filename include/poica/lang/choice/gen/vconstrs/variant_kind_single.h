
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

#ifndef POICA_LANG_CHOICE_GEN_VCONSTRS_VARIANT_KIND_SINGLE_H
#define POICA_LANG_CHOICE_GEN_VCONSTRS_VARIANT_KIND_SINGLE_H

#include <poica/lang/choice/gen/tags.h>

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_CHOICE_GEN_VCONSTR_VARIANT_KIND_SINGLE(                                       \
    choice_name, variant_name, variant_type)                                                       \
    inline static choice_name variant_name(variant_type arg) {                                     \
        return (choice_name){                                                                      \
            .tag = POICA_P_LANG_CHOICE_VARIANT_NAME_AS_TAG(variant_name),                          \
            .data.variant_name = arg,                                                              \
        };                                                                                         \
    }

#endif // POICA_LANG_CHOICE_GEN_VCONSTRS_VARIANT_KIND_SINGLE_H
