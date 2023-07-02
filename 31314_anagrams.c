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

    // subtract occurrence of letters in second word
    char *q = second;
    while (*q != '\0') {
        int iletter = *q - 'a';
        counts[iletter] -= 1;
        q++;
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
    int nchars0 = read(first);

    printf("Enter the second word: ");

    char second[NCHARS] = "";
    int nchars1 = read(second);

    bool is_anagram;
    if (nchars0 == nchars1) {
        is_anagram = are_anagrams(first, second);
    } else {
        is_anagram = false;
    }

    if (is_anagram == true) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }
    return EXIT_SUCCESS;
}
