#include <stdio.h>
#include <stdlib.h>

int count_periods (const char * filename) {
    int n = 0;
    FILE * fp = fopen(filename, "r");
    if (fp != NULL) {
        while (true) {
            int c = fgetc(fp);
            if (c == EOF) break;
            if (c == '.') n++;
        }
        fclose(fp);
    }
    return n;
}

int main (int argc, char * argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: count-periods FILENAME\n");
        fprintf(stderr, "Return the number of periods in a given string\n");
        exit(EXIT_FAILURE);
    }

    int n = count_periods(argv[1]);
    fprintf(stdout, "%d\n", n);

    return EXIT_SUCCESS;
}
