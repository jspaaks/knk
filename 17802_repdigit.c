#include <stdio.h>

int main (void) {

    long user_input;

    printf("Enter a number: ");
    scanf("%ld", &user_input);

    long remaining = user_input;

    int ndigits = 10;

    int count[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    while (remaining > 0) {

        int digit = remaining % 10;

        count[digit]++;

        remaining = remaining / 10;
    }

    printf("Digit      : ");

    for (int idigit = 0; idigit < ndigits; idigit++) {
        printf("%2d ", idigit);
    }

    printf("\n");

    printf("Occurrences: ");

    for (int idigit = 0; idigit < ndigits; idigit++) {
        if (count[idigit] > 0) {
            printf("%2d ", count[idigit]);
        } else {
            printf("   ");
        }
    }

    printf("\n");

    return 0;

}

