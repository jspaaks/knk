#include <stdio.h>

void remove_filename(char *url);

int main (void) {
    char url[] = "http://www.knking.com/index.html";
    printf("before: %s\n", url);
    remove_filename(url);
    printf("after : %s\n", url);
}

void remove_filename(char *url) {
    char *p = url;
    while (*p) {
        p++;
    }
    while (url <= p) {
        if (*p == '/') {
            *p = '\0';
            break;
        }
        p--;
    }
}
