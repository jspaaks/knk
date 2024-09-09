#include <ctype.h>
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

    constexpr size_t cap = 4096;
    char buf[cap] = {};
    char * status;
    char * delim = " ";
    char * word = nullptr;
    while (true) {
        status = fgets(buf, cap, stdin);
        if (status == nullptr && ferror(stdin)) {
            fprintf(stderr, "Error reading from STDIN: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (status == nullptr && feof(stdin)) {
            break;
        }
        word = strtok(buf, delim);
        while (true) {
            fprintf(stdout, "%c", toupper(*word));
            word++;
            fprintf(stdout, "%s", word);
            word = strtok(nullptr, delim);
            if (word == nullptr) break;
            fprintf(stdout, " ");
        }
    }

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "capitalize";
    fprintf(stream,
            "Usage: %s\n"
            "    Copy STDIN to STDOUT while capitalizing each word.\n",
            exename);
}
