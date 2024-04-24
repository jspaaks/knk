#include <stdio.h>
#include <stdbool.h>



int main (void) {

    float largest;
    float user_input;
    int i = 0;

    do {
        printf("Enter a non-negative number (0 to terminate): ");
        scanf("%f", &user_input);
        if (user_input == 0) {
            break;
        }
        if (i == 0 || user_input > largest) {
            largest = user_input;
        }
        i += 1;
    } while (true);

    printf("The largest number from the series was: %.2f\n", largest);

    return 0;

}
