#include <stdio.h>


int main (void) {

    int i00;
    int i01;
    int i02;
    int i03;

    int i10;
    int i11;
    int i12;
    int i13;

    int i20;
    int i21;
    int i22;
    int i23;

    int i30;
    int i31;
    int i32;
    int i33;

    printf("Please enter the integer numbers 1-16 in random order separated by spaces:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &i00, &i01, &i02, &i03,
            &i10, &i11, &i12, &i13,
            &i20, &i21, &i22, &i23,
            &i30, &i31, &i32, &i33);

    int colsum0 = i00 + i01 + i02 + i03;
    int colsum1 = i10 + i11 + i12 + i13;
    int colsum2 = i20 + i21 + i22 + i23;
    int colsum3 = i30 + i31 + i32 + i33;

    int rowsum0 = i00 + i10 + i20 + i30;
    int rowsum1 = i01 + i11 + i21 + i31;
    int rowsum2 = i02 + i12 + i22 + i32;
    int rowsum3 = i03 + i13 + i23 + i33;

    int diagsum0 = i00 + i11 + i22 + i33;
    int diagsum1 = i03 + i12 + i21 + i30;

    printf("\nLet's see if entering the numbers in that order makes a magic square:\n\n");
    printf("   %2d %2d %2d %2d | %2d\n", i00, i01, i02, i03, colsum0);
    printf("   %2d %2d %2d %2d | %2d\n", i10, i11, i12, i13, colsum1);
    printf("   %2d %2d %2d %2d | %2d\n", i20, i21, i22, i23, colsum2);
    printf("   %2d %2d %2d %2d | %2d\n", i30, i31, i32, i33, colsum3);

    printf("   -- -- -- --\n");
    printf("%2d %2d %2d %2d %2d   %2d\n", diagsum1, rowsum0, rowsum1, rowsum2, rowsum3, diagsum0);

    return 0;

}
