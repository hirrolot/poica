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

#include <stdio.h>

interface(Animal, iMethod(void, noise, (const void *self)));

record(Dog);
record(Cat);

void dogNoise(const void *self) {
    (void)(self);
    puts("Woof!");
}

void catNoise(const void *self) {
    (void)(self);
    puts("Meow!");
}

VTable(Animal) VTableImpl(Animal, Dog) = {dogNoise};
VTable(Animal) VTableImpl(Animal, Cat) = {catNoise};

/*
 * Output:
 * Woof!
 * Meow!
 */
int main(void) {
    Dog dog = {unit};
    Cat cat = {unit};

    P(IObj, Animal) animal;

    initIObj(animal, &dog, &VTableImpl(Animal, Dog));
    iObjCall(animal, noise);

    initIObj(animal, &cat, &VTableImpl(Animal, Cat));
    iObjCall(animal, noise);
}
