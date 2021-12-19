#include <stdio.h>


#define NROWS 5
#define NCOLS 5

int main (void) {

    int numbers[NROWS][NCOLS];
    int nrows = NROWS;
    int ncols = NCOLS;

    // prompt user for input and collect the numbers
    for (int irow = 0; irow < nrows; irow++) {
        printf("Enter row %d: ", irow + 1);
        for (int icol = 0; icol < ncols; icol++) {
             scanf("%d", &numbers[irow][icol]);
        }
    }

    // calculate row sums
    int rowsums[NROWS];
    printf("Row totals: ");
    for (int irow = 0; irow < nrows; irow++) {
        rowsums[irow] = 0;
        for (int icol = 0; icol < ncols ; icol++) {
            rowsums[irow] += numbers[irow][icol];
        }
    }

    // print the row sums
    for (int irow = 0; irow < nrows; irow++) {
        printf("%d ", rowsums[irow]);
    }
    printf("\n");

    // calculate col sums
    int colsums[NCOLS];
    printf("Column totals: ");
    for (int icol = 0; icol < ncols ; icol++) {
        colsums[icol] = 0;
        for (int irow = 0; irow < nrows; irow++) {
            colsums[icol] += numbers[irow][icol];
        }
    }

    // print the col sums
    for (int icol = 0; icol < ncols; icol++) {
        printf("%d ", colsums[icol]);
    }
    printf("\n");

    return 0;

}
