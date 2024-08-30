#include "files.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void close_files (Files * files) {
    {
        int status = fclose(files->read.fp);
        if (status == EOF) {
            fprintf(stderr, " -- Error closing file '%s': %s.\n", (char *) files->read.filename, strerror(errno));
            errno = 0;
            close_files(files);
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, " -- Closed file '%s'.\n", files->read.filename);
    }
    {
        int status = fclose(files->write.fp);
        if (status == EOF) {
            fprintf(stderr, " -- Error closing file '%s': %s.\n", (char *) files->write.filename, strerror(errno));
            errno = 0;
            close_files(files);
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, " -- Closed file '%s'.\n", files->write.filename);
    }
}

void open_files (Files * files) {
    {
        files->read.fp = fopen((char *) files->read.filename, "r");
        if (files->read.fp == nullptr) {
            fprintf(stderr, " -- Error opening file '%s': %s.\n", (char *) files->read.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, " -- Opened file '%s' for reading...\n", files->read.filename);
    }
    {
        files->write.fp = fopen((char *) files->write.filename, "w");
        if (files->write.fp == nullptr) {
            fprintf(stderr, " -- Error opening file '%s': %s.\n", (char *) files->write.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, " -- Opened file '%s' for writing...\n", files->write.filename);
    }
}
