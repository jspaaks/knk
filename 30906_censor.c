#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void censor(char *, const char *);

void censor(char *s, const char *redact) {
    int n = strlen(redact);
    char redacted[n];
    for (int i = 0; i < n; i++) {
        redacted[i] = 'x';
    }
    char *p = &s[0];
    while (*p != '\0') {
        bool isequal = strncmp(p, redact, n) == 0;
        if (isequal) {
            strncpy(p, redacted, n);
        }
        p++;
    }
    // shorter != better, dont do this: 
    // for (char *p = s; *p != '\0'; p++) if (strncmp(p, redact, n) == 0) strncpy(p, redacted, n);
}

int main (void) {
    char text[] = "food fool";
    char redact[] = "foo";
    printf("before censoring: %s\n", text);
    censor(text, redact);
    printf("redacted        : %s\n", text);
    return EXIT_SUCCESS;
}
