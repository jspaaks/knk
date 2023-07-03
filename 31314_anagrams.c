#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define NCHARS 100
#define NLETTERS 26

bool are_anagrams(char *first, char *second) {

    // prepare a tally of characters
    int counts[NLETTERS] = { 0 };

    // add occurrence of letters in first word
    char *p = first;
    while (*p != '\0') {
        int iletter = *p - 'a';
        counts[iletter] += 1;
        p++;
    }
    int nchars0 = p - first;

    // subtract occurrence of letters in second word
    char *q = second;
    while (*q != '\0') {
        int iletter = *q - 'a';
        counts[iletter] -= 1;
        q++;
    }
    int nchars1 = q - second;

    if (nchars0 != nchars1) {
        // unequal length, words can't be anagrams
        return false;
    }

    // tally should be 0 for all elements in count for the words to be considered anagrams
    for (int iletter = 0; iletter < NLETTERS; iletter++) {
        if (counts[iletter] != 0) {
            return false;
        }
    }
    return true;
}

int read(char word[NCHARS]) {
    char *start = word;
    char *end = word;
    while ((end - start) < NCHARS) {
        char c = getchar();
        if (c == '\n') {
            break;
        }
        if (isalpha(c)) {
            *end = tolower(c);
            end++;
        }
    }
    return end - start;
}

int main (void) {

    printf("Enter the first word: ");

    char first[NCHARS] = "";
    read(first);

    printf("Enter the second word: ");

    char second[NCHARS] = "";
    read(second);

    const char *msg_yes = "The words are anagrams.\n";
    const char *msg_no = "The words are not anagrams.\n";

    are_anagrams(first, second) ? printf("%s", msg_yes) : printf("%s", msg_no);

    return EXIT_SUCCESS;
}
