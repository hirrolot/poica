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

#ifndef POICA_INTERFACE_GEN_CHECKS_IS_NO_STATIC_METHODS_H
#define POICA_INTERFACE_GEN_CHECKS_IS_NO_STATIC_METHODS_H

#include <poica/private/overload_on_kind.h>

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

#define POICA_P_INTERFACE_IS_NO_STATIC_METHODS(methods)                        \
    BOOST_VMD_IS_EMPTY(BOOST_PP_SEQ_FOR_EACH(                                  \
        POICA_P_INTERFACE_IS_NO_STATIC_METHODS_VISIT_ONE, _data, methods))

#define POICA_P_INTERFACE_IS_NO_STATIC_METHODS_VISIT_ONE(_r, _data, method)    \
    POICA_P_OVERLOAD_ON_KIND(                                                  \
        POICA_P_INTERFACE_IS_NO_STATIC_METHODS_VISIT_ONE_, method)

#define POICA_P_INTERFACE_IS_NO_STATIC_METHODS_VISIT_ONE_I_METHOD_KIND_STATIC( \
    _return_type, _name, _params)                                              \
    (_)

#define POICA_P_INTERFACE_IS_NO_STATIC_METHODS_VISIT_ONE_I_METHOD_KIND_SELF(   \
    _return_type, _name, _params)

#define POICA_P_INTERFACE_IS_NO_STATIC_METHODS_VISIT_ONE_I_METHOD_KIND_MUT_SELF( \
    _return_type, _name, _params)

#endif // POICA_INTERFACE_GEN_CHECKS_IS_NO_STATIC_METHODS_H
