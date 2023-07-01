#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NCHARS 1000

int get_shift_amount() {
    int shift;
    scanf(" %d", &shift);
    if (shift < 0 || shift > 25) {
        printf("Shift amount should be between 1 and 25 characters. Aborting.\n");
        return -1;
    }
    return shift;
}

void print_encrypted(char *message, int shift) {
    char *p = message;
    while (*p != '\0') {
        char c = *p;
        char c_cipher;
        bool is_upper = 'A' <= c && c <= 'Z';
        bool is_lower = 'a' <= c && c <= 'z';
        if (is_upper == true) {
            c_cipher = (c - 'A' + shift) % 26 + 'A';
        } else if (is_lower == true) {
            c_cipher = (c - 'a' + shift) % 26 + 'a';
        } else {
            c_cipher = c;
        }
        putchar(c_cipher);
        p++;
    }
    putchar('\n');
}

void read(char message[NCHARS]) {
    for (int ichar = 0; ichar < NCHARS; ichar++) {
        char c = getchar();
        if (c == '\n') {
            break;
        } else {
            message[ichar] = c;
        }
    }
    return;
}

int main (void) {
    char message[NCHARS] = "";
    int shift;

    printf("Enter message to be encrypted: ");
    read(message);

    printf("Enter shift amount (1-25): ");
    shift = get_shift_amount();
    if (shift == -1) {
        return EXIT_FAILURE;
    }

    printf("Encrypted message: ");
    print_encrypted(message, shift);

    return EXIT_SUCCESS;
}
