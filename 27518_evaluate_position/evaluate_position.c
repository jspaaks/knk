#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define NRANKS 8
#define NFILES 8

int evaluate_position(char [NRANKS][NFILES]);
void print_board(char [NRANKS][NFILES]);
void print_piece(char c);

int main (void) {
    char board[NRANKS][NFILES] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        {'_', '_', '_', '_', '_', '_', '_', '_' },
        {'_', '_', '_', '_', '_', '_', '_', '_' },
        {'_', '_', '_', '_', '_', '_', '_', '_' },
        {'_', '_', '_', '_', '_', '_', '_', '_' },
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    print_board(board);
    int position = evaluate_position(board);
    wprintf(L"position: %d\n", position);
    return 0;
}

int evaluate_position(char board[NRANKS][NFILES]) {

    int position_white = 0;
    int position_black = 0;
    char *i = &board[0][0];
    char *n = &board[NRANKS - 1][NFILES - 1];
    for (; i <= n; i++) {
        if (*i == 'Q') {
            position_white += 9;
        }
        if (*i == 'q') {
            position_black += 9;
        }
        if (*i == 'R') {
            position_white += 5;
        }
        if (*i == 'r') {
            position_black += 5;
        }
        if (*i == 'B' || *i == 'N') {
            position_white += 3;
        }
        if (*i == 'b' || *i == 'n') {
            position_black += 3;
        }
        if (*i == 'P') {
            position_white += 1;
        }
        if (*i == 'p') {
            position_black += 1;
        }
    }
    return position_white - position_black;
}

void print_board(char board[NRANKS][NFILES]) {
    for (int irank = 0; irank < NRANKS; irank++ ){
        for (int ifile = 0; ifile < NFILES; ifile++ ){
            print_piece(board[irank][ifile]);
        }
        wprintf(L"\n");
    }
}

void print_piece(char c) {
    wchar_t wking = 0x2654;
    wchar_t wqueen = 0x2655;
    wchar_t wrook = 0x2656;
    wchar_t wbishop = 0x2657;
    wchar_t wknight = 0x2658;
    wchar_t wpawn = 0x2659;
    wchar_t bking = 0x265A;
    wchar_t bqueen = 0x265B;
    wchar_t brook = 0x265C;
    wchar_t bbishop = 0x265D;
    wchar_t bknight = 0x265E;
    wchar_t bpawn = 0x265F;

    char chars[] = {'K', 'Q', 'R', 'B', 'N', 'P', 'k', 'q', 'r', 'b', 'n', 'p', '_'};
    wchar_t wchars[] = {wking, wqueen, wrook, wbishop, wknight, wpawn, bking, bqueen, brook, bbishop, bknight, bpawn, 0x2610};
    int nchars = (int) (sizeof chars / sizeof chars[0]);

    for (int ichar = 0; ichar < nchars; ichar++) {
        if (c == chars[ichar]) {
            setlocale(LC_CTYPE, "");
            wprintf(L"%lc ", wchars[ichar]);
            return;
        }
    }
}
