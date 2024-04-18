#include <stdio.h>


int main (void) {

    int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12;

    printf("Please enter the 13-digit EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i0, &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);

    int check_digit_read = i12;

    printf("check digit (read)    : %d\n", check_digit_read);

    int sum0 = i1 + i3 + i5 + i7 + i9 + i11;
    int sum1 = i0 + i2 + i4 + i6 + i8 + i10;
    int check_digit_computed = 9 - (sum0 * 3 + sum1 - 1) % 10;

    printf("check digit (computed): %d\n", check_digit_computed);

    return 0;

}
