#include <stdio.h>

int main (void) {

    int enum0;
    int denom0;
    int enum1;
    int denom1;

    printf("Enter two numbers as fractions separated by a plus sign:");
    scanf(" %d / %d + %d / %d", &enum0, &denom0, &enum1, &denom1);

    int enum2 = enum0 * denom1 + enum1 * denom0;
    int denom2 = denom0 * denom1;

    printf("The sum is: %d/%d\n", enum2, denom2);

    return 0;

}
