#include <stdio.h>
#include <stdbool.h>


int main (void) {

    printf("Enter an expression: ");

    float total = 0.0f;
    scanf(" %f", &total);

    while (true) {

        // this loop iterates over the operands

        char oper;
        int c;

        while (true) {

            // this loop deals with characters preceding the next term

            c = getchar();

            if (c == '\n') {
                break;
            } else if (c == ' ') {
                continue;
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                oper = c;
                break;
            } else {
                printf("Unexpected operator %c, Aborting.\n", c);
                return 1;
            }
        }

        if (c == '\n') {
            printf("Value of the expression: %f\n", total);
            break;
        }

        float number;
        scanf(" %f", &number);

        if (oper == '+') {
            total += number;
        } else if (oper == '-') {
            total -= number;
        } else if (oper == '*') {
            total *= number;
        } else if (oper == '/') {
            total /= number;
        } else {
            printf("Unimplemented operator behavior, aborting.\n");
            return 1;
        }

    }

    return 0;

}
