#include <stdio.h>

int main (void) {

    int enum0;
    int denom0;
    int enum1;
    int denom1;

    char operator0;
    int enum2;
    int denom2;

    printf("Add / subtract / divide / multiply two fractional numbers: ");
    scanf(" %d / %d %1c %d / %d", &enum0, &denom0, &operator0, &enum1, &denom1);

    if (operator0 == '+') {

        enum2 = enum0 * denom1 + enum1 * denom0;
        denom2 = denom0 * denom1;

        printf("The result of the addition is: %d/%d\n", enum2, denom2);

    } else if (operator0 == '-') {

        enum2 = enum0 * denom1 - enum1 * denom0;
        denom2 = denom0 * denom1;

        printf("The result of the subtraction is: %d/%d\n", enum2, denom2);

    } else if (operator0 == '*') {

        enum2 = enum0 * enum1;
        denom2 = denom0 * denom1;

        printf("The result of the multiplication is: %d/%d\n", enum2, denom2);

    } else if (operator0 == '/') {

        enum2 = enum0 * denom1;
        denom2 = denom0 * enum1;

        printf("The result of the division is: %d/%d\n", enum2, denom2);

    } else {
        printf("Unknown operator. Aborting.\n");
        return 1;
    }

    return 0;

}
