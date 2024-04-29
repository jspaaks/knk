#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * duplicate(const char *);


char * duplicate(const char * src) {
    int n = strlen(src);
    char * tgt = malloc(n * sizeof (char *));
    if (tgt != NULL) {
        strncpy(tgt, src, n);
    } else {
        printf("Memory allocation didn't work.\n");
    }
    return tgt;
}


int main (void) {
    char * s1 = "aerf 24f2 4f4r f24f3 fqws fqws fqsdf asdf betbg fba sdf vb.";
    char * s2 = duplicate(s1);
    if (s2 == NULL) {
        exit(EXIT_FAILURE);
    }
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    free(s2);
    exit(EXIT_SUCCESS);
}
