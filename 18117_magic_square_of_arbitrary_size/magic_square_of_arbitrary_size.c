#include <stdio.h>
#include <stdbool.h>


int main (void) {


    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    int nrows;
    scanf(" %d", &nrows);

    if (nrows < 1 || nrows > 99) {
        printf("Size should be between 1 and 99 inclusive.\n");
        return 1;
    }
    if (nrows % 2 != 1) {
        printf("Size should be an odd number.\n");
        return 1;
    }


    // initialize all elements of the array with 0
    int ncols = nrows;
    int numbers[nrows][ncols];
    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < ncols; icol++) {
            numbers[irow][icol] = 0;
        }
    }


    // magic squares of size n contains all numbers 1 - n*n exactly once
    int irow = 0;
    int icol = ncols / 2;
    for (int i = 1; i <= nrows * ncols; i++) {
        numbers[irow][icol] = i;
        irow = (irow - 1 + nrows) % nrows;
        icol = (icol + 1) % ncols;
        bool occupied = numbers[irow][icol] != 0;
        if (occupied == true) {
            icol = (icol - 1 + ncols) % ncols;
            irow = (irow + 2) % nrows;
        }
    }

    // print the first diagonal sum
    for (int icol = 0; icol < ncols; icol++) {
        printf("       ");
    }
    int diagsum0 = 0;
    for (int i = 0; i < nrows; i++) {
        diagsum0 += numbers[nrows - 1 - i][i];
    }
    printf(" %6d \n", diagsum0);
    for (int icol = 0; icol < ncols; icol++) {
        printf("------ ");
    }
    printf("\n");

    // print the magic square and the row
    for (int irow = 0; irow < nrows; irow++) {
        int rowsum = 0;
        for (int icol = 0; icol < ncols; icol++) {
            int number = numbers[irow][icol];
            printf("%6d ", number);
            rowsum += number;
        }
        printf("|%6d\n", rowsum);
    }

    // print the column sums underneath the magix square
    for (int icol = 0; icol < ncols; icol++) {
        printf("------ ");
    }
    printf("\n");
    for (int icol = 0; icol < ncols; icol++) {
        int colsum = 0;
        for (int irow = 0; irow < nrows; irow++) {
            colsum += numbers[irow][icol];
        }
        printf("%6d ", colsum);
    }

    // print the second diagonal sum
    int diagsum1 = 0;
    for (int i = 0; i < nrows; i++) {
        diagsum1 += numbers[i][i];
    }
    printf(" %6d \n", diagsum1);



    return 0;

}
