#include <stdio.h>
#include <stdbool.h>


int main (void) {

    printf("Enter a sentence: \n");

    char c_prev = ' ';
    float avg_word_length = 0.0f;
    int nwords = 0;
    int istart;
    int iend = 0;
    int i = 0;

    while (true) {

        char c = getchar();

        if ((c_prev != ' ' && c == ' ') ||
            (c_prev != ' ' && c == '\n')) {

            // found the end of a word
            iend = i;
            nwords = nwords + 1;
            avg_word_length = (avg_word_length * (nwords - 1) + (iend - istart)) / nwords;
            printf(" - %d\n", iend - 1);
        }

        if (c_prev == ' ' && c != ' ' && c != '\n') {
            // found the start of a word
            istart = i;
            printf("%d", istart);
        }

        c_prev = c;

        if (c == '\n') {
            printf("\\n @ %d\n", i);
            break;
        }

        i += 1;

    }

    printf("Sentence statistics\n");
    printf("words              : %d\n", nwords);
    printf("average word length: %.1f\n", avg_word_length);

    return 0;

}

