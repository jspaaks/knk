#include <stdio.h>

#define NCOLS 5

int sum_two_dimensional_array(const int a[][NCOLS], int nrows);
int sum_two_dimensional_array_pointers(const int a[][NCOLS], int nrows);

int main (void) {

    int a[][NCOLS] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };
    int nrows = sizeof a / sizeof a[0];
    printf("sum is %d (indexing)\n", sum_two_dimensional_array(a, nrows));
    printf("sum is %d (pointers)\n", sum_two_dimensional_array_pointers(a, nrows));
}

int sum_two_dimensional_array(const int a[][NCOLS], int nrows) {
    int sum;
    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < NCOLS; icol++) {
            sum += a[irow][icol];
        }
    }
    return sum;
}

int sum_two_dimensional_array_pointers(const int a[][NCOLS], int nrows) {
    int sum = 0;
    for (const int *v = &a[0][0]; v <= &a[nrows - 1][NCOLS - 1]; v++) {
        sum += *v;
    }
    return sum;
}
