#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr size_t nflightsmax = 1024;

typedef struct {
    uint8_t iminute;
    uint8_t ihour;
} TimeOfDay;

typedef struct {
    TimeOfDay arr;
    TimeOfDay dep;
} Flight;

void timeofday_to_ampm (const TimeOfDay, char (*)[9]);
char * exename (char * const);
size_t read_flights (const char *, Flight (*)[nflightsmax]);

char * exename (char * const path) {
    char * p = &path[0];
    for (; *p != '\0'; ++p) {}
    for (; p > &path[0] && *p != '/'; --p) {}
    return ++p;
}

size_t read_flights (const char * const filename, Flight (*flights)[nflightsmax]) {
    FILE * fp = fopen(filename, "r");
    if (fp == nullptr) {
        fprintf(stderr, " -- Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    size_t nflights;
    for (size_t i = 0; i < nflightsmax; ++i) {
        int nread = fscanf(fp, "%2hhu:%2hhu %2hhu:%2hhu\n", &(*flights)[i].dep.ihour, &(*flights)[i].dep.iminute,
                           &(*flights)[i].arr.ihour, &(*flights)[i].arr.iminute);
        if (nread < 4 && ferror(fp)) {
            fprintf(stderr, " -- Error reading data from file '%s': %s.\n", filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread < 4 && feof(fp)) {
            nflights = i;
            break;
        }
    }
    int status = fclose(fp);
    if (status == EOF) {
        fprintf(stderr, " -- Error closing file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    return nflights;
}

int main (int argc, char * argv[]) {

    if (argc != 2) {
        fprintf(stderr,
                "Usage: %s FILENAME\n"
                "    Recommend the best flight using formatted data from FILENAME.\n",
                exename(argv[0]));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Enter a 24-hour time: ");
    uint8_t ihours;
    uint8_t iminutes;
    char tmp[2];
    int nread = fscanf(stdin, " %2hhu:%2hhu%[^\n]", &ihours, &iminutes, &tmp[0]);
    if (nread < 2 || strlen(tmp) > 0) {
        fprintf(stderr, " -- Error reading data from STDIN. Aborting.\n");
        errno = 0;
        exit(EXIT_FAILURE);
    }
    if (ihours > 23) {
        fprintf(stderr, " -- Out of bounds: hours.\n");
        exit(EXIT_FAILURE);
    }
    if (iminutes > 59) {
        fprintf(stderr, " -- Out of bounds: minutes.\n");
        exit(EXIT_FAILURE);
    }
    uint16_t mod = 60 * ihours + iminutes;
    fprintf(stdout, " -- Requested minute of day: %hu\n", mod);

    char * filename = argv[1];
    Flight flights[nflightsmax] = {};
    size_t nflights = read_flights(filename, &flights);
    fprintf(stdout, " -- Read data of %zu flights.\n", nflights);

    uint16_t best = 24 * 60;
    size_t ibest = nflightsmax;
    for (size_t i = 0; i < nflights; ++i) {
        uint16_t this = abs((flights[i].dep.ihour * 60 + flights[i].dep.iminute) - mod);
        if (this < best) {
            ibest = i;
            best = this;
        }
    }
    {
        char dep[9] = {};
        char arr[9] = {};
        timeofday_to_ampm(flights[ibest].dep, &dep);
        timeofday_to_ampm(flights[ibest].arr, &arr);
        fprintf(stdout, " -- Closest departure time is %s, arriving at %s.\n", dep, arr);
    }
    return EXIT_SUCCESS;
}

void timeofday_to_ampm (const TimeOfDay tod, char (*buf)[9]) {
    char ampm = tod.ihour < 12 ? 'A' : 'P';
    sprintf(&(*buf)[0], "%hhu:%02hhu %cM", ((tod.ihour - 1) % 12) + 1, tod.iminute, ampm);
}
