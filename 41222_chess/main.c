#include <stdio.h>


enum chess_pieces {
    KING = 0,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
};

const int piece_values[] = {
    [KING] = 200,
    [QUEEN] = 9,
    [ROOK] = 5,
    [BISHOP] = 3,
    [KNIGHT] = 3,
    [PAWN] = 1
};

int main (void) {
    fprintf(stdout, "Chess pieces values\n");
    fprintf(stdout, "KING   = %d\n", piece_values[KING]);
    fprintf(stdout, "QUEEN  = %d\n", piece_values[QUEEN]);
    fprintf(stdout, "ROOK   = %d\n", piece_values[ROOK]);
    fprintf(stdout, "BISHOP = %d\n", piece_values[BISHOP]);
    fprintf(stdout, "KNIGHT = %d\n", piece_values[KNIGHT]);
    fprintf(stdout, "PAWN   = %d\n", piece_values[PAWN]);
}
