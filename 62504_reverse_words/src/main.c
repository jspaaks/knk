#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Program to print words in reverse order.\n");
    fprintf(stdout, "Please enter a sequence of words separated by a single whitespace: ");
    constexpr size_t cap = 4096;
    char buf[cap] = {};
    char * words[1024] = {};
    size_t nwords = 0;

    fgets(buf, cap, stdin);

    char * delim = " \n";
    char * word = strtok(buf, delim);
    while (word != nullptr) {
        words[nwords] = word;
        word = strtok(nullptr, delim);
        nwords++;
    };

    fprintf(stdout, "Sequence has %zu words.%s\n", nwords, nwords > 0 ? " In reversed order: " : "");

    for (int i = nwords - 1; i >= 0; --i) {
        fprintf(stdout, "%s%s", words[i], i == 0 ? "\n" : " ");
    }

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "reverse";
    fprintf(stream,
            "Usage: %s\n"
            "    Prompt the user for a sequence of words, then print them in reverse order.\n",
            exename);
}
