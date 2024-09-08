#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE *);

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s STR\n"
            "    Compare two methods of determining whether string STR is one\n"
            "    of 'foo', 'bar', 'baz' or not.\n",
            exename);
}

int main (int argc, char * argv[]) {

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    if (strncmp(argv[1], "--help", 5) == 0 || strncmp(argv[1], "-h", 3) == 0) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    char * str = argv[1];

    bool cond1 = strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0 || strcmp(str, "baz") == 0;

    bool cond2 = strstr("foo bar baz", str) != nullptr;

    fprintf(stdout, "According to method 1, '%s' is%sone of 'foo', 'bar', 'baz'.\n", str, cond1 ? " " : " not ");
    fprintf(stdout, "According to method 2, '%s' is%sone of 'foo', 'bar', 'baz'.\n", str, cond2 ? " " : " not ");
    fprintf(stdout, "Methods are%sequivalent.\n", cond1 == cond2 ? " " : " not ");

    return cond1 == cond2 ? EXIT_SUCCESS : EXIT_FAILURE;
}
