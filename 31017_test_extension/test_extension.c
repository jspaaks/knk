#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool test_extension(const char *, const char *);

int main (void) {

    char *filenames[] = {
        "memo.txt",
        "README.md",
        "About.page.route.ts",
        ".gitignore",
        ".somefile.txt",
        "README"
    };
    int n = sizeof filenames / sizeof filenames[0];
    char extension[] = "TXT";
    for (int i = 0; i < n; i++) {
        bool is_matching = test_extension(filenames[i], extension);
        if (strcmp(extension, "") == 0) {
            printf("File '%s' has no extension: %s.\n", filenames[i], is_matching == true ? "true" : "false");
        } else {
            printf("File '%s' has extension %s: %s.\n",
                filenames[i],
                extension,
                is_matching == true ? "true" : "false");
        }
    }
}

bool test_extension(const char *filename, const char *extension) {
    const char *p = filename;
    const char *q = filename;
    while (*p) {
        if (*p == '.') {
            q = p + 1;
        }
        p++;
    }

    if (q == filename) {
        // no dot in filename, return true if extension is empty string
        return strlen(extension) == 0;
    }

    if (filename[0] == '.' && q == filename + 1) {
        // hidden file without extension
        return strlen(extension) == 0;
    }

    char uppered[p - q];
    for (int i = 0; q <= p; q++, i++) {
        uppered[i] = toupper(*q);
    }
    return strcmp(uppered, extension) == 0;
}
