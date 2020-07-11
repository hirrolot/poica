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

#include <poica.h>

#include <assert.h>
#include <stdio.h>

typedef const char *Msg;

DefMaybe(int);
DefMaybe(Msg);

int main(void) {
    P(Maybe, int) maybe1 = P(Just, int)(123);

    /*
     * Output:
     * Just(123)
     */
    match(maybe1) {
        of(P(Just, int), number) {
            printf("Just(%d)\n", *number);
        }
        of(P(Nothing, int)) {
            puts("Nothing");
        }
    }

    assert(P(isJust, int)(maybe1));
    assert(!P(isNothing, int)(maybe1));

    P(Maybe, Msg) maybe2 = P(Nothing, Msg)();

    /*
     * Output:
     * Nothing
     */
    match(maybe2) {
        of(P(Just, Msg), msg) {
            printf("Just(\"%s\")\n", *msg);
        }
        of(P(Nothing, Msg)) {
            puts("Nothing");
        }
    }

    assert(!P(isJust, Msg)(maybe2));
    assert(P(isNothing, Msg)(maybe2));
}
