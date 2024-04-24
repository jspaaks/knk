#include "fraction.h"
#include "gcd.h"


int gcd (struct fraction f) {
    // greatest common divisor, following explanation from p122 ex2
    int m = f.enumerator;
    int n = f.denominator;
    int rem = 0;
    while (n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
