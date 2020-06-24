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

/*
 * Let us have a simple arithmetical language, consisting of:
 *
 *  1) Constants of double;
 *  2) Expressions: either expr1 (+ | - | * | /) expr2 or a constant.
 *
 *
 * A sum type can be used to represent the hierarchical structure of ASTs, and
 * pattern matching is a technique to evaluate them.
 */

#include <poica.h>

#include <stdio.h>

// clang-format off
record(
    ExprPair,
    field(left, const struct Expr *)
    field(right, const struct Expr *)
);

enum(
    Expr,
    variant(MkConst, double)
    variant(MkAdd, ExprPair)
    variant(MkSub, ExprPair)
    variant(MkMul, ExprPair)
    variant(MkDiv, ExprPair)
);
// clang-format on

double eval(const Expr *expr) {
    match(expr) {
        case(MkConst, number) {
            return *number;
        }
        case(MkAdd, add) {
            return eval(add->left) + eval(add->right);
        }
        case(MkSub, sub) {
            return eval(sub->left) - eval(sub->right);
        }
        case(MkMul, mul) {
            return eval(mul->left) * eval(mul->right);
        }
        case(MkDiv, div) {
            return eval(div->left) / eval(div->right);
        }
    }
}

#define EXPR(expr)          obj(expr, Expr)
#define OP(op, left, right) Mk##op((ExprPair){EXPR(left), EXPR(right)})

int main(void) {
    Expr expr = OP(Add,
                   MkConst(53),
                   OP(Sub, OP(Div, MkConst(155), MkConst(5)), MkConst(113)));

    /*
     * Output:
     * -29.000000
     */
    printf("%f\n", eval(&expr));
}

#undef EXPR
#undef OP
