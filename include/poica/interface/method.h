/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Temirkhan Myrzamadi
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

#ifndef POICA_INTERFACE_METHOD_H
#define POICA_INTERFACE_METHOD_H

#ifdef POICA_USE_PREFIX

#define poicaIMethod        POICA_P_I_METHOD
#define poicaIMethodSelf    POICA_P_I_METHOD_SELF
#define poicaIMethodMutSelf POICA_P_I_METHOD_MUT_SELF

#else

#define iMethod        POICA_P_I_METHOD
#define iMethodSelf    POICA_P_I_METHOD_SELF
#define iMethodMutSelf POICA_P_I_METHOD_MUT_SELF

#endif

#define POICA_P_I_METHOD(return_type, name, params)                            \
    ((I_METHOD_KIND_STATIC)(return_type)(name)(params))

#define POICA_P_I_METHOD_SELF(return_type, name, params)                       \
    ((I_METHOD_KIND_SELF)(return_type)(name)(params))

#define POICA_P_I_METHOD_MUT_SELF(return_type, name, params)                   \
    ((I_METHOD_KIND_MUT_SELF)(return_type)(name)(params))

#endif // POICA_INTERFACE_METHOD_H
