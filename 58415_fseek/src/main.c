#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char indent[] = "   -- ";

void write_testfile (const char * filename, const size_t ncolumns, const size_t nrecords) {
    fprintf(stdout, "   Writing test data to file '%s'...\n", filename);
    const size_t nelems = nrecords * ncolumns;
    uint8_t data[nelems] = {};
    for (size_t i = 0; i < nrecords; ++i) {
        data[i * ncolumns] = '0' + i;
    }

    FILE * fp = fopen(filename, "wb+");
    if (fp == NULL) {
        char formatstr[] = "%sSomething went wrong writing test data to file '%s': %s.\n";
        fprintf(stderr, formatstr, indent, filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    size_t size = 1;
    size_t nmemb = nelems;
    size_t written = fwrite(&data[0], size, nmemb, fp);
    if (written != nelems) {
        fprintf(stderr, "%sError writing to file '%s': %s.\n", indent, filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    fprintf(stdout, "%sDone.\n", indent);
}

void a (FILE * fp, const size_t ncolumns, const char * filename) {
    fprintf(stdout, "\na) Set cursor to the beginning of record 2 and read the first\n   byte...\n");
    int irecord = 2;
    long offset = irecord * ncolumns;
    int whence = SEEK_SET;
    uint8_t buf;
    fseek(fp, offset, whence);
    int nread = fread(&buf, 1, 1, fp);
    if (nread != 1) {
        char formatstr[] = "%sAn error occurred while reading a byte from file '%s': %s.\n";
        fprintf(stderr, formatstr, indent, filename, strerror(errno));
    }
    fprintf(stdout, "%sThe first byte of record %d is %c.\n", indent, irecord, buf);
}

void b (FILE * fp, const size_t ncolumns, const char * filename) {
    fprintf(stdout, "\nb) Set cursor to the beginning of the last record and read the\n   first byte...\n");
    long offset = -1 * ncolumns;
    int whence = SEEK_END;
    fseek(fp, offset, whence);
    uint8_t buf;
    int nread = fread(&buf, 1, 1, fp);
    if (nread != 1) {
        char formatstr[] = "%sAn error occurred while reading a byte from file '%s': %s.\n";
        fprintf(stderr, formatstr, indent, filename, strerror(errno));
    }
    fprintf(stdout, "%sThe first byte of the last record is %c.\n", indent, buf);
}

void c (FILE * fp, const size_t ncolumns, const char * filename) {

    {
        fprintf(stdout, "\nc) Set cursor to the beginning of the 5th record, move\n"
                        "   forward 1 record, and read the first byte...\n");
        int irecord = 5;
        long offset = irecord * ncolumns;
        int whence = SEEK_SET;
        fseek(fp, offset, whence);
        uint8_t buf;
        int nread = fread(&buf, 1, 1, fp);
        if (nread != 1) {
            char formatstr[] = "%sAn error occurred while reading a byte from file '%s': %s.\n";
            fprintf(stderr, formatstr, indent, filename, strerror(errno));
        }
        fprintf(stdout, "%sThe first byte of the 5th record is '%c'.\n", indent, buf);
        // rewind the cursor to the position before the fread:
        fseek(fp, -1, SEEK_CUR);
    }
    {
        long offset = 1 * ncolumns;
        int whence = SEEK_CUR;
        fseek(fp, offset, whence);
        uint8_t buf;
        int nread = fread(&buf, 1, 1, fp);
        if (nread != 1) {
            char formatstr[] = "%sAn error occurred while reading a byte from file '%s': %s.\n";
            fprintf(stderr, formatstr, indent, filename, strerror(errno));
        }
        fprintf(stdout, "%sThe first byte of the next record is '%c'.\n", indent, buf);
        // rewind the cursor to the position before the fread:
        fseek(fp, -1, SEEK_CUR);
    }
}

void d (FILE * fp, const size_t ncolumns, const char * filename) {

    {
        fprintf(stdout, "\nd) Move backward 2 records and read the first byte...\n");
        long offset = -2 * ncolumns;
        int whence = SEEK_CUR;
        fseek(fp, offset, whence);
        uint8_t buf;
        int nread = fread(&buf, 1, 1, fp);
        if (nread != 1) {
            char formatstr[] = "%sAn error occurred while reading a byte from file '%s': %s.\n";
            fprintf(stderr, formatstr, indent, filename, strerror(errno));
        }
        fprintf(stdout, "%sThe first byte of the record 2 records back is '%c'.\n", indent, buf);
        // rewind the cursor to the position before the fread:
        fseek(fp, -1, SEEK_CUR);
    }
}

int main (int argc, char * argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
        fprintf(stderr, "Write binary data to file FILENAME and perform fseek operations on it. \n");
        exit(EXIT_FAILURE);
    }
    char * filename = argv[1];

    constexpr int ncolumns = 64;
    constexpr int nrecords = 16;
    write_testfile(filename, ncolumns, nrecords);

    FILE * fp = fopen(filename, "rb");
    a(fp, ncolumns, filename);
    b(fp, ncolumns, filename);
    c(fp, ncolumns, filename);
    d(fp, ncolumns, filename);
    fclose(fp);

    return EXIT_SUCCESS;
}
