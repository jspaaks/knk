#include <stdio.h>

float calc_tax(float income);


float calc_tax(float income) {

    float tax;

    if (income < 750.00f) {
        tax = 0.00f + 0.01f * (income - 0.00f);
    } else if (income < 2250.00f) {
        tax = 7.50f + 0.02f * (income - 750.00f);
    } else if (income < 3750.00f) {
        tax = 37.50f + 0.03f * (income - 2250.00f);
    } else if (income < 5250.00f) {
        tax = 82.50f + 0.04f * (income - 3750.00f);
    } else if (income < 7000.00f) {
        tax = 142.50f + 0.05f * (income - 5250.00f);
    } else {
        tax = 230.00f + 0.06f * (income - 7000.00f);
    }

    return tax;

}


int main (void) {

    float income;
    printf("Please enter your income: $");
    scanf(" %f", &income);

    float tax = calc_tax(income);

    printf("Tax due: $%.2f\n", tax);

    return 0;

}
