#include <stdio.h>


int main (void) {

    printf("Enter a positive integer: ");

    int n;

    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid input, aborting.\n");
        return 1;
    }

    long double fact = 1.0f;
    long double fact_prev = 1.0f;
    for (long double i = 1.0f; i <= n; i++) {

        fact_prev = fact;
        fact = fact * i;

        printf("Factorial of %Lf: %Lf %Lg\n", i, fact, fact / i - fact_prev);
    }

    return 0;

}

// Maximum valid value of user_input with various types:
// short       :  7 (5040)
// int         : 12 (479001600)
// long        : 20 (2432902008176640000)
// long long   : compiler supports it, but result is same as long

// (not sure about the floating point results)
// float       : 34 (295232822996533287161359432338880069632.000000; inf after that; roundoff occurs earlier)
// double      : 170 (7257415615307994045399635715589591467896184117242257803405544211755693246215271577444614997868077640013184176271985826801597743247247979077995336619429980685793285768053360886112149825437081356365699043287884614002788490694530469661753007801896962563721104619242357348735986883814984039817295623520648167424.000000; inf after that; roundoff occurs earlier)
// long double : 1745 (very long number; inf after that)
