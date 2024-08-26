#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 200

typedef struct {
    const char * filename;
    FILE * fp;
} File;

typedef struct {
    File in0;
    File in1;
    File out;
} Files;

typedef struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} Part;

Part inventory[MAX_PARTS];

void close_files(Files);
void merge(Files);
Files open_files (const char *, const char *, const char *);
void print_usage (const char *[], FILE *);
bool read_part (const File, Part *);
void write_part (const File, const Part *);

void close_files (Files files) {
    constexpr size_t nfiles = 3;
    File arr[nfiles] = {
        files.in0,
        files.in1,
        files.out,
    };
    for (size_t i = 0; i < nfiles; ++i) {
        int status = fclose(arr[i].fp);
        if (status == EOF) {
            fprintf(stderr, "Error closing file '%s': %s.\n", arr[i].filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }
}

int main (const int argc, const char * argv[]) {

    if (argc != 6) {
        print_usage(argv, stderr);
        exit(EXIT_FAILURE);
    }
    if ((strncmp(argv[1], "-i", 3) != 0) && (strncmp(argv[1], "--input-filenames", 18) != 0)) {
        print_usage(argv, stderr);
        exit(EXIT_FAILURE);
    }
    if ((strncmp(argv[4], "-o", 3) != 0) && (strncmp(argv[4], "--output-filenames", 19) != 0)) {
        print_usage(argv, stderr);
        exit(EXIT_FAILURE);
    }

    Files files = open_files(argv[2], argv[3], argv[5]);
    merge(files);
    close_files(files);

    return EXIT_SUCCESS;
}

void merge (Files files) {
    Part part0;
    Part part1;

    bool eof0 = read_part(files.in0, &part0);
    bool eof1 = read_part(files.in1, &part1);

    while (true) {
        if (eof0 && eof1) {
            break;
        } else if (eof1 || (!eof0 && part0.number < part1.number)) {
            // write part0
            write_part(files.out, &part0);
            // read 0
            eof0 = read_part(files.in0, &part0);
        } else if (eof0 || (!eof1 && part0.number > part1.number)) {
            // write part1
            write_part(files.out, &part1);
            // read 1
            eof1 = read_part(files.in1, &part1);
        } else if (part0.number == part1.number) {
            // adjust part 0, read part 1; defer writing updated part0 until the next iteration
            bool cond = strncmp(part0.name, part1.name, NAME_LEN + 1) == 0;
            if (!cond) {
                fprintf(stderr, "Names don't match for part identifier %d: %s v. %s.\n", part0.number, part0.name,
                        part1.name);
                exit(EXIT_FAILURE);
            }
            part0.on_hand += part1.on_hand;
            eof1 = read_part(files.in1, &part1);
        } else {
            assert(false && "unreachable");
        }
    }
}

Files open_files (const char * input_filename1, const char * input_filename2, const char * output_filename) {
    Files files = {};

    {
        FILE * fp = fopen(input_filename1, "rb");
        if (fp == nullptr) {
            fprintf(stderr, "Error opening file '%s': %s.\n", input_filename1, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        files.in0 = (File){
            .fp = fp,
            .filename = input_filename1,
        };
    }

    {
        FILE * fp = fopen(input_filename2, "rb");
        if (fp == nullptr) {
            fprintf(stderr, "Error opening file '%s': %s.\n", input_filename2, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        files.in1 = (File){
            .fp = fp,
            .filename = input_filename2,
        };
    }

    {
        FILE * fp = fopen(output_filename, "wb+");
        if (fp == nullptr) {
            fprintf(stderr, "Error opening file '%s': %s.\n", output_filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        files.out = (File){
            .fp = fp,
            .filename = output_filename,
        };
    }
    return files;
}

void print_usage (const char * argv[], FILE * stream) {
    const char * exename = argv[0];
    const char * p = argv[0];
    while (*p != '\0')
        p++;
    while (p > exename && *p != '/')
        p--;
    p++;
    fprintf(stream,
            "Usage:\n"
            "    %s [-i | --input-filenames ] INPUT_FILENAME1 INPUT_FILENAME2\n"
            "          [-o | --output-filename ] OUTPUT_FILENAME\n\n"
            "    Merge binary inventory file INPUT_FILENAME1 with binary\n"
            "    inventory file INPUT_FILENAME2, and write the results in\n"
            "    binary file OUTPUT_FILENAME.\n",
            p);
}

bool read_part (const File file, Part * part) {
    int nread = fread(part, sizeof(Part), 1, file.fp);
    if (nread != 1 && ferror(file.fp)) {
        fprintf(stderr, "Error reading from file '%s': %s.\n", file.filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    if (nread != 1 && feof(file.fp)) {
        return true;
    }
    return false;
}

void write_part (const File file, const Part * part) {
    int nwritten = fwrite(part, sizeof(Part), 1, file.fp);
    if (nwritten != 1 && ferror(file.fp)) {
        fprintf(stderr, "Error writing to file '%s': %s.\n", file.filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
}
