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

#ifndef POICA_PAIR_H
#define POICA_PAIR_H

#include <poica/private/form_type_name.h>

#include <poica/record.h>

#include <boost/preprocessor.hpp>

#ifdef POICA_USE_PREFIX

#define PoicaPairDef POICA_P_PAIR_DEF
#define PoicaPair    POICA_P_PAIR

#else

#define PairDef POICA_P_PAIR_DEF
#define Pair    POICA_P_PAIR

#endif

#define POICA_P_PAIR_DEF(fst_type, snd_type)                                   \
    record(POICA_P_PAIR(fst_type, snd_type),                                   \
           field(fst, fst_type) variant(snd, snd_type))

#define POICA_P_PAIR(fst_type, snd_type)                                       \
    POICA_P_FORM_TYPE_NAME(Pair, fst_type, snd_type)

#endif // POICA_PAIR_H
