#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int countchr (const char *, const char);
void show_usage (FILE *);

void show_usage (FILE * stream) {
    char * exename = "count";
    fprintf(stream,
            "Usage: %s STR CH\n"
            "    Count the occurrences of character CH in string STR.\n",
            exename);
}

unsigned int countchr (const char * s, const char ch) {
    unsigned int ntimes = 0;
    const char * p = s;
    while (true) {
        p = strchr(p + 1, ch);
        if (p == nullptr) break;
        ntimes++;
    }
    return ntimes;
}

int main (int argc, char * argv[]) {

    if (argc != 3) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    char * s = argv[1];
    char ch = argv[2][0];

    unsigned int ntimes = countchr(s, ch);

    fprintf(stdout, "Character '%c' occurs %d times in string '%s'.\n", ch, ntimes, s);

    return EXIT_SUCCESS;
}
