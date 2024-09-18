#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    constexpr size_t cap = 100;
    char buf[cap] = {};
    struct tm datetimeinfo = {};

    time_t epoch_seconds = 1234567890;
    localtime_r(&epoch_seconds, &datetimeinfo);

    {
        strftime(&buf[0], cap, "%Y-%j", &datetimeinfo);
        fprintf(stdout, " -- a) %s\n", buf);
    }

    {
        strftime(&buf[0], cap, "%Y-W%V-%u", &datetimeinfo);
        fprintf(stdout, " -- b) %s\n", buf);
    }

    {
        strftime(&buf[0], cap, "%Y-%m-%dT%H:%M:%S", &datetimeinfo);
        fprintf(stdout, " -- c) %s\n", buf);
    }

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "    Print time_t t = 1234567890 in various formats using strftime.\n",
            exename);
}
