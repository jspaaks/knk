#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main (void) {

    //                 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P,  Q, R, S, T, U, V, W, X, Y,  Z
    int values[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

    int points = 0;

    printf("Enter a word: ");

    while (true) {

        int c = getchar();

        c = toupper(c);

        if (c == '\n') {
            break;
        } else if ('A'<= c && c <= 'Z') {
            int iletter = c - 'A';
            points += values[iletter];
        } else {
            printf("Unknown character %d ('%c') encountered, aborting.\n", c, c);
            return 1;
        }

    }

    printf("Scrabble value: %d\n", points);

    return 0;

}
