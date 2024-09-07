#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_c_identifier (char * s);

bool is_valid_c_identifier (char * s) {
    char * p = s;
    if (*p == '_' || isalpha(*p)) {
        // pass
    } else {
        return false;
    }
    p++;
    while (*p != '\0') {
        if (*p == '_' || isalnum(*p)) {
            // pass
        } else {
            return false;
        }
        p++;
    }
    return true;
}

int main (int argc, char *[]) {

    char * exename = "identifiers";

    if (argc != 1) {
        fprintf(stderr,
                "Usage: %s\n"
                "    Print a few different strings and indicate whether\n"
                "    they are valid C identifier strings.\n",
                exename);
        exit(EXIT_FAILURE);
    }

    char * strs[] = { "napples",        "number_of_apples", "#apples",          "numberOfApples",
                      "NumberOfApples", "_state",           "number-of-apples", "n'",
                      "0apples",        "apples!",          "apples[4]" };

    int nspaces = 0;
    char spaces[16];
    bool isvalid = true;
    memset(&spaces[0], ' ', 16);
    size_t n = sizeof(strs) / sizeof(strs[0]);
    fprintf(stdout, "string             is valid   is not valid\n");
    fprintf(stdout, "----------------   --------   ------------\n");
    for (size_t i = 0; i < n; ++i) {
        isvalid = is_valid_c_identifier(strs[i]);
        fprintf(stdout, "%s%n", strs[i], &nspaces);
        fprintf(stdout, "%.*s   %.*sx\n", 16 - nspaces, spaces, isvalid ? 4 : 16, spaces);
    }
    return EXIT_SUCCESS;
}
