#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    struct lconv lconv;
    char * props;
} LocaleInfo;

void show_usage (FILE * stream);

void get_locale_info (LocaleInfo *);
void print_locale_info (LocaleInfo *);

void get_locale_info (LocaleInfo * locale_info) {
    locale_info->lconv = *localeconv();
    char * tmp = setlocale(LC_ALL, nullptr);
    if (tmp == nullptr) {
        fprintf(stderr, "Error querying locale, aborting.\n");
        exit(EXIT_FAILURE);
    }
    const size_t ell = strlen(tmp);
    locale_info->props = malloc(ell + 1);
    if (locale_info->props == nullptr) {
        fprintf(stderr, "Error allocating memory for setlocale query result, aborting.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(locale_info->props, tmp, ell + 1);
}

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    char * abbr = argv[1];
    LocaleInfo locale_info = {};
    char * status = setlocale(LC_ALL, abbr);
    if (status == nullptr) {
        fprintf(stderr, "Unrecognized locale, aborting.\n");
        exit(EXIT_FAILURE);
    }
    get_locale_info(&locale_info);
    print_locale_info(&locale_info);
    free(locale_info.props);
    return EXIT_SUCCESS;
}

void print_locale_info (LocaleInfo * locale_info) {
    const char * delim = ";";
    size_t ell = strlen(locale_info->props);
    char * tmp = malloc(ell + 1);
    if (tmp == nullptr) {
        fprintf(stderr, " -- Error allocating memory, aborting.\n");
        free(locale_info->props);
        exit(EXIT_FAILURE);
    }
    strncpy(tmp, locale_info->props, ell + 1);
    char * prop = strtok(tmp, delim);
    fprintf(stdout, " -- Properties\n");
    while (prop != nullptr) {
        fprintf(stdout, " --     %s\n", prop);
        prop = strtok(nullptr, delim);
    }
    free(tmp);
    fprintf(stdout, " -- Non-monetary\n");
    fprintf(stdout, " --     decimal_point      = %s\n", locale_info->lconv.decimal_point);
    fprintf(stdout, " --     thousands_sep      = %s\n", locale_info->lconv.thousands_sep);
    fprintf(stdout, " --     grouping           = %d\n", locale_info->lconv.grouping[0]);
    fprintf(stdout, " -- Monetary\n");
    fprintf(stdout, " --     mon_decimal_point  = %s\n", locale_info->lconv.mon_decimal_point);
    fprintf(stdout, " --     mon_thousands_sep  = %s\n", locale_info->lconv.mon_thousands_sep);
    fprintf(stdout, " --     mon_grouping       = %d\n", locale_info->lconv.mon_grouping[0]);
    fprintf(stdout, " --     positive_sign      = %s\n", locale_info->lconv.positive_sign);
    fprintf(stdout, " --     negative_sign      = %s\n", locale_info->lconv.negative_sign);
    fprintf(stdout, " --     currency_symbol    = %s\n", locale_info->lconv.currency_symbol);
    fprintf(stdout, " --     int_curr_symbol    = %s\n", locale_info->lconv.int_curr_symbol);
    fprintf(stdout, " -- Local formatting\n");
    fprintf(stdout, " --     frac_digits        = %d\n", locale_info->lconv.frac_digits);
    fprintf(stdout, " --     p_cs_precedes      = %d\n", locale_info->lconv.p_cs_precedes);
    fprintf(stdout, " --     n_cs_precedes      = %d\n", locale_info->lconv.n_cs_precedes);
    fprintf(stdout, " --     p_sep_by_space     = %d\n", locale_info->lconv.p_sep_by_space);
    fprintf(stdout, " --     n_sep_by_space     = %d\n", locale_info->lconv.n_sep_by_space);
    fprintf(stdout, " --     p_sign_posn        = %d\n", locale_info->lconv.p_sign_posn);
    fprintf(stdout, " --     n_sign_posn        = %d\n", locale_info->lconv.n_sign_posn);
    fprintf(stdout, " -- International formatting\n");
    fprintf(stdout, " --     int_frac_digits    = %d\n", locale_info->lconv.int_frac_digits);
    fprintf(stdout, " --     int_p_cs_precedes  = %d\n", locale_info->lconv.int_p_cs_precedes);
    fprintf(stdout, " --     int_n_cs_precedes  = %d\n", locale_info->lconv.int_n_cs_precedes);
    fprintf(stdout, " --     int_p_sep_by_space = %d\n", locale_info->lconv.int_p_sep_by_space);
    fprintf(stdout, " --     int_n_sep_by_space = %d\n", locale_info->lconv.int_n_sep_by_space);
    fprintf(stdout, " --     int_p_sign_posn    = %d\n", locale_info->lconv.int_p_sign_posn);
    fprintf(stdout, " --     int_n_sign_posn    = %d\n", locale_info->lconv.int_n_sign_posn);
}

void show_usage (FILE * stream) {
    char * exename = "localeinfo ABBR";
    fprintf(stream,
            "Usage: %s\n"
            "    Print properties of the locale whose abbreviation is ABBR.\n",
            exename);
}
