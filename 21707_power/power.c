#include <stdio.h>



int power(int x, int n);

int main (void) {

    int x;
    printf("This program raises x to the power n.\n");
    printf("Enter an integer number for x: ");
    scanf(" %d", &x);

    int n;
    printf("Enter an integer number for n: ");
    scanf(" %d", &n);

    int powered = power(x, n);

    printf("%d^%d = %d\n", x, n, powered);

    return 0;

}


int power(int x, int n) {

    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        int tmp = power(x, n/2);
        return tmp * tmp;
    } else {
        return x * power(x, n - 1);
    }

}
