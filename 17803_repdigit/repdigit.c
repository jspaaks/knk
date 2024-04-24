#include <stdio.h>
#include <stdbool.h>

int main (void) {

    int count[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    int ndigits = (int) sizeof (count) / sizeof(count[0]);

    int inumber = 0;

    do {

        if (inumber == 0) {
            printf("Enter a number (0 to abort): ");
        } else {
            printf("Enter another number (0 to abort): ");
        }

        long user_input;

        scanf("%ld", &user_input);

        if (user_input == 0) {
            break;
        }

        long remaining = user_input;

        while (remaining > 0) {

            int digit = remaining % 10;

            count[digit]++;

            remaining = remaining / 10;
        }

        inumber += 1;

    } while (true);

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

