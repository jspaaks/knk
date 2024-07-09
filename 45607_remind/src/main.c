#include "vstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line (char str[], int n);

int main (void) {
    struct vstring * reminders[MAX_REMIND];
    char day_str[3];
    char msg_str[MSG_LEN + 1];
    int day;
    int i;
    int num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            fprintf(stderr, "-- No space left --\n");
            break;
        }

        fprintf(stderr, "Enter day and reminder: ");
        int n = scanf("%2d", &day);
        if (n != 1) {
            fprintf(stdout, "Problem parsing the input. Here's what was entered so far:\n");
            day = 0;
        }

        if (day == 0) {
            break;
        }

        snprintf(day_str, 3 * sizeof(char), "%2d", day);

        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]->chars) < 0) {
                break;
            }
        }
        for (int j = num_remind; j > i; j--) {
            reminders[j] = reminders[j - 1];
        }

        int nchars = strlen(day_str) + strlen(msg_str);
        struct vstring * reminder = malloc(sizeof(struct vstring) + nchars + 1);
        if (reminder == NULL) {
            fprintf(stderr, "Something went wrong allocating memory for reminder '%s %s'.\n", day_str, msg_str);
            break;
        }
        reminder->nchars = nchars;
        strcpy(reminder->chars, day_str);
        strcat(reminder->chars, msg_str);
        reminders[i] = reminder;
        num_remind++;
    }

    fprintf(stdout, "\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        fprintf(stdout, " %s\n", reminders[i]->chars);
        free(reminders[i]);
    }

    return 0;
}

int read_line (char str[], int n) {
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
