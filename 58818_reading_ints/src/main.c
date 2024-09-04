#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char * filename;
    FILE * fp;
} File;

// assume files contain fewer than ncap integers
size_t ncap = 10001;

int comparator (const void * a, const void * b) {
    int * casta = (int *) a;
    int * castb = (int *) b;
    if (*casta < *castb) {
        return -1;
    } else if (*casta == *castb) {
        return 0;
    } else {
        return 1;
    }
}

size_t read_data (File * src, int (*buf)[ncap]) {
    size_t i = 0;
    while (true) {
        int nread = fscanf(src->fp, " %d", &(*buf)[i]);
        if (nread < 1 && ferror(src->fp)) {
            fprintf(stderr, "Error reading data from file '%s': %s.\n", src->filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        } else if (nread < 1 && feof(src->fp)) {
            break;
        }
        i++;
    }
    return i;
}

void print_stats (int (*buf)[ncap], size_t nints) {
    qsort(&(*buf)[0], nints, sizeof(int), comparator);

    int minv = (*buf)[0];
    int maxv = (*buf)[nints - 1];
    int absminv = abs(minv);
    int absmaxv = abs(maxv);

    int ndigitsmaxv = ceil(log10(absmaxv)) + (maxv < 1 ? 1 : 0);
    int ndigitsminv = ceil(log10(absminv)) + (minv < 1 ? 1 : 0);
    int ndigits = ndigitsminv < ndigitsmaxv ? ndigitsmaxv : ndigitsminv;

    fprintf(stdout, "nints  : %*zu\n", ndigits, nints);
    fprintf(stdout, "minimum: %*d\n", ndigits, (*buf)[0]);
    fprintf(stdout, "maximum: %*d\n", ndigits, maxv);

    size_t imiddle = nints / 2; // integer division
    if (nints % 2 == 0) {
        // round down as per the instructions
        int median = ((*buf)[imiddle] + (*buf)[imiddle - 1]) / 2;
        fprintf(stdout, "median : %*d\n", ndigits, median);
    } else {
        fprintf(stdout, "median : %*d\n", ndigits, (*buf)[imiddle]);
    }
}

int main (int argc, char * argv[]) {

    const char exename[] = "readints";

    if (argc != 2) {
        fprintf(stderr,
                "Usage: %s FILENAME\n"
                "    Read integers from file FILENAME and show\n"
                "    summary statistics.\n",
                exename);
        exit(EXIT_FAILURE);
    }

    File src = (File){
        .filename = argv[1],
        .fp = fopen(argv[1], "r"),
    };

    int data[ncap] = {};
    size_t nints = read_data(&src, &data);
    print_stats(&data, nints);

    return EXIT_SUCCESS;
}
