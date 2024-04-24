#include <stdio.h>
#include <stdlib.h>


int main (void) {

    int user_input;
    printf("Please enter an integer between 0-99: ");
    scanf("%d", &user_input);

    if (user_input < 0 || user_input >= 100) {
        printf("Input out of valid range.\n");
        return EXIT_SUCCESS;
    }

    char *names[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };
    printf("You entered the number: ");
    if (user_input <= 20) {
        printf("%s\n", names[user_input]);
    } else {
        int tens = user_input / 10;
        int singles = user_input % 10;

        printf("%s", names[18 + tens]);
        if (singles != 0) {
            printf("-%s", names[singles]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
