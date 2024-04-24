#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define NROWS 10
#define NCOLS 10

void generate_random_walk(char walk[NROWS][NCOLS]);
void initialize_board(char walk[NROWS][NCOLS]);
void print_array(char walk[NROWS][NCOLS]);


void generate_random_walk(char walk[NROWS][NCOLS]) {

    // initialize the pseudorandom number generator with the current time
    srand((unsigned) time(NULL));

    int irow = rand() % NROWS;
    int icol = rand() % NCOLS;
    char ichar = 'A';
    walk[irow][icol] = ichar;
    bool canmove[4] = { false };
    int npossible;

    for (ichar = 'B'; ichar <= 'Z'; ichar++) {

        canmove[0] = irow != 0 && walk[irow - 1][icol] == '.';     // up
        canmove[1] = irow != NROWS - 1 && walk[irow + 1][icol] == '.'; // down
        canmove[2] = icol != 0 && walk[irow][icol - 1] == '.';     // left
        canmove[3] = icol != NCOLS - 1 && walk[irow][icol + 1] == '.'; // right

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

        walk[irow][icol] = ichar;

    }
}

void initialize_board(char walk[NROWS][NCOLS]) {
    for (int irow = 0; irow < NROWS; irow++) {
        for (int icol = 0; icol < NCOLS; icol++) {
            walk[irow][icol] = '.';
        }
    }
}


int main (void) {

    char board[NROWS][NCOLS];

    initialize_board(board);

    generate_random_walk(board);

    print_array(board);

    return 0;

}

void print_array(char walk[NROWS][NCOLS]) {
    // show board state

    for (int irow = 0; irow < NROWS; irow++) {
        for (int icol = 0; icol < NCOLS; icol++) {
            printf("%2c", walk[irow][icol]);
        }
        printf("\n");
    }
}
