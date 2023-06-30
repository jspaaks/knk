#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

double compute_average_word_length(const char *sentence) {
    double total_word_length = 0.0;
    int nwords = 0;
    const char *start = sentence;
    const char *end = sentence;
    while (!isalpha(*end)) {
        start++;
        end++;
    }
    while (*end != '\0') {
        while (isalpha(*end)) {
            end++;
        }
        total_word_length += end - start;
        nwords += 1;
        start = end;
        while (!isalpha(*end) && *end != '\0') {
            start++;
            end++;
        }
    }
    return total_word_length / nwords;
}


int main (void) {
    printf("Enter a sentence: \n");
    char sentence[1000] = "";
    char *p = sentence;
    while (true) {
        char c = getchar();
        if (c == '\n') {
            break;
        }
        *p = c;
        p++;
    }
    double avg_word_length = compute_average_word_length(sentence);
    printf("Average word length: %.1f\n", avg_word_length);
    return EXIT_SUCCESS;
}
