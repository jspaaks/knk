#include <stdio.h>


int main (void) {

    int i, n;

    printf("This program prints integers 1..n and their squares.\n");
    printf("Please enter an integer value for n: ");
    scanf("%d", &n);

    // remove newline from buffer
    getchar();

    for (i = 1; i <= n; i++) {
        printf("%10d %10d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n') {
                continue;
            }
        }
    }

    return 0;

}
