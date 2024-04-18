#include <stdio.h>
#include <stdbool.h>


int main (void) {

    int n;

    printf("This program prints the squares of even integers from 1 to a positive integer n.\n");
    printf("Enter a value for n: ");
    scanf(" %d", &n);

    int i = 1;
    int square;

    while (true) {

        square = i * i;

        if (square > n) {
            break;
        }

        if (i % 2 == 0) {
            printf("%d\n", square);
        }

        i += 1;
    }

    printf("Done.\n");

    return 0;

}
