#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int letter_to_value(char letter) {
    char *data[] = {
        "",
        "AEILNORSTU",
        "DG",
        "BCMP",
        "FHVWY",
        "K",
        "",
        "",
        "JX",
        "",
        "QZ"
    };
    for (int i = 0; i <= 10; i++) {
        char *p = data[i];
        while (*p != '\0') {
            if (toupper(letter) == *p) {
                return i;
            }
            p++;
        }
    }
    printf("Encountered an unknown character '%c'.\n", letter);
    return 0;
}

int compute_scrabble_value(const char *word) {
    int points = 0;
    const char *p = word;
    while (*p != '\0') {
        points += letter_to_value(*p);
        p++;
    }
    return points;
}


int main (void) {
    char word[40] = "";
    char *p = word;
    printf("Enter a word: ");
    while (true) {
        char c = (char)(getchar());
        if (c == '\n') {
            break;
        }
        *p = c;
        p++;
    }
    int points = compute_scrabble_value(word);
    printf("Scrabble value of word '%s' is %d\n", word, points);
    return EXIT_SUCCESS;
}
