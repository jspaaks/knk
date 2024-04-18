#include <stdio.h>

int main (void) {

    int amount, twenties, tenners, fivers, singles;

    printf("Enter amount in dollars: ");
    scanf("%d", &amount);

    printf("amount (whole dollars): %d\n", amount);

    twenties = amount / 20;
    printf("number of twenties: %d\n", twenties);

    amount = amount - twenties * 20;
    tenners = amount / 10;
    printf("number of tenners : %d\n", tenners);

    amount = amount - tenners * 10;
    fivers = amount / 5;
    printf("number of fivers  : %d\n", fivers);

    amount = amount - fivers * 5;
    singles = amount / 1;
    printf("number of singles : %d\n", singles);

    return 0;
}
