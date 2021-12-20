#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define NROWS 7
#define NCOLS 12


int main (void) {

    char board[NROWS][NCOLS];
    int nrows = (int) (sizeof(board) / sizeof(board[0]));
    int ncols = (int) (sizeof(board[0]) / sizeof(board[0][0]));

    // initialization
    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < ncols; icol++) {
            board[irow][icol] = '.';
        }
    }

    // initialize the pseudorandom number generator with the current time
    srand((unsigned) time(NULL));

    int irow = rand() % NROWS;
    int icol = rand() % NCOLS;
    char ichar = 'A';
    board[irow][icol] = ichar;
    bool canmove[4] = { false };
    int npossible;

    for (ichar = 'B'; ichar <= 'Z'; ichar++) {

        canmove[0] = irow != 0 && board[irow - 1][icol] == '.';     // up
        canmove[1] = irow != nrows - 1 && board[irow + 1][icol] == '.'; // down
        canmove[2] = icol != 0 && board[irow][icol - 1] == '.';     // left
        canmove[3] = icol != ncols - 1 && board[irow][icol + 1] == '.'; // right

        npossible = 0;
        for (int i = 0; i < 4; i++) {
            if (canmove[i] == true) {
                npossible += 1;
            }
        }

        if (npossible == 0) {
            break;
        }

        int direction;
        do {
            direction = rand() % 4;
        } while (canmove[direction] == false);

        switch (direction) {
            case 0:
                // move up
                irow = irow - 1;
                break;
            case 1:
                // move down
                irow = irow + 1;
                break;
            case 2:
                // move left
                icol = icol - 1;
                break;
            case 3:
                // move right
                icol = icol + 1;
                break;
            default:
                printf("Should not happen.");
                break;
        }

        board[irow][icol] = ichar;

    }


    // show board state
    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < ncols; icol++) {
            printf("%2c", board[irow][icol]);
        }
        printf("\n");
    }

    if (npossible == 0) {
        printf("No moves left after %1c\n", ichar - 1);
    }

    return 0;

}
