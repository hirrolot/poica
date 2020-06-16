<div align="center">
  <h1>poica</h1>
  
  This library provides [algebraic data types], [type introspection], and [pattern matching] for pure C11. They are used to represent data from the real world naturally, without too much boilerplate.
  
  <a href="https://github.com/hirrolot/poica/actions?query=workflow%3A%22C%2FC%2B%2B+CI%22">
  <img src="https://github.com/hirrolot/poica/workflows/C/C++%20CI/badge.svg">
  </a>
  <a href="https://github.com/teloxide/teloxide/releases/tag/v0.1.0">
  <img src="https://img.shields.io/badge/version-0.1.0-blue.svg">
  </a>
  <br>

  <img src="https://i.imgur.com/SiyRYvC.png" width="500px">
</div>

<hr>

## Features
 - C11-compliant
 - Can work on bare-metal environments
 - Comes with the [specification]
 - Product and sum types
 - [Pattern matching] with exhaustiveness checking
 - [Type introspection]
 - No third-party code generators, just `#include <poica.h>` and go!

[specification]: https://github.com/hirrolot/poica/wiki/Specification

## Motivation

Usually in C we use unions to tell a compiler that we're going to interpret a single memory region in different ways. To decide how to interpret a union, we endow it with a tag and get a [tagged union].

However, there'll be quite lot of duplication in code:

```c
typedef struct {
    enum {
        OUR_TAGGED_UNION_STATE_1,
        OUR_TAGGED_UNION_STATE_2,
        OUR_TAGGED_UNION_STATE_3,
    } state;

    union {
        int state_1;
        const char *state_2;
        double state_3;
    } data;
} OurTaggedUnion;
```

What's even worse is that this approach is unsafe, meaning that we can construct invalid `OurTaggedUnion` (i), or, for example, (ii) access `data.state_1` when the actual state is `OUR_TAGGED_UNION_STATE_3`:

```c
// (i)
OurTaggedUnion res1 = { .state = OUR_TAGGED_UNION_STATE_2, .data.state_1 = 123 };

// (ii)
OurTaggedUnion res2 = { .state = OUR_TAGGED_UNION_STATE_3, .data.state_3 = .99 };
some_procedure(res2.data.state_1);
```

poica solves these two problems by introducing [algebraic data types] (discussed in the next section). That's how it's accomplished with poica:

```c
SUM(
    OurTaggedUnion,
    VARIANT(MkState1 OF int)
    VARIANT(MkState2 OF const char *)
    VARIANT(MkState3 OF double)
);

// (i) Compilation failed!
OurTaggedUnion res1 = MkState2(123);

OurTaggedUnion res2 = MkState3(.99);
some_procedure(/* Impossible to pass state_1! */);
```

## Quick start

[**ADT**s (**A**lgebraic **D**ata **T**ypes)] provide a convenient approach to combine, destruct, and introspect data types. There are two main kinds of them: **sum types** and **product types**.

Simply put, a **sum type** is _either_ of `T1`, ..., `Tn`, and a **product type** is _both_ `T1`, ..., `Tn`. Another name of sum types is a [tagged union], and product types correspond to structures in C.

[Pattern matching] is checking each variant of a sum type, and, if a matched variant is an actual one, trigger some action. They are like `if` statements, but for sum types, rather than for boolean expressions.

[**ADT**s (**A**lgebraic **D**ata **T**ypes)]: https://en.wikipedia.org/wiki/Algebraic_data_type
[algebraic data types]: https://en.wikipedia.org/wiki/Algebraic_data_type

[tagged union]: https://en.wikipedia.org/wiki/Tagged_union

[Pattern matching]: https://en.wikipedia.org/wiki/Pattern_matching
[pattern matching]: https://en.wikipedia.org/wiki/Pattern_matching

### Sum types

For example, a [binary tree] like this:

[binary tree]: https://en.wikipedia.org/wiki/Binary_tree

<div align="center">
  <img src="https://i.imgur.com/ng8FdNI.png" />
</div>

Can be conveniently represented and further manipulated using a sum type. In the code below we first construct this binary tree, and then print all its elements to `stdout`:

[[`examples/binary_tree.c`](examples/binary_tree.c)]
```c
#include <poica.h>

#include <stdio.h>

SUM(
    Tree,
    VARIANT(MkEmpty)
    VARIANT(MkLeaf OF int)
    VARIANT(MkNode OF MANY
        FIELD(left OF struct Tree *)
        FIELD(number OF int)
        FIELD(right OF struct Tree *)
    )
);

void print_tree(const Tree *tree) {
    MATCH(tree) {
        CASE(MkEmpty) {
            return;
        }
        CASE(MkLeaf, number) {
            printf("%d\n", *number);
        }
        CASE(MkNode, MANY(left, number, right)) {
            print_tree(*left);
            printf("%d\n", *number);
            print_tree(*right);
        }
    }
}

#define TREE(tree)                OBJ(tree OF Tree)
#define NODE(left, number, right) TREE(MkNode(left, number, right))
#define LEAF(number)              TREE(MkLeaf(number))

int main(void) {
    const Tree *tree =
        NODE(NODE(LEAF(81), 456, NODE(LEAF(90), 7, LEAF(111))), 57, LEAF(123));

    print_tree(tree);
}

#undef TREE
#undef NODE
#undef LEAF
```

