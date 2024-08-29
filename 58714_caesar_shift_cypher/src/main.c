#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    struct {
        FILE * fp;
        char filename[FILENAME_MAX];
    } read;

    struct {
        FILE * fp;
        char filename[FILENAME_MAX];
    } write;
} Files;

void close_files (Files *);
void open_files (Files *);
void print_usage (FILE *, char *);
void prompt_filename (Files *);
int8_t prompt_shift (void);

void close_files (Files * files) {
    {
        int status = fclose(files->read.fp);
        if (status == EOF) {
            fprintf(stderr, " -- Error closing file '%s': %s.\n", (char *) files->read.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }
    {
        int status = fclose(files->write.fp);
        if (status == EOF) {
            fprintf(stderr, " -- Error closing file '%s': %s.\n", (char *) files->write.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }
}

void encypher (Files * files, int8_t shift) {
    fprintf(stdout, " -- Encrypting...\n");
    while (true) {
        int ch = fgetc(files->read.fp);
        int ch_enc;
        if (ch == EOF && ferror(files->read.fp)) {
            fprintf(stderr, "Error reading from file '%s': %s", (char *) files->read.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (ch == EOF && feof(files->read.fp)) {
            break;
        }
        if (islower(ch)) {
            ch_enc = 'a' + (ch - 'a' + shift) % 26;
        } else if (isupper(ch)) {
            ch_enc = 'A' + (ch - 'A' + shift) % 26;
        } else {
            ch_enc = ch;
        }
        if (fputc(ch_enc, files->write.fp) == EOF) {
            fprintf(stderr, "Error writing to file '%s': %s", (char *) files->write.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }
    fprintf(stdout, " -- Done.\n");
}

void open_files (Files * files) {
    files->read.fp = fopen((char *) files->read.filename, "r");
    if (files->read.fp == nullptr) {
        fprintf(stderr, " -- Error opening file '%s': %s.\n", (char *) files->read.filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    strncpy(files->write.filename, files->read.filename, FILENAME_MAX);
    strcat(files->write.filename, ".enc");
    files->write.fp = fopen((char *) files->write.filename, "w");
    if (files->write.fp == nullptr) {
        fprintf(stderr, " -- Error opening file '%s': %s.\n", (char *) files->write.filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, " -- Opened file '%s' for writing...\n", files->write.filename);
}

void prompt_filename (Files * files) {
    fprintf(stdout, " -- Enter the name of a file to be encrypted: ");
    int nread = fscanf(stdin, "%s", (char *) files->read.filename);
    if (nread != 1) {
        fprintf(stderr, " -- Error getting data from STDIN.\n");
        errno = 0;
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, " -- Requested encrypting contents of '%s'.\n", (char *) files->read.filename);
}

int8_t prompt_shift (void) {
    int8_t shift;
    fprintf(stdout, " -- Enter shift amount (1-25): ");
    int nread = fscanf(stdin, " %hhd", &shift);
    if (nread != 1) {
        fprintf(stderr, " -- Error getting data from STDIN.\n");
        errno = 0;
        exit(EXIT_FAILURE);
    }
    return shift;
}

void print_usage (FILE * stream, char * exepath) {
    fprintf(stream,
            "Usage: %s\n"
            "\n"
            "    1. Ask the user to enter a FILENAME\n"
            "    2. Encrypt FILENAME's contents using Caesar's shift cypher\n"
            "    3. Write the encrypted file as FILENAME.enc\n",
            exepath);
}

int main (int argc, char * argv[]) {
    char * exepath = argv[0];

    if (argc != 1) {
        print_usage(stderr, exepath);
        exit(EXIT_FAILURE);
    }

    Files files = {};

    prompt_filename(&files);
    int8_t shift = prompt_shift();

    open_files(&files);

    encypher(&files, shift);

    close_files(&files);

    return EXIT_SUCCESS;
}
