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

// Error handling with ADTs. This is demonstrated on parsing the "'<full name>'
// <age>" string.

#include <poica.h>

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// clang-format off
RECORD(
    Person,
    FIELD(full_name, const char *)
    FIELD(age, unsigned char)
);

// Can be represented as an ordinary enumeration, but we define it as a sum type
// for consistency.
ENUM(
    ParseErr,
    VARIANT(MkInvalidAge)
    VARIANT(MkNoFirstApostrophe)
    VARIANT(MkNoSecondApostrophe)
);

ENUM(
    ParseRes,
    VARIANT(MkParseOk, Person)
    VARIANT(MkParseErr, ParseErr)
);
// clang-format on

void skip_emptiness(const char **src) {
    while (**src != '\0' && isblank(**src)) {
        (*src)++;
    }
}

// clang-format off
ENUM(
    ParseFullNameRes,
    VARIANT(MkParseFullNameOk)
    VARIANT(MkParseFullNameErr, ParseErr)
);
// clang-format on

ParseFullNameRes parse_full_name(Person *person, const char **src) {
    if ((person->full_name = strchr(*src, '\'')) == NULL) {
        return MkParseFullNameErr(MkNoFirstApostrophe());
    }

    person->full_name++;
    *src = (char *)person->full_name;

    return MkParseFullNameOk();
}

// clang-format off
ENUM(
    ParseAgeRes,
    VARIANT(MkParseAgeOk)
    VARIANT(MkParseAgeErr, ParseErr)
);
// clang-format on

ParseAgeRes parse_age(Person *person, char **src) {
    char *age_pos;
    if ((age_pos = strchr(*src, '\'')) == NULL) {
        return MkParseAgeErr(MkNoSecondApostrophe());
    }

    *age_pos = '\0';
    age_pos++;
    *src = age_pos;

    skip_emptiness((const char **)&age_pos);

    if (sscanf(age_pos, "%hhu", &person->age) == 0) {
        return MkParseAgeErr(MkInvalidAge());
    }

    return MkParseAgeOk();
}

ParseRes parse(char *src) {
    Person person;

    {
        ParseFullNameRes res = parse_full_name(&person, (const char **)&src);
        TRY(&res, CASE(MkParseFullNameErr, err), MkParseErr(*err));
    }

    {
        ParseAgeRes res = parse_age(&person, &src);
        TRY(&res, CASE(MkParseAgeErr, err), MkParseErr(*err));
    }

    return MkParseOk(person);
}

const char *stringify_parse_err(const ParseErr *err) {
    MATCH(err) {
        CASE(MkInvalidAge) {
            return "a range must be a nonnegative integral number";
        }
        CASE(MkNoFirstApostrophe) {
            return "no apostrophe before a full name";
        }
        CASE(MkNoSecondApostrophe) {
            return "no apostrophe after a full name";
        }
    }
}

int main(void) {
    char src[] = "'James Brown' 73";
    ParseRes res = parse(src);

    /*
     * Output:
     * Success!
     */
    MATCH(&res) {
        CASE(MkParseOk, person) {
            assert(person->age == 73);
            assert(strcmp(person->full_name, "James Brown") == 0);
            puts("Success!");
        }
        CASE(MkParseErr, err) {
            printf("Parsing has been failed! Reason: %s.\n",
                   stringify_parse_err(err));
        }
    }
}
