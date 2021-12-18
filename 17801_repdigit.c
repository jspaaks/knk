#include <stdio.h>


int main (void) {

    long user_input;

    printf("Enter a number: ");
    scanf("%ld", &user_input);

    long remaining = user_input;

    int ndigits = 10;

    int seen[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  // 0: not seen;
                                                    // 1: seen once;
                                                    // 2: repeated.
    int nrepeated = 0;

    while (remaining > 0) {

        int digit = remaining % 10;

        if (seen[digit] == 1) {
            nrepeated += 1;
        }
        if (seen[digit] < 2) {
            seen[digit]++;
        }

        remaining = remaining / 10;
    }

    if (nrepeated > 0) {
        printf("Repeated digit(s): ");
        for (int idigit = 0; idigit < ndigits; idigit++) {
            if (seen[idigit] == 2) {
                printf("%d ", idigit);
            }
        }
    } else {
        printf("No repeated digit.\n");
    }

    printf("\n");

    return 0;

}
