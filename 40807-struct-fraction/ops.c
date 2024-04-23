#include "fraction.h"
#include "gcd.h"
#include "ops.h"


struct fraction add (struct fraction f1, struct fraction f2) {
    int y = f1.denominator * f2.denominator;
    int x = f1.enumerator * f2.denominator + f1.denominator * f2.enumerator;
    struct fraction f = create(x, y);
    return reduce(f);
}


struct fraction create(int enumerator, int denominator) {
    struct fraction f = {.enumerator = enumerator, .denominator = denominator};
    return f;
}


struct fraction divide (struct fraction f1, struct fraction f2) {
    int x = f1.enumerator * f2.denominator;
    int y = f1.denominator * f2.enumerator;
    struct fraction f3 = create(x, y);
    return reduce(f3);
}


struct fraction multiply (struct fraction f1, struct fraction f2) {
    int x = f1.enumerator * f2.enumerator;
    int y = f1.denominator * f2.denominator;
    struct fraction f = create(x, y);
    return reduce(f);
}


struct fraction reduce (struct fraction f) {
    int x = gcd(f);
    return create(f.enumerator / x, f.denominator / x);
}


struct fraction subtract (struct fraction f1, struct fraction f2) {
    int y = f1.denominator * f2.denominator;
    int x = f1.enumerator * f2.denominator - f1.denominator * f2.enumerator;
    struct fraction f = create(x, y);
    return reduce(f);
}
