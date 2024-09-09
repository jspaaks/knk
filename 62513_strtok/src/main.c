#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int count_words (char *);
void show_usage (FILE * stream);

unsigned int count_words (char * sentence) {
    char * delim = " \t\n";
    char * token = nullptr;
    unsigned int nwords = 0;
    token = strtok(sentence, delim);
    while (token != nullptr) {
        nwords++;
        token = strtok(nullptr, delim);
    }
    return nwords;
}

void show_usage (FILE * stream) {
    char * exename = "countwords";
    fprintf(stream,
            "Usage: %s\n"
            "    Read a sentence from STDIN and count the words in it.\n",
            exename);
}

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    constexpr size_t cap = 4096;
    char sentence[cap] = {};
    fgets(sentence, cap, stdin);

    fprintf(stdout, "Sentence: '%s'.\n", sentence);
    unsigned int nwords = count_words(sentence);
    fprintf(stdout, "Counted %u words.\n", nwords);

    return EXIT_SUCCESS;
}
