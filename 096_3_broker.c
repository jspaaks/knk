#include <stdio.h>

int main (void) {

    int nshares;
    float price_per_share;

    printf("Please enter the unit price per share: $");
    scanf("%f", &price_per_share);

    printf("Please enter how many shares are included in this transaction: ");
    scanf("%d", &nshares);

    float transaction_size = nshares * price_per_share;
    float commission0;

    if (transaction_size < 2500.00f) {
        commission0 = 30.00f + 0.017f * transaction_size;
    } else if (transaction_size < 6250.00f) {
        commission0 = 56.00f + 0.0066f * transaction_size;
    } else if (transaction_size < 20000.00f) {
        commission0 = 76.00f + 0.0034f * transaction_size;
    } else if (transaction_size < 50000.00f) {
        commission0 = 100.00f + 0.0022f * transaction_size;
    } else if (transaction_size < 500000.00f) {
        commission0 = 155.00f + 0.0011f * transaction_size;
    } else {
        commission0 = 255.00f + 0.0009f * transaction_size;
    }

    float minimal_commission = 39.00f;


    printf("Number of shares: %d\n", nshares);
    printf("Unit price: $%.2f\n", price_per_share);
    printf("Value of the trade: $%.2f\n", transaction_size);
    printf("Commission broker 1: $%.2f\n", commission0 < minimal_commission ? minimal_commission : commission0);


   float commission1;

    if (nshares < 2000) {
        commission1 = 33.00f + 0.03f * nshares;
    } else {
        commission1 = 33.00f + 0.02f * nshares;
    }

    printf("Commission broker 2: $%.2f\n", commission1);

    return 0;

}
