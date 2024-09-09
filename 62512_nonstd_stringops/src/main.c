#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mystrdup (const char *);
int mystricmp (const char *, const char *);
char * mystrlwr (char *);
char * mystrrev (char *);
char * mystrset (char *, char);
void show_usage (FILE *);
void test_mystrdup (void);
void test_mystricmp (void);
void test_mystrlwr (void);
void test_mystrrev (void);
void test_mystrset (void);

char * mystrdup (const char * s) {
    size_t ell = strlen(s);
    char * s_dup = malloc(ell + 1);
    if (s_dup != nullptr) {
        strncpy(s_dup, s, ell + 1);
    }
    return s_dup;
}

int mystricmp (const char * s1, const char * s2) {
    const char * p1 = s1;
    const char * p2 = s2;
    int diff;
    bool ends;
    while (true) {
        ends = *p1 == '\0' || *p2 == '\0';
        diff = tolower(*p1) - tolower(*p2);
        if (ends) break;
        if (diff == 0) {
            p1++;
            p2++;
        }
    }
    return diff;
}

char * mystrlwr (char * s) {
    char * p = s;
    while (*p != '\0') {
        if (isupper(*p)) {
            *p = tolower(*p);
        }
        p++;
    }
    return s;
}

char * mystrrev (char * s) {
    char * p = s;
    char * q = s;
    while (*q != '\0') {
        q++;
    }
    q--;
    while (p < q) {
        char tmp = *q;
        *q = *p;
        *p = tmp;
        p++;
        q--;
    }
    return s;
}

char * mystrset (char * s, char ch) {
    size_t cap = strlen(s);
    memset(s, ch, cap);
    return s;
}

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    test_mystrdup();
    test_mystricmp();
    test_mystrlwr();
    test_mystrrev();
    test_mystrset();

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "stringalong";
    fprintf(stream,
            "Usage: %s\n"
            "Demo various non-standard string methods.\n",
            exename);
}

void test_mystrdup (void) {
    fprintf(stdout, "a) Test mystrdup:\n");
    char s[] = "hello strings";
    char * s_dup = mystrdup(&s[0]);
    fprintf(stdout, "   -- %p: %s\n", s, s);
    fprintf(stdout, "   -- %p: %s\n", s_dup, s_dup);
    free(s_dup);
    fprintf(stdout, "\n");
}

void test_mystricmp (void) {
    fprintf(stdout, "b) Test mystricmp:\n");
    {
        char s1[] = "abc";
        char s2[] = "abc";
        int status = strcmp(s1, s2);
        int statusi = mystricmp(s1, s2);
        fprintf(stdout, "   -- strcmp(\"%s\", \"%s\") = %d\n", s1, s2, status);
        fprintf(stdout, "   -- mystricmp(\"%s\", \"%s\") = %d\n\n", s1, s2, statusi);
    }
    {
        char s1[] = "abc";
        char s2[] = "ABC";
        int status = strcmp(s1, s2);
        int statusi = mystricmp(s1, s2);
        fprintf(stdout, "   -- strcmp(\"%s\", \"%s\") = %d\n", s1, s2, status);
        fprintf(stdout, "   -- mystricmp(\"%s\", \"%s\") = %d\n\n", s1, s2, statusi);
    }
    {
        char s1[] = "abc";
        char s2[] = "ABC";
        int status = strcmp(s1, s2);
        int statusi = mystricmp(s1, s2);
        fprintf(stdout, "   -- strcmp(\"%s\", \"%s\") = %d\n", s1, s2, status);
        fprintf(stdout, "   -- mystricmp(\"%s\", \"%s\") = %d\n\n", s1, s2, statusi);
    }
    {
        char s1[] = "abcd";
        char s2[] = "ABC";
        int status = strcmp(s1, s2);
        int statusi = mystricmp(s1, s2);
        fprintf(stdout, "   -- strcmp(\"%s\", \"%s\") = %d\n", s1, s2, status);
        fprintf(stdout, "   -- mystricmp(\"%s\", \"%s\") = %d\n\n", s1, s2, statusi);
    }
    {
        char s1[] = "ABC";
        char s2[] = "abcd";
        int status = strcmp(s1, s2);
        int statusi = mystricmp(s1, s2);
        fprintf(stdout, "   -- strcmp(\"%s\", \"%s\") = %d\n", s1, s2, status);
        fprintf(stdout, "   -- mystricmp(\"%s\", \"%s\") = %d\n\n", s1, s2, statusi);
    }
    {
        char s1[] = "abc";
        char s2[] = "ABCD";
        int status = strcmp(s1, s2);
        int statusi = mystricmp(s1, s2);
        fprintf(stdout, "   -- strcmp(\"%s\", \"%s\") = %d\n", s1, s2, status);
        fprintf(stdout, "   -- mystricmp(\"%s\", \"%s\") = %d\n\n", s1, s2, statusi);
    }
    {
        char s1[] = "ABCD";
        char s2[] = "abc";
        int status = strcmp(s1, s2);
        int statusi = mystricmp(s1, s2);
        fprintf(stdout, "   -- strcmp(\"%s\", \"%s\") = %d\n", s1, s2, status);
        fprintf(stdout, "   -- mystricmp(\"%s\", \"%s\") = %d\n", s1, s2, statusi);
    }
    fprintf(stdout, "\n");
}

void test_mystrlwr (void) {
    char s[] = "Testing ONE Two *&^ (-98 JKHG";
    fprintf(stdout, "c) Test mystrlwr:\n");
    fprintf(stdout, "   -- before: '%s'\n", s);
    mystrlwr(s);
    fprintf(stdout, "   -- after : '%s'\n", s);
    fprintf(stdout, "\n");
}

void test_mystrrev (void) {
    char s[] = "flip it!";
    fprintf(stdout, "d) Test mystrrev:\n");
    fprintf(stdout, "   -- before: '%s'\n", s);
    mystrrev(s);
    fprintf(stdout, "   -- after : '%s'\n", s);
    fprintf(stdout, "\n");
}

void test_mystrset (void) {
    char s[] = "abcde";
    fprintf(stdout, "e) Test mystrset:\n");
    fprintf(stdout, "   -- before: '%s'\n", s);
    mystrset(s, '*');
    fprintf(stdout, "   -- after : '%s'\n", s);
    fprintf(stdout, "\n");
}
