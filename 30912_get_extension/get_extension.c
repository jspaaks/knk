#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get_extension(const char *filename, char *extension);

void get_extension(const char *filename, char *extension) {
    int n = strlen(filename);
    const char *p = &filename[n - 1];
    for (; p > filename; p--) {
        // for loop has p > filename, not p >= filename,
        // to handle e.g. filenames starting with .
        if (*p == '.') {
            strcpy(extension, ++p);
            return;
        }
    }
    strcpy(extension, "");
    return;
}

int main(void) {
    char *filenames[] = {
        "README",
        "memo.txt",
        ".gitinore",
        "about.page.route.ts"
    };
    int n = sizeof(filenames) / sizeof(filenames[0]);
    for (int i = 0; i < n; i++) {
        char extension[20];
        get_extension(filenames[i], extension);
        printf("file     : %s\n", filenames[i]);
        printf("extension: %s\n\n", extension);
    }
    return EXIT_SUCCESS;
}
