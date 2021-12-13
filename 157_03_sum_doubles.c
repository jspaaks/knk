#include <stdio.h>


int main (void) {

    double d;

    printf("This program sums a series of doubles.\n");
    printf("Enter doubles (0 to terminate):\n");
    scanf("%lf", &d);

    double sum = 0.0;

    while (d != 0.0) {

        sum += d;
        scanf("%lf", &d);

    }

    printf("The sum is: %f\n", sum);

    return 0;

}
