#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);
void myprintf (char * fmt, ...);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    myprintf("hello %d%d\n", 1, 23);
    myprintf("hello %d, %d, %d\n", 444, 55, 6);

    return EXIT_SUCCESS;
}

void myprintf (char * fmt, ...) {
    // assume all inputs are integers
    // assume no escape chars
    // ignore percent literals

    char * prev = nullptr;
    char * curr = fmt;
    va_list ap;
    va_start(ap, fmt);

    while (true) {
        if (*curr == '\0') {
            break;
        } else if (*curr == '%') {
            // ignore
        } else if (prev != nullptr && *prev == '%' && *curr == 'd') {
            int d = va_arg(ap, int);
            int arr[100] = { 0 };
            size_t i = 0;
            while (d > 0) {
                arr[i] = d % 10;
                d /= 10;
                i++;
            }
            while (i > 0) {
                putchar('0' + arr[i - 1]);
                i--;
            }
        } else {
            putchar(*curr);
        }
        prev = curr;
        curr++;
    }
    va_end(ap);
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "    Demo homegrown printf.\n",
            exename);
}
