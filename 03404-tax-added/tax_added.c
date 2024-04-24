#include <stdio.h>

int main (void) {

    float amount;
    printf("Enter a dollar amount: ");
    scanf("%f", &amount);
    printf("    With 5%% tax added: %.2f\n", 1.05 * amount);

}
