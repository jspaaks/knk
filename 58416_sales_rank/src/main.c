#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {

    if (argc != 1) {
        fprintf(stdout, "Usage: %s\n", argv[0]);
        fprintf(stdout, "Parses sales rank formatted numbers from STDIN and prints them to STDOUT.\n");
    }

    while (true) {
        char str[1024] = {};
        char rank[1024] = {};

        char * status = fgets(str, 1024, stdin);
        if (status == NULL) {
            break;
        }
        sscanf(str, " %*[^0-9]%[0-9,]%*[^\n]", rank);
        fprintf(stdout, "%s\n", rank);
    }
    fprintf(stdout, "Done.\n");
    return EXIT_SUCCESS;
}
