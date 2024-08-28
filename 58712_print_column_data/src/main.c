#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    uint32_t item;
    float price;
    uint8_t imonth;
    uint8_t iday;
    uint16_t iyear;
} Record;

constexpr size_t nrecordsmax = 1024;

char * exename (char *);
void print_records (FILE *, Record (*)[nrecordsmax], size_t);
size_t read_records (const char *, Record (*)[nrecordsmax]);

char * exename (char * path) {
    char * p = &path[0];
    for (; *p != '\0'; ++p) {}
    for (; p > &path[0] && *p != '/'; --p) {}
    return p;
}

int main (int argc, char * argv[]) {

    if (argc != 3) {
        fprintf(stderr,
                "Usage: %s [-i | --input-file] FILENAME\n"
                "\n"
                "    Read formatted product data from FILENAME and print it as columns.\n",
                exename(argv[0]));
        exit(EXIT_FAILURE);
    }
    if (strncmp(argv[1], "-i", 3) != 0 && strncmp(argv[1], "--input-file", 13) != 0) {
        fprintf(stderr, "Unexpected argument name '%s'. Aborting.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    char * filename = argv[2];
    Record records[nrecordsmax] = {};
    size_t nrecords = read_records(&filename[0], &records);
    print_records(stdout, &records, nrecords);
    return EXIT_SUCCESS;
}

void print_records (FILE * stream, Record (*records)[nrecordsmax], size_t nrecords) {
    if (nrecords == 0) {
        fprintf(stream, "Empty\n");
        return;
    }
    fprintf(stream, "Item          Unit           Purchase\n"
                    "              price          date\n");
    for (size_t i = 0; i < nrecords; ++i) {
        fprintf(stream, "%-12u  $ %6.2f       %2hhu/%2hhu/%4hu\n", (*records)[i].item, (*records)[i].price,
                (*records)[i].imonth, (*records)[i].iday, (*records)[i].iyear);
    }
}

size_t read_records (const char * filename, Record (*records)[nrecordsmax]) {
    FILE * fp = fopen(filename, "r");
    if (fp == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        return EXIT_FAILURE;
    }
    size_t nrecords = 0;
    for (size_t i = 0; i < nrecordsmax; ++i) {
        int nread = fscanf(fp, "%u,%f,%hhu/%hhu/%hu", &(*records)[i].item, &(*records)[i].price, &(*records)[i].imonth,
                           &(*records)[i].iday, &(*records)[i].iyear);
        if (nread != 5 && ferror(fp)) {
            fprintf(stderr, "Error reading data from file '%s': %s.\n", filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread != 5 && feof(fp)) {
            nrecords = i;
            break;
        }
    }
    int status = fclose(fp);
    if (status == EOF) {
        fprintf(stderr, "Error closing file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        return EXIT_FAILURE;
    }
    return nrecords;
}
