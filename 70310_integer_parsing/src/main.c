#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE *);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    char * str = argv[1];

    fprintf(stdout, "INT_MAX: %d\n", INT_MAX);
    fprintf(stdout, "LONG_MAX: %ld\n", LONG_MAX);
    fprintf(stdout, "LLONG_MAX: %lld\n", LLONG_MAX);

    {
        int i = atoi(str);
        fprintf(stdout, "\"%s\" as parsed by atoi yields %d.\n", str, i);
    }

    {
        char * p = str;
        errno = 0;
        long i = strtol(str, &p, 10);
        bool cond = *p != '\0' || errno != 0;
        fprintf(stdout, "\"%s\" as parsed by strtol yields %ld %s parsing errors.\n", str, i,
                cond ? "with" : "without any");
    }

    // ---------------------------- //

    {
        long int i = atol(str);
        fprintf(stdout, "\"%s\" as parsed by atol yields %ld.\n", str, i);
    }

    {
        char * p = str;
        errno = 0;
        long i = strtol(str, &p, 10);
        bool cond = *p != '\0' || errno != 0;
        fprintf(stdout, "\"%s\" as parsed by strtol yields %ld %s parsing errors.\n", str, i,
                cond ? "with" : "without any");
    }

    // ---------------------------- //

    {
        long long int i = atoll(str);
        fprintf(stdout, "\"%s\" as parsed by atoll yields %lld.\n", str, i);
    }

    {
        char * p = str;
        errno = 0;
        long long i = strtoll(str, &p, 10);
        bool cond = *p != '\0' || errno != 0;
        fprintf(stdout, "\"%s\" as parsed by strtoll yields %lld %s parsing errors.\n", str, i,
                cond ? "with" : "without any");
    }

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s STR\n"
            "    Parse user-supplied string into integer number using various methods.\n",
            exename);
}
