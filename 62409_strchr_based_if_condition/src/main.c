#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {

    char * exename = "demo";

    if (argc != 2) {
        fprintf(stderr,
                "Usage: %s CH\n"
                "    Determine whether character CH is one of 'a', 'b', or 'c' using 2 methods.\n",
                exename);
        exit(EXIT_FAILURE);
    }

    char ch = argv[1][0];

    bool cond1 = ch == 'a' || ch == 'b' || ch == 'c';
    fprintf(stdout, "According to method 1, character '%c' is%sone of 'a', 'b', or 'c'.\n", ch, cond1 ? " " : " not ");

    bool cond2 = strchr("abc", ch) != nullptr;
    fprintf(stdout, "According to method 2, character '%c' is%sone of 'a', 'b', or 'c'.\n", ch, cond2 ? " " : " not ");

    return EXIT_SUCCESS;
}
