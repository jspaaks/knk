#include <string.h>
#include <stdio.h>

void build_index_url(const char *domain, char *index_url);

void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "https://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
    return;
}

int main (void) {
    char url[100];
    build_index_url("knking.com", url);
    printf("%s\n", url);
}
