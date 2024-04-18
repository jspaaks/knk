#include <string.h>
#include <stdio.h>

char *duplicate(const char *); 

char *duplicate(const char *p) {
    // gives error, q not initialized so points to a random place somewhere in memory
    char *q; 
    strcpy(q, p);
    return q;
}; 

int main (void) {
    char s0[] = "to be copied";
    char *s1 = duplicate(s0);
    printf("%s", s1);
}
