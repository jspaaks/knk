#include <errno.h>
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

    char * prevset = ".?!";
    char * thisset = " \n";
    int ch;
    char prev;
    size_t nsentences = 0;
    bool cond1;
    bool cond2;
    const char EOT = 4;

    while (true) {
        ch = fgetc(stdin);
        if (ch == EOF && ferror(stdin)) {
            fprintf(stderr, "Error reading from STDIN: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_SUCCESS);
        }
        cond1 = strchr(prevset, prev) != nullptr;
        cond2 = strchr(thisset, ch) != nullptr || ch == EOF || ch == EOT;
        if (cond1 && cond2) {
            nsentences++;
        }
        if (ch == EOF && feof(stdin)) {
            break;
        }
        prev = ch;
    }
    fprintf(stdout, "Counted %zu sentences in text provided on STDIN.\n", nsentences);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "count";
    fprintf(stream,
            "Usage: %s\n"
            "    Read text from STDIN and print the number of sentences.\n",
            exename);
}
