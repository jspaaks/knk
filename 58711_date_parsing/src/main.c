#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr size_t ell = 10;
char * monthnames[12] = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December",
};

void get_data (char (*)[ell + 1]);
void print_output(uint8_t, uint8_t, uint16_t);
void print_usage (FILE *, char *);

void get_data (char (*buf)[ell + 1]) {
    char * p = &(*buf)[0];
    const char * const q = &(*buf)[ell];
    while (p < q) {
        int ch = fgetc(stdin);
        if (ch == EOF && ferror(stdin)) {
            fprintf(stderr, "Error reading from STDIN: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (ch == EOF && feof(stdin)) {
            break;
        }
        if (ch == '\n') {
            break;
        }
        *p = ch;
        p++;
    }
    *p = '\0';
}

int main (int argc, char * argv[]) {

    if (argc != 1) {
        print_usage(stderr, argv[0]);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Enter a date: ");

    char data[ell + 1];
    get_data(&data);

    uint8_t imonth;
    uint8_t iday;
    uint16_t iyear;

    {
        uint8_t nread = sscanf(&data[0], "%02hhu-%02hhu-%4hu", &imonth, &iday, &iyear);
        if (nread == 3) {
            print_output(iday, imonth, iyear);
            return EXIT_SUCCESS;
        }
    }
    {
        uint8_t nread = sscanf(&data[0], "%02hhu/%02hhu/%4hu", &imonth, &iday, &iyear);
        if (nread == 3) {
            print_output(iday, imonth, iyear);
            return EXIT_SUCCESS;
        }
    }
    print_usage(stderr, argv[0]);
    fprintf(stderr, "Error parsing input '%s' as a date.\n", &data[0]);
    return EXIT_FAILURE;
}

void print_output (uint8_t iday, uint8_t imonth, uint16_t iyear) {
    if (imonth < 1 || imonth > 12) {
        fprintf(stderr, "Out of range: month\n");
        exit(EXIT_FAILURE);
    }
    if (iday < 1 || iday > 31) {
        fprintf(stderr, "Out of range: day\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "%s %2hhu, %4hu\n", monthnames[imonth - 1], iday, iyear);
}

void print_usage (FILE * stream, char * argv0) {
    char * p = &argv0[0];
    for (; *p != '\0'; ++p) {}
    for (; p > &argv0[0] && *p != '/'; --p) {}
    char * shortexename = ++p;

    fprintf(stream,
            "Usage: %s\n"
            "    Read datestring from STDIN and display it as %%B %%d, %%Y.\n"
            "    Supported input formats are:\n"
            "      %%m-%%d-%%Y\n"
            "      %%m/%%d/%%Y\n",
            shortexename);
}
