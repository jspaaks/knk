#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct dialing_code {
    char * country;
    int code;
};


int ask (void);
bool lookup (int, struct dialing_code *);
void verdict (bool, int, struct dialing_code);
void welcome (void);


const struct dialing_code country_codes[] = {
    { "Argentina",       54 },
    { "Bangladesh",     880 },
    { "Brazil",          55 },
    { "China",           86 },
    { "Colombia",        57 },
    { "DRC",            243 },
    { "Egypt",           20 },
    { "Ethiopia",       251 },
    { "France",          33 },
    { "Germany",         49 },
    { "India",           91 },
    { "Indonesia",       62 },
    { "Iran",            98 },
    { "Italy",           39 },
    { "Japan",           81 },
    { "Mexico",          52 },
    { "Myanmar",         95 },
    { "Netherlands",     31 },
    { "Nigeria",        234 },
    { "Pakistan",        92 },
    { "Philippines",     63 },
    { "Poland",          48 },
    { "Russia",           7 },
    { "South Africa",    27 },
    { "South Korea",     82 },
    { "Spain",           34 },
    { "Sudan",          249 },
    { "Thailand",        66 },
    { "Turkey",          90 },
    { "Ukraine",        380 },
    { "United Kingdom",  44 },
    { "United States",    1 },
    { "Vietnam",         84 }
};



int ask (void) {
    int code = -1;
    char s[] = "Enter a country code [1-880]: ";
    fprintf(stdout, "%s", s);
    scanf(" %d", &code);
    return code;
}


bool lookup (int code, struct dialing_code * result) {
    int n = sizeof country_codes / sizeof country_codes[0];
    for (int i = 0; i < n; i++) {
        if (country_codes[i].code == code) {
            *result = country_codes[i];
            return true;
        }
    }
    return false;
}


void verdict (bool success, int code, struct dialing_code match) {
    if (success) {
        fprintf(stdout, "Code %d is for %s.\n", code, match.country);
    } else {
        fprintf(stdout, "Not found.\n");
    }
}

void welcome (void) {
    char s[] = "Telephone country code lookup program.\n";
    fprintf(stdout, "%s", s);
}


int main (void) {

    welcome();
    int code = ask();
    if (code < 1 || code > 880) {
        fprintf(stderr, "Code is out of range.\n");
        return EXIT_FAILURE;
    }
    struct dialing_code match = {"", -1};
    bool success = lookup(code, &match);
    verdict(success, code, match);
    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
