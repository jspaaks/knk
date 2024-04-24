#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10
#define NROWS_DIGIT 4
#define NCOLS_DIGIT 4
#define NSEGMENTS 7
#define NDIGITS 10


const bool segments[NDIGITS][NSEGMENTS] = {
    {true,  true,  true,  true,  true,  true,  false},   // 0
    {false, true,  true,  false, false, false, false},   // 1
    {true,  true,  false, true,  true,  false, true},    // 2
    {true,  true,  true,  true,  false, false, true},    // 3
    {false, true,  true,  false, false, true,  true},    // 4
    {true,  false, true,  true,  false, true,  true},    // 5
    {true,  false, true,  true,  true,  true,  true},    // 6
    {true,  true,  true,  false, false, false, false},   // 7
    {true,  true,  true,  true,  true,  true,  true},    // 8
    {true,  true,  true,  true,  false, true,  true}     // 9
};
char digits[NROWS_DIGIT][MAX_DIGITS * NCOLS_DIGIT];


void clear_digits_array (void);
void process_digits (int digit, int position);
void print_digits_array (void);


void clear_digits_array (void) {

    int nrows = (int) (sizeof(digits) / sizeof(digits[0]));
    int ncols = (int) (sizeof(digits[0]) / sizeof(digits[0][0]));

    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < ncols; icol++) {
            digits[irow][icol] = ' ';
        }
    }

    return;

}


int main (void) {

    clear_digits_array();

    printf("Enter a number of up to 10 digits: ");

    for (int iposition = 0; iposition < MAX_DIGITS;) {

        char c = getchar();

        if (c == '\n') {
            break;
        } else if ('0' <= c && c <= '9') {

            process_digits(c - '0', iposition);

            iposition += 1;
        } else {
            continue;
        }
    }

    print_digits_array();

    return 0;

}


void process_digits (int digit, int position) {

    if (segments[digit][0] == true) {
        int icol = (position * NCOLS_DIGIT) + 2;
        digits[0][icol] = '_';
    }
    if (segments[digit][1] == true) {
        int icol = (position * NCOLS_DIGIT) + 3;
        digits[1][icol] = '|';
    }
    if (segments[digit][2] == true) {
        int icol = (position * NCOLS_DIGIT) + 3;
        digits[2][icol] = '|';
    }
    if (segments[digit][3] == true) {
        int icol = (position * NCOLS_DIGIT) + 2;
        digits[2][icol] = '_';
    }
    if (segments[digit][4] == true) {
        int icol = (position * NCOLS_DIGIT) + 1;
        digits[2][icol] = '|';
    }
    if (segments[digit][5] == true) {
        int icol = (position * NCOLS_DIGIT) + 1;
        digits[1][icol] = '|';
    }
    if (segments[digit][6] == true) {
        int icol = (position * NCOLS_DIGIT) + 2;
        digits[1][icol] = '_';
    }

    return;

}


void print_digits_array (void) {

    int nrows = (int) (sizeof(digits) / sizeof(digits[0]));
    int ncols = (int) (sizeof(digits[0]) / sizeof(digits[0][0]));

    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < ncols; icol++) {
            printf("%1c", digits[irow][icol]);
        }
        printf("\n");
    }

    return;

}

