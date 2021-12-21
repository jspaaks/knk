#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXLENGTH 100


int main (void) {

    printf("Enter the first word: ");

    char first[MAXLENGTH];
    int nchars0;

    for (int ichar = 0; ichar < MAXLENGTH; ichar++) {
        char c = getchar();
        if (c == '\n') {
            nchars0 = ichar;
            break;
        } else {
            first[ichar] = c;
        }
    }

    printf("Enter the second word: ");

    char second[MAXLENGTH];
    int nchars1;

    for (int ichar = 0; ichar < MAXLENGTH; ichar++) {
        char c = getchar();
        if (c == '\n') {
            nchars1 = ichar;
            break;
        } else {
            second[ichar] = c;
        }
    }

    bool is_anagram = true;

    // keep a tally of characters
    int counts[26] = { 0 };
    int nletters = (int) (sizeof(counts) / sizeof(counts[0]));

    // count occurrence of letters in first word (case-insensitive, ignoring characters that are not letters)
    for (int ichar = 0; ichar < nchars0; ichar++) {
        char c = first[ichar];
        if ( isalpha(c) ) {
            int iletter = tolower(c) - 'a';
            counts[iletter] += 1;
        }
    }

    // count occurrence of letters in second word (case-insensitive, ignoring characters that are not letters)
    for (int ichar = 0; ichar < nchars1; ichar++) {
        char c = second[ichar];
        if ( isalpha(c) ) {
            int iletter = tolower(c) - 'a';
            counts[iletter] -= 1;
        }
    }

    // tally should be 0 for all elements in count for the words to be considered anagrams
    for (int iletter = 0; iletter < nletters; iletter++) {
        if (counts[iletter] != 0) {
            is_anagram = false;
            break;
        }
    }

    if (is_anagram == true) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }


    return 0;

}
