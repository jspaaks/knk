#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

const int nletters = 26;


void read_word(int counts[nletters]);
bool equal_array(int counts1[nletters], int counts2[nletters]);


bool equal_array(int counts1[nletters], int counts2[nletters]) {

    for (int iletter = 0; iletter < nletters; iletter++) {
        if (counts1[iletter] != counts2[iletter]) {
            return false;
        }
    }
    return true;

}


int main (void) {

    int counts1[nletters];
    int counts2[nletters];
    for (int i = 0; i < nletters; i++) {
        counts1[i] = 0;
        counts2[i] = 0;
    }

    printf("Enter the first word: ");

    read_word(counts1);

    printf("Enter the second word: ");

    read_word(counts2);

    bool is_anagram = equal_array(counts1, counts2);

    if (is_anagram == true) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }


    return 0;

}


void read_word(int counts[nletters]) {

    while (true) {

        char c;

        c = getchar();
        c = tolower(c);

        if (c == '\n') {
            break;
        } else if ('a' <= c && c <= 'z') {
            counts[c - 'a'] += 1;
        } else {
            continue;
        }
    }

    return;
}
