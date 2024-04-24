#include <stdio.h>
#include "fraction.h"
#include "ops.h"

#define NTESTS 3


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
