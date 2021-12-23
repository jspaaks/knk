#include <stdio.h>
#include <stdbool.h>


void create_magic_square(int n, char magic_square[n][n]);
void initialize_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);


void create_magic_square(int n, char magic_square[n][n]) {

    int nrows = n;
    int ncols = n;

    int irow = 0;
    int icol = ncols / 2;

    for (int i = 1; i <= nrows * ncols; i++) {

        magic_square[irow][icol] = i;
        irow = (irow - 1 + nrows) % nrows;
        icol = (icol + 1) % ncols;

        bool occupied = magic_square[irow][icol] != 0;

        if (occupied == true) {
            icol = (icol - 1 + ncols) % ncols;
            irow = (irow + 2) % nrows;
        }
    }
    return;
}


void initialize_magic_square(int n, char magic_square[n][n]) {

    // initialize all elements of the array with 0
    int nrows = n;
    int ncols = n;
    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < ncols; icol++) {
            magic_square[irow][icol] = 0;
        }
    }

    return;
}


int main (void) {


    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    int n;
    scanf(" %d", &n);

    if (n < 1 || n > 99) {
        printf("Size should be between 1 and 99 inclusive.\n");
        return 1;
    }
    if (n % 2 != 1) {
        printf("Size should be an odd number.\n");
        return 1;
    }


    char numbers[n][n];

    initialize_magic_square(n, numbers);

    create_magic_square(n, numbers);

    print_magic_square(n, numbers);

    return 0;

}


void print_magic_square(int n, char magic_square[n][n]) {

    int nrows = n;
    int ncols = n;

    // print the first diagonal sum
    for (int icol = 0; icol < ncols; icol++) {
        printf("       ");
    }
    int diagsum0 = 0;
    for (int i = 0; i < nrows; i++) {
        diagsum0 += magic_square[nrows - 1 - i][i];
    }
    printf(" %6d \n", diagsum0);
    for (int icol = 0; icol < ncols; icol++) {
        printf("------ ");
    }
    printf("\n");

    // print the magic square and the row sums
    for (int irow = 0; irow < nrows; irow++) {
        int rowsum = 0;
        for (int icol = 0; icol < ncols; icol++) {
            int number = magic_square[irow][icol];
            printf("%6d ", number);
            rowsum += number;
        }
        printf("|%6d\n", rowsum);
    }

    // print the column sums underneath the magic square
    for (int icol = 0; icol < ncols; icol++) {
        printf("------ ");
    }
    printf("\n");
    for (int icol = 0; icol < ncols; icol++) {
        int colsum = 0;
        for (int irow = 0; irow < nrows; irow++) {
            colsum += magic_square[irow][icol];
        }
        printf("%6d ", colsum);
    }

    // print the second diagonal sum
    int diagsum1 = 0;
    for (int i = 0; i < nrows; i++) {
        diagsum1 += magic_square[i][i];
    }
    printf(" %6d \n", diagsum1);

    return;

}
