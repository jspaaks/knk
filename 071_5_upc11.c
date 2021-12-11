#include <stdio.h>


int main (void) {

    int item_type;
    int manufacturer_id;
    int product_id;
    int check_digit_read;

    int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11;

    printf("Please enter the 12-digit UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i0, &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11);

    item_type = i0;
    manufacturer_id = 10000 * i1 + 1000 * i2 + 100 * i3 + 10 * i4 + 1 * i5;
    product_id =      10000 * i6 + 1000 * i7 + 100 * i8 + 10 * i9 + 1 * i10;
    check_digit_read = i11;

    printf("item type             : %d\n", item_type);
    printf("manufacturer id       : %d\n", manufacturer_id);
    printf("product id            : %d\n", product_id);
    printf("check digit (read)    : %d\n", check_digit_read);

    int sum0 = i0 + i2 + i4 + i6 + i8 + i10;
    int sum1 = i1 + i3 + i5 + i7 + i9;
    int check_digit_computed = 9 - (sum0 * 3 + sum1 - 1) % 10;

    printf("check digit (computed): %d\n", check_digit_computed);

    return 0;

}
