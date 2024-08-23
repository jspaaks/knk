#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    struct {
        char * filename;
        FILE * fp;
    } uncmpr;

    struct {
        char * filename;
        FILE * fp;
    } cmpr;
} Files;

typedef struct {
    uint8_t count;
    uint8_t payload;
} Pair;

typedef enum {
    KIND_ENCODE = 0,
    KIND_DECODE,
} Kind;

static void decode(Files);
static void encode(Files);
static Kind get_kind (char *);
static void print_usage (char *);
static Files safeopen_for_decoding (char *);
static Files safeopen_for_encoding (char *);

static void decode (Files files) {
    bool keepgoing = true;
    while (keepgoing) {
        Pair pair;
        {
            size_t nread = fread(&pair.count, 1, 1, files.cmpr.fp);
            if (nread != 1 && ferror(files.cmpr.fp)) {
                // error
                fprintf(stderr, "Error reading character from file '%s': %s.\n", files.cmpr.filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (nread != 1 && feof(files.cmpr.fp)) {
                // eof
                break;
            }
        }
        {
            size_t nread = fread(&pair.payload, 1, 1, files.cmpr.fp);
            if (nread != 1 && ferror(files.cmpr.fp)) {
                // error
                fprintf(stderr, "Error reading character from file '%s': %s.\n", files.cmpr.filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (nread != 1 && feof(files.cmpr.fp)) {
                // eof
                break;
            }
        }
        for (int i = 0; i < pair.count; ++i) {
            fwrite(&pair.payload, 1, 1, files.uncmpr.fp);
        }
    }
}

static void encode (Files files) {
    bool keepgoing = true;
    while (keepgoing) {
        Pair pair = {};
        uint8_t payload;
        for (int i = 0; i < 255; ++i) {
            size_t nread = fread(&payload, 1, 1, files.uncmpr.fp);
            if (nread != 1 && ferror(files.uncmpr.fp)) {
                // error
                fprintf(stderr, "Error reading character from file '%s': %s.\n", files.uncmpr.filename,
                        strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (nread != 1 && feof(files.uncmpr.fp)) {
                // eof
                if (pair.count > 0) {
                    fwrite(&pair.count, 1, 1, files.cmpr.fp);
                    fwrite(&pair.payload, 1, 1, files.cmpr.fp);
                }
                keepgoing = false;
                break;
            }
            if (pair.count == 254) {
                // count full
                pair.count++;
                fwrite(&pair.count, 1, 1, files.cmpr.fp);
                fwrite(&pair.payload, 1, 1, files.cmpr.fp);
                break;
            }
            if (i > 0 && payload != pair.payload) {
                // payload changed
                fwrite(&pair.count, 1, 1, files.cmpr.fp);
                fwrite(&pair.payload, 1, 1, files.cmpr.fp);
                fseek(files.uncmpr.fp, -1, SEEK_CUR);
                break;
            }
            if (i == 0) {
                pair.payload = payload;
            }
            pair.count++;
        }
    }
}

static Kind get_kind (char * kind) {
    {
        bool cond1 = strncmp(kind, "--encode", 9) == 0;
        bool cond2 = strncmp(kind, "-e", 3) == 0;
        if (cond1 || cond2) return KIND_ENCODE;
    }
    {
        bool cond1 = strncmp(kind, "--decode", 9) == 0;
        bool cond2 = strncmp(kind, "-d", 3) == 0;
        if (cond1 || cond2) return KIND_DECODE;
    }
    fprintf(stderr, "Unknown argument '%s'. Aborting.\n", kind);
    exit(EXIT_FAILURE);
}

int main (int argc, char * argv[]) {

    if (argc != 3) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    Files files;
    Kind kind = get_kind(argv[1]);
    switch (kind) {
        case KIND_ENCODE: {
            fprintf(stdout, "encoding\n");
            files = safeopen_for_encoding(argv[2]);
            encode(files);
            break;
        }
        case KIND_DECODE: {
            fprintf(stdout, "decoding\n");
            files = safeopen_for_decoding(argv[2]);
            decode(files);
            break;
        }
        default: {
            assert(false && "Unreachable.\n");
        }
    }

    fclose(files.uncmpr.fp);
    fclose(files.cmpr.fp);

    return EXIT_SUCCESS;
}

static void print_usage (char * exename) {
    char * p = exename;
    while (*p != '\0') {
        p++;
    };
    while ((p > exename) && (*p != '/')) {
        p--;
    };
    exename = ++p;
    fprintf(stderr,
            "Usage:\n\n"
            "   %s [ --encode | -e ] FILENAME     Compress the contents of FILENAME\n"
            "                                      using run-length encoding and save\n"
            "                                      it as a new file; the created file\n"
            "                                      will be named FILENAME plus the .rle\n"
            "                                      extension.\n\n"
            "   %s [ --decode | -d ] FILENAME     Decompress the contents of FILENAME\n"
            "                                      using run-length encoding and save it\n"
            "                                      as a new file. FILENAME should have a\n"
            "                                      .rle extension; the created file will\n"
            "                                      be named FILENAME minus the extension.\n",
            exename, exename);
}

Files safeopen_for_encoding (char * filename_uncmpr) {
    FILE * fp_uncmpr = fopen(filename_uncmpr, "rb");
    if (fp_uncmpr == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename_uncmpr, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    char filename_cmpr[NAME_MAX];
    strncpy(filename_cmpr, filename_uncmpr, NAME_MAX - 5);
    strcat(filename_cmpr, ".rle");

    FILE * fp_cmpr = fopen(filename_cmpr, "wb");
    if (fp_cmpr == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename_cmpr, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    return (Files) {
        .uncmpr = {
            .filename = filename_uncmpr,
            .fp = fp_uncmpr,
        },
        .cmpr = {
            .filename = filename_cmpr,
            .fp = fp_cmpr,
        },
    };
}

Files safeopen_for_decoding (char * filename_cmpr) {

    FILE * fp_cmpr = fopen(filename_cmpr, "rb");
    if (fp_cmpr == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename_cmpr, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    char filename_uncmpr[NAME_MAX];
    strncpy(filename_uncmpr, filename_cmpr, NAME_MAX);

    char * p = filename_uncmpr;
    while (*p != '\0') {
        p++;
    };
    if (p - filename_uncmpr < 4) {
        fprintf(stderr, "FILENAME should end in .rle extension.\n");
        exit(EXIT_FAILURE);
    }
    p -= 4;
    if (strncmp(p, ".rle", 5) != 0) {
        fprintf(stderr, "FILENAME should end in .rle extension.\n");
        exit(EXIT_FAILURE);
    }
    *p = '\0';

    FILE * fp_uncmpr = fopen(filename_uncmpr, "wb");
    if (fp_uncmpr == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename_uncmpr, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    return (Files) {
        .uncmpr = {
            .filename = filename_uncmpr,
            .fp = fp_uncmpr,
        },
        .cmpr = {
            .filename = filename_cmpr,
            .fp = fp_cmpr,
        },
    };
}