<details>
    <summary>Output</summary>

```
81
456
90
7
111
57
123
```

</details>

### Product types

If we have structures in C, why we need product types? Well, because product types provide some extra features, such as type introspection (discussed in the next section) and fields extraction.

As example, consider [Heron's formula]:

[Heron's formula]: https://en.wikipedia.org/wiki/Heron's_formula

<div align="center">
  <img src="https://i.imgur.com/OuXtE5c.png" width="500px" />
</div>

This can be mapped to the actual code as follows:

[[`examples/heron_formula.c`](examples/heron_formula.c)]
```c
#include <math.h>
#include <stdio.h>

#include <poica.h>

PRODUCT(
    Triangle,
    FIELD(a OF double)
    FIELD(b OF double)
    FIELD(c OF double)
);

double compute_area(Triangle triangle) {
    EXTRACT((a, b, c) FROM (&triangle OF Triangle));

    const double p = (a + b + c) / 2;
    const double area = sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}

int main(void) {
    Triangle triangle = {4, 13, 15};
    printf("%f\n", compute_area(triangle));
}

```

<details>
    <summary>Output</summary>

```
24.000000
```

</details>

`EXTRACT` just creates new variables of the appropriate types and assigns them values from `triangle`. Compare the above code to this version of `compute_area`:

```c
double compute_area(Triangle triangle) {
    const double p = (triangle.a + triangle.b + triangle.c) / 2;
    const double area = sqrt(p * (p - triangle.a) * (p - triangle.b) * (p - triangle.c));

    return area;
}
```

This is how fields extraction can make our code a bit cleaner. In general, fields extraction is preffered when there's a lot of repeating access to fields of a single variable, and it's obvious to what variable the fields correspond.

## Type introspection

[Type introspection] is supported in the sence that you can query the type properties of ADTs at compile-time and then handle them somehow in your hand-written macros.

Here are what product and sum types return when they are introspected:

[Type introspection]: https://en.wikipedia.org/wiki/Introspection_(computer_science)
[type introspection]: https://en.wikipedia.org/wiki/Introspection_(computer_science)

[[`examples/introspection/product.c`](examples/introspection/product.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_PRODUCT                                                             \
    Something,                                                                 \
    FIELD(a OF int)                                                            \
    FIELD(b OF const char *)                                                   \
    FIELD(c OF double)                                                         \

PRODUCT(MY_PRODUCT);
#define Something_INTROSPECT PRODUCT_INTROSPECT(MY_PRODUCT)

int main(void) {
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}
```

<details>
    <summary>Output</summary>

```
((a)(int)) ((b)(const char *)) ((c)(double))
```

</details>

[[`examples/introspection/sum.c`](examples/introspection/sum.c)]
```c
#include <poica.h>

#include <stdio.h>

#include <boost/preprocessor.hpp>

#define MY_SUM                                                             \
    Something,                                                             \
    VARIANT(MkA)                                                           \
    VARIANT(MkB OF int)                                                    \
    VARIANT(MkC OF MANY FIELD(c1 OF double) FIELD(c2 OF char))             \

SUM(MY_SUM);
#define Something_INTROSPECT SUM_INTROSPECT(MY_SUM)

int main(void) {
    puts(BOOST_PP_STRINGIZE(Something_INTROSPECT));
}

```

<details>
    <summary>Output</summary>

```
((POICA_VARIANT_EMPTY)(MkA))
((POICA_VARIANT_SINGLE)(MkB)(int))
((POICA_VARIANT_MANY)(MkC)( ((c1)(double)) ((c2)(char)) ))
```

</details>

That is, the metainformation about types is actually a [sequence] in the terms of [Boost/Preprocessor]. So the [`BOOST_PP_SEQ_*` macros] can be used further, as well as [other utility macros](https://github.com/hirrolot/poica/wiki/Specification) from poica.

[sequence]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/data/sequences.html
[Boost/Preprocessor]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/
[`BOOST_PP_SEQ_*` macros]: https://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/headers/seq.html

## Contributing

Read [wiki/Contributing](https://github.com/hirrolot/poica/wiki/Contributing).

## FAQ

### What "poica" means?
"poica" is a [Quenya] word, which means clean, pure. It reflects its API.


[Quenya]: https://www.ambar-eldaron.com/telechargements/quenya-engl-A4.pdf

### Are these macros zero-cost?

poica has no runtime and performs no system calls, the macros expand to plain C code. Here are the disassembled versions of the examples:

| Example | Link |
|--------|-------|
| `ast.c` | https://godbolt.org/z/BHQEog |
| `binary_tree.c` | https://godbolt.org/z/5XKjVu |
