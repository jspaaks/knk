#include <stdio.h>


typedef enum {
    EMPTY_COLOR,
    BLACK,
    WHITE
} Color;

typedef enum {
    EMPTY_PIECE,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} Piece;

typedef struct {
    Color color;
    Piece piece;
} Square;

Square board[8][8] = {
    {
        {.color = BLACK, .piece = ROOK},
        {.color = BLACK, .piece = KNIGHT},
        {.color = BLACK, .piece = BISHOP},
        {.color = BLACK, .piece = QUEEN},
        {.color = BLACK, .piece = KING},
        {.color = BLACK, .piece = BISHOP},
        {.color = BLACK, .piece = KNIGHT},
        {.color = BLACK, .piece = ROOK},
    },
    {
        {.color = BLACK, .piece = PAWN},
        {.color = BLACK, .piece = PAWN},
        {.color = BLACK, .piece = PAWN},
        {.color = BLACK, .piece = PAWN},
        {.color = BLACK, .piece = PAWN},
        {.color = BLACK, .piece = PAWN},
        {.color = BLACK, .piece = PAWN},
        {.color = BLACK, .piece = PAWN},
    },
    [6] = {
        {.color = WHITE, .piece = PAWN},
        {.color = WHITE, .piece = PAWN},
        {.color = WHITE, .piece = PAWN},
        {.color = WHITE, .piece = PAWN},
        {.color = WHITE, .piece = PAWN},
        {.color = WHITE, .piece = PAWN},
        {.color = WHITE, .piece = PAWN},
        {.color = WHITE, .piece = PAWN},
    },
    {
        {.color = WHITE, .piece = ROOK},
        {.color = WHITE, .piece = KNIGHT},
        {.color = WHITE, .piece = BISHOP},
        {.color = WHITE, .piece = QUEEN},
        {.color = WHITE, .piece = KING},
        {.color = WHITE, .piece = BISHOP},
        {.color = WHITE, .piece = KNIGHT},
        {.color = WHITE, .piece = ROOK},
    }
};


int main (void) {
    char abbrs[] = "_bw_PNBRQK";
    for (int irow = 0; irow < 8; irow++) {
        for (int icol = 0; icol < 8; icol++) {
            Color c = board[irow][icol].color;
            Piece p = board[irow][icol].piece;
            fprintf(stdout, " %c%c", abbrs[c], abbrs[p + 3]);
        }
        fprintf(stdout, "\n");
    }
}
