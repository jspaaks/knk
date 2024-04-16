#include <stdio.h>
#include <stdbool.h>
#include "buffer.h"
#define NCHARSMAX 20

bool is_whitespace(int);
bool is_repeated_whitespace(int, int);


// --------------------------------------------

int read_next_char() {
    int this = getchar();
    return is_whitespace(this) ? ' ' : this;
}


bool is_whitespace(int c) {
    return c == ' ' || c == '\t' || c == '\n';
}

bool is_repeated_whitespace(int prev, int this) {
    return is_whitespace(prev) && is_whitespace(this);
}

int main (void) {
    int this = ' ';
    int prev = this;
    while (true) {
        prev = this;
        this = read_next_char();
        if (this == EOF) {
            print_buffer();
            return 0;
        }
        if (is_repeated_whitespace(prev, this)) {
            continue;
        }
        update_buffer(this);
    }
}
