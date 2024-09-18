#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);
struct tm prompt_for_date (bool);

struct tm prompt_for_date (bool isfirst) {
    fprintf(stdout, "Please enter the %s date (DD-MM-YYYY): ", isfirst ? "first" : "second");
    constexpr size_t cap = 100;
    char buf[cap];
    char * status = fgets(&buf[0], cap, stdin);
    if (status == nullptr) {
        fprintf(stderr, "Error reading from STDIN, aborting.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int iday;
    unsigned int imonth;
    unsigned int iyear;
    int nread = sscanf(&buf[0], "%02u-%02u-%4u", &iday, &imonth, &iyear);
    if (nread != 3 || imonth > 12 || iday < 1 || iday > 31) {
        fprintf(stderr, "Error parsing date, aborting.\n");
        exit(EXIT_FAILURE);
    }
    return (struct tm){
        .tm_mon = imonth - 1,
        .tm_mday = iday,
        .tm_year = iyear - 1900,
    };
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

    struct tm from = prompt_for_date(true);
    struct tm to = prompt_for_date(false);

    constexpr size_t cap0 = 100;
    char buf0[cap0];
    strftime(&buf0[0], cap0, "%d-%m-%Y", &from);
    constexpr size_t cap1 = 100;
    char buf1[cap1];
    strftime(&buf1[0], cap1, "%d-%m-%Y", &to);

    time_t t0 = mktime(&from);
    time_t t1 = mktime(&to);

    double diff = difftime(t1, t0);

    fprintf(stdout, "%s and %s have %d days separation.\n", &buf0[0], &buf1[0], (int) (diff / 3600 / 24));

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "datediff";
    fprintf(stream,
            "Usage: %s\n"
            "    Prompts the user to enter two dates and returns the\n"
            "    number of dates between them.\n",
            exename);
}
