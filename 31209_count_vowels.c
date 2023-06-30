#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int compute_vowel_count(const char *sentence) {
    int nvowels = 0;
    const char *p;
    p = sentence;
    while (*p != '\0') {
        char c = tolower(*p);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            nvowels += 1;
        }
        p++;
    }
    return nvowels;
}


int main (void) {
    char sentence[1000] = "";
    char *p = sentence;
    printf("Enter a sentence: ");
    for (char c;(c = getchar()) != '\n'; p++) {
        *p = c;
    }
    int nvowels = compute_vowel_count(&sentence[0]);
    printf("Your sentence '%s' contains %d vowels.\n", sentence, nvowels);
    return EXIT_SUCCESS;
}
