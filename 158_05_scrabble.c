#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main (void) {

    printf("Enter a word: ");

    int points = 0;

    while (true) {

        int c = getchar();

        c = toupper(c);

        if (c == '\n') {
            break;
        } else if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U') {
            points += 1;
        } else if (c == 'D' || c == 'G') {
            points += 2;
        } else if (c == 'B' || c == 'C' || c == 'M' || c == 'P') {
            points += 3;
        } else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y') {
            points += 4;
        } else if (c == 'K') {
            points += 5;
        } else if (c == 'J' || c == 'X') {
            points += 8;
        } else if (c == 'Q' || c == 'Z') {
            points += 10;
        } else {
            printf("Encountered an unknown character '%c'.\n", c);
            points += 0;
        }
    }

    printf("Scrabble value: %d\n", points);

    return 0;

}
