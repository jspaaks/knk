#ifndef FILES_H
#define FILES_H

#include <stdio.h>

typedef struct {
    struct {
        char filename[FILENAME_MAX];
        FILE * fp;
    } read;
    struct {
        char filename[FILENAME_MAX];
        FILE * fp;
    } write;
} Files;

void close_files (Files *);
void open_files (Files *);

#endif
