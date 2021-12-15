#include <stdio.h>


int main (void) {

    int user_input;
    printf("Please enter an integer between 0-99: ");
    scanf("%d", &user_input);

    if (user_input < 0 || user_input >= 100) {
        printf("Input out of valid range.\n");
        return 1;
    }

    int tens = user_input / 10;
    int singles = user_input % 10;

    printf("You entered the number: ");

    switch (tens) {
        case 2: printf("twenty");
                break;
        case 3: printf("thirty");
                break;
        case 4: printf("fourty");
                break;
        case 5: printf("fifty");
                break;
        case 6: printf("sixty");
                break;
        case 7: printf("seventy");
                break;
        case 8: printf("eighty");
                break;
        case 9: printf("ninety");
                break;
    }

    if (tens >= 2 && singles != 0) {
        printf("-");
    }

    switch (singles) {
        case 0: if (tens == 0) {
                    printf("zero");
                }
                if (tens == 1) {
                    printf("ten");
                }
                break;
        case 1: if (tens == 1) {
                    printf("eleven");
                } else {
                    printf("one");
                }
                break;
        case 2: if (tens == 1) {
                    printf("twelve");
                } else {
                    printf("two");
                }
                break;
        case 3: if (tens == 1) {
                    printf("thirteen");
                } else {
                    printf("three");
                }
                break;
        case 4: if (tens == 1) {
                    printf("fourteen");
                } else {
                    printf("four");
                }
                break;
        case 5: if (tens == 1) {
                    printf("fifteen");
                } else {
                    printf("five");
                }
                break;
        case 6: if (tens == 1) {
                    printf("sixteen");
                } else {
                    printf("six");
                }
                break;
        case 7: if (tens == 1) {
                    printf("seventeen");
                } else {
                    printf("seven");
                }
                break;
        case 8: if (tens == 1) {
                    printf("eighteen");
                } else {
                    printf("eight");
                }
                break;
        case 9: if (tens == 1) {
                    printf("nineteen");
                } else {
                    printf("nine");
                }
                break;
    }

    printf("\n");

    return 0;


}
