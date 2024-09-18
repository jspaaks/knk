#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);

time_t get_epoch_seconds (unsigned int);

time_t get_epoch_seconds (unsigned int iyear) {
    struct tm timedata = {
        .tm_sec = 0,
        .tm_min = 0,
        .tm_hour = 0,
        .tm_mday = 1,
        .tm_mon = 0,
        .tm_year = iyear - 1900,
        .tm_isdst = -1,
    };
    return mktime(&timedata);
}

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    char * input = argv[1];
    char * endptr = argv[1];
    int iyear = strtol(input, &endptr, 10);
    if (*input == '\0' || *endptr != '\0' || errno != 0) {
        char msg[100];
        sprintf(msg, ": %s", strerror(errno));
        fprintf(stderr, "Error parsing data '%s' into an integer%s\n", input, errno == 0 ? "." : msg);
        exit(EXIT_FAILURE);
    }
    time_t t = get_epoch_seconds(iyear);
    fprintf(stdout,
            "12:00a on January 1, %d (local time) equals\n"
            "epoch seconds  %ld\n"
            "ctime()        %s",
            iyear, t, ctime(&t));

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "yearstart";
    fprintf(stream,
            "Usage: %s YYYY\n"
            "    Return a datetime for the start of the year YYYY.\n",
            exename);
}
