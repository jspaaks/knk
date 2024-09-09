#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int ask_nyears (void);
double ask_original_amount (void);
double ask_yearly_rate (void);
void show_usage (FILE * stream);

unsigned int ask_nyears (void) {
    fprintf(stdout, " -- How many years? ");
    constexpr size_t cap = 4096;
    char buf[cap] = {};
    char * status = fgets(buf, cap, stdin);
    if (status == nullptr && ferror(stdin)) {
        fprintf(stderr, " -- Error reading from STDIN: %s", strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    unsigned int nyears;
    {
        int nread = sscanf(buf, "%u", &nyears);
        if (nread != 1) {
            fprintf(stderr, " -- Error parsing provided data.\n");
            exit(EXIT_FAILURE);
        }
    }
    return nyears;
}

double ask_original_amount (void) {
    fprintf(stdout, " -- How much was the original amount? ");
    constexpr size_t cap = 4096;
    char buf[cap] = {};
    char * status = fgets(buf, cap, stdin);
    if (status == nullptr && ferror(stdin)) {
        fprintf(stderr, " -- Error reading from STDIN: %s", strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    double original_amount;
    {
        int nread = sscanf(buf, "%lf", &original_amount);
        if (nread != 1) {
            fprintf(stderr, " -- Error parsing provided data.\n");
            exit(EXIT_FAILURE);
        }
    }
    return original_amount;
}

double ask_yearly_rate (void) {
    fprintf(stdout, " -- What is the yearly interest rate in percent? ");
    constexpr size_t cap = 4096;
    char buf[cap] = {};
    char * status = fgets(buf, cap, stdin);
    if (status == nullptr && ferror(stdin)) {
        fprintf(stderr, " -- Error reading from STDIN: %s", strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    double yearly_rate;
    {
        int nread = sscanf(buf, "%lf", &yearly_rate);
        if (nread != 1) {
            fprintf(stderr, " -- Error parsing provided data.\n");
            exit(EXIT_FAILURE);
        }
    }
    return yearly_rate;
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

    fprintf(stdout, "Program prompts the user for some inputs, then calculates accrued interest.\n");

    double original_amount = ask_original_amount();
    double yearly_rate = ask_yearly_rate();
    unsigned int nyears = ask_nyears();
    double with_interest = original_amount * exp(nyears * yearly_rate / 100);

    fprintf(stdout, " -- An original amount of $%.2lf plus %.2lf%% interest for %u years equals $%.2lf.\n",
            original_amount, yearly_rate, nyears, with_interest);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "accrue";
    fprintf(stream,
            " -- Usage: %s\n"
            " --    Program to calculate accrued interest.\n",
            exename);
}
