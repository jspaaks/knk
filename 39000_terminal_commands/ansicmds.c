#include <stdio.h>
#include "ansicmds.h"


void clear_screen (void) {
    printf("\033[2J");
}


void move_cursor_down (int nlines) {
    printf("\033[%dB", nlines);
}


void move_cursor_left (int ncols) {
    printf("\033[%dD", ncols);
}


void move_cursor_right (int ncols) {
    printf("\033[%dC", ncols);
}


void move_cursor_up (int nlines) {
    printf("\033[%dA", nlines);
}


void move_cursor_to_pos (int irow, int icol) {
    printf("\033[%d;%dH", irow, icol);
}
