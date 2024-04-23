#include <stdio.h>
#define NTESTS 3

struct fraction {
    int enumerator;
    int denominator;
};


struct fraction add (struct fraction, struct fraction);
struct fraction create(int enumerator, int denominator);
struct fraction divide (struct fraction, struct fraction);
int gcd (struct fraction);
struct fraction multiply (struct fraction, struct fraction);
struct fraction reduce (struct fraction);
struct fraction subtract (struct fraction, struct fraction);


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


int main (void) {
    struct fraction tests[NTESTS][2] = {
        {create(2, 4), create(5, 2)},
        {create(2, 3), create(5, 9)},
        {create(7, 5), create(2, 7)},
    };

    char operators[4] = "+-*/";
    for (char * op = &operators[0]; op < &operators[4]; op++) {
        for (int i = 0; i < NTESTS; i++) {
            struct fraction ans;
            switch (*op) {
                case '+': {
                    if (i == 0) {
                        fprintf(stdout, "---------------------\naddition\n---------------------\n");
                    }
                    ans = add(tests[i][0], tests[i][1]);
                    break;
                }
                case '-': {
                    if (i == 0) {
                        fprintf(stdout, "---------------------\nsubtraction\n------------------\n");
                    }
                    ans = subtract(tests[i][0], tests[i][1]);
                    break;
                }
                case '*': {
                    if (i == 0) {
                        fprintf(stdout, "---------------------\nmultiplication\n----------------\n");
                    }
                    ans = multiply(tests[i][0], tests[i][1]);
                    break;
                }
                case '/': {
                    if (i == 0) {
                        fprintf(stdout, "---------------------\ndivision\n---------------------\n");
                    }
                    ans = divide(tests[i][0], tests[i][1]);
                    break;
                }
                default:
                    fprintf(stderr, "An error occurred, aborting.\n");
                    return 1;
            }
            fprintf(stdout, "%d/%d %c %d/%d = %d/%d\n", tests[i][0].enumerator, tests[i][0].denominator,
                                                        *op,
                                                        tests[i][1].enumerator, tests[i][1].denominator,
                                                        ans.enumerator, ans.denominator);
        }
        fprintf(stdout, "\n");
    }
    return 0;
}
