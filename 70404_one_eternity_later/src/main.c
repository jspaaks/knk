#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);
int prompt_for_diff (void);
struct tm prompt_for_reference_date (void);

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
    char refnstr[cap];
    struct tm ref = {};

    struct tm refn = {};
    {
        ref = prompt_for_reference_date();
        time_t t = mktime(&ref);
        localtime_r(&t, &refn);
        strftime(refnstr, cap, "%m-%d-%Y", &refn);
    }

    char reqnstr[cap];
    struct tm req = {};
    struct tm reqn = {};
    int n;
    {
        n = prompt_for_diff();
        req = refn;
        req.tm_mday += n;
        time_t t = mktime(&req);
        localtime_r(&t, &reqn);
        strftime(reqnstr, cap, "%m-%d-%Y", &reqn);
    }

    fprintf(stdout, "'%s' is %d days after the reference date '%s'.\n", reqnstr, n, refnstr);

    return EXIT_SUCCESS;
}

struct tm prompt_for_reference_date (void) {
    const char * subject = "reference date";
    fprintf(stdout, "Please enter the %s (MM-DD-YYYY): ", subject);
    constexpr size_t cap = 100;
    char buf[cap] = {};
    char * status = fgets(&buf[0], cap, stdin);
    if (status == nullptr) {
        fprintf(stderr, "Error reading %s, aborting.\n", subject);
        exit(EXIT_FAILURE);
    }
    unsigned int imonth;
    unsigned int iday;
    unsigned int iyear;
    int nread = sscanf(&buf[0], "%02u-%02u-%4u", &imonth, &iday, &iyear);
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

int prompt_for_diff (void) {
    const char * subject = "number of days";
    fprintf(stdout, "Please enter the %s: ", subject);
    constexpr size_t cap = 100;
    char buf[cap] = {};
    char * status = fgets(&buf[0], cap, stdin);
    if (status == nullptr) {
        fprintf(stderr, "Error reading %s, aborting.\n", subject);
        exit(EXIT_FAILURE);
    }
    int n;
    sscanf(&buf[0], " %d", &n);
    return n;
}

void show_usage (FILE * stream) {
    char * exename = "dayslater";
    fprintf(stream,
            "Usage: %s\n"
            "   Prompts the user for a date (MM-DD-YYYY) and a number of days N,\n"
            "   then returns the date that is N days after the reference date.\n",
            exename);
}
