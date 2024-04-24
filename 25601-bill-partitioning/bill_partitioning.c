#include <stdio.h>

void pay_amount (int dollars, int *twenties, int * tens, int *fives, int *ones);


int main (void) {

    int amount;
    int twenties;
    int tenners;
    int fivers;
    int singles;

    printf("Enter amount in dollars: ");
    scanf("%d", &amount);

    printf("amount (whole dollars): %d\n", amount);

    pay_amount(amount, &twenties, &tenners, &fivers, &singles);

    printf("number of twenties: %d\n", twenties);
    printf("number of tens    : %d\n", tenners);
    printf("number of fives   : %d\n", fivers);
    printf("number of singles : %d\n", singles);

    return 0;
}



void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones) {

    int remaining = dollars;

    *twenties = remaining / 20;

    remaining -= *twenties * 20;
    *tens = remaining / 10;

    remaining -= *tens * 10;
    *fives = remaining / 5;

    remaining -= *fives * 5;
    *ones = remaining;

    return;

}
