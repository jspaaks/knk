#include <stdio.h>

int main (void) {

    float loan_remaining;
    float interest_rate_yearly; // in percent
    float payment_monthly;
    float interest_monthly;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_remaining);

    printf("Enter yearly interest rate in percent: ");
    scanf("%f", &interest_rate_yearly);

    printf("Enter monthly payment: ");
    scanf("%f", &payment_monthly);

    // montly interest rate should be interest_rate_yearly ^ (1/12), but instructions say divide by 12
    float interest_rate_monthly = interest_rate_yearly / 12;

    interest_monthly = loan_remaining * interest_rate_monthly / 100;
    loan_remaining += interest_monthly - payment_monthly;
    printf("Balance remaining after 1 month : %.2f\n", loan_remaining);

    interest_monthly = loan_remaining * interest_rate_monthly / 100;
    loan_remaining += interest_monthly - payment_monthly;
    printf("Balance remaining after 2 months: %.2f\n", loan_remaining);

    interest_monthly = loan_remaining * interest_rate_monthly / 100;
    loan_remaining += interest_monthly - payment_monthly;
    printf("Balance remaining after 3 months: %.2f\n", loan_remaining);

}
