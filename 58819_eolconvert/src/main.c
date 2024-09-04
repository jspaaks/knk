#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char * filename;
    FILE * fp;
} File;

typedef struct files {
    File src;
    File dst;
} Files;

void close_files (Files *);
void convert_linux_to_windows (Files *);
void convert_windows_to_linux (Files *);
Files open_files (char *, char *);

void close_files (Files * files) {
    {
        int status = fclose(files->src.fp);
        if (status == EOF && ferror(files->src.fp)) {
            fprintf(stderr, "Error closing file '%s': %s.\n", files->src.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }
    {
        int status = fclose(files->dst.fp);
        if (status == EOF && ferror(files->dst.fp)) {
            fprintf(stderr, "Error closing file '%s': %s.\n", files->dst.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }
}

void convert_linux_to_windows (Files * files) {
    fprintf(stdout,
            "Converting Linux line endings in file '%s' to Windows line "
            "ending, and saving the result as file '%s'...\n",
            files->src.filename, files->dst.filename);
    uint8_t byte;
    const uint8_t carriage_return = '\r';
    while (true) {
        unsigned int nread = fread(&byte, 1, 1, files->src.fp);
        if (nread != 1 && ferror(files->src.fp)) {
            fprintf(stderr, "Error reading data from file '%s': %s.\n", files->src.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread != 1 && feof(files->src.fp)) {
            break;
        }
        int nwritten = fwrite(&byte, 1, 1, files->dst.fp);
        if (nwritten != 1) {
            fprintf(stderr, "Error writing data to file '%s': %s.\n", files->dst.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (byte == '\n') {
            int nwritten = fwrite(&carriage_return, 1, 1, files->dst.fp);
            if (nwritten != 1) {
                fprintf(stderr, "Error writing data to file '%s': %s.\n", files->dst.filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
        }
    }
    fprintf(stdout, "Done.\n");
}

void convert_windows_to_linux (Files * files) {
    fprintf(stdout,
            "Converting Windows line endings in file '%s' to Linux line "
            "ending, and saving the result as file '%s'...\n",
            files->src.filename, files->dst.filename);

    uint8_t prevbyte = '\0';
    uint8_t thisbyte = '\0';

    while (true) {
        unsigned int nread = fread(&thisbyte, 1, 1, files->src.fp);
        if (nread != 1 && ferror(files->src.fp)) {
            fprintf(stderr, "Error reading data from file '%s': %s.\n", files->src.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread != 1 && feof(files->src.fp)) {
            break;
        }

        if (prevbyte == '\n' && thisbyte == '\r') {
            prevbyte = thisbyte;
            continue;
        }

        int nwritten = fwrite(&thisbyte, 1, 1, files->dst.fp);
        if (nwritten != 1) {
            fprintf(stderr, "Error writing data to file '%s': %s.\n", files->dst.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        prevbyte = thisbyte;
    }

    fprintf(stdout, "Done.\n");
}

int main (int argc, char * argv[]) {

    char exename[] = "eolconvert";

    if (argc != 4) {
        fprintf(stderr,
                "Usage: %s [--windows-to-linux | --linux-to-windows ] INPUT_FILENAME OUTPUT_FILENAME\n"
                "\n"
                "Options:\n"
                "    --windows-to-linux    Convert Windows line endings in text file\n"
                "                          INPUT_FILENAME to Linux line endings, and\n"
                "                          write the result to OUTPUT_FILENAME.\n"
                "    --linux-to-windows    Convert Linux line endings in text file\n"
                "                          INPUT_FILENAME to Windows line endings, and\n"
                "                          write the result to OUTPUT_FILENAME.\n",
                exename);
        exit(EXIT_FAILURE);
    }

    Files files = open_files(argv[2], argv[3]);
    char * kind = argv[1];
    if (strncmp(kind, "--windows-to-linux", 19) == 0) {
        convert_windows_to_linux(&files);
    } else if (strncmp(kind, "--linux-to-windows", 19) == 0) {
        convert_linux_to_windows(&files);
    } else {
        fprintf(stderr, "Unknown argument name '%s', aborting.\n", kind);
    }

    close_files(&files);

    return EXIT_SUCCESS;
}

Files open_files (char * input_filename, char * output_filename) {
    File src = (File){
        .filename = input_filename,
        .fp = fopen(input_filename, "rb"),
    };
    if (src.fp == nullptr) {
        fprintf(stderr, "Error reading file '%s': %s.\n", input_filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    File dst = (File){
        .filename = output_filename,
        .fp = fopen(output_filename, "wb+"),
    };

    if (dst.fp == nullptr) {
        fprintf(stderr, "Error reading file '%s': %s.\n", output_filename, strerror(errno));
        errno = 0;
        fclose(src.fp);
        exit(EXIT_FAILURE);
    }
    return (Files){
        .src = src,
        .dst = dst,
    };
}
