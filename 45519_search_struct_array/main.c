#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void close_all_cmd (void);
void close_cmd (void);
void exit_cmd (void);
void new_cmd (void);
void open_cmd (void);
void print_cmd (void);
void save_all_cmd (void);
void save_as_cmd (void);
void save_cmd (void);
int search (char *);

struct {
    char * cmd_name;
    void (*cmd_pointer)(void);
} file_cmds[] = {
    {      "new",       new_cmd},
    {     "open",      open_cmd},
    {    "close",     close_cmd},
    {"close all", close_all_cmd},
    {     "save",      save_cmd},
    {  "save as",   save_as_cmd},
    { "save all",  save_all_cmd},
    {    "print",     print_cmd},
    {     "exit",      exit_cmd},
};

void close_all_cmd (void) {
    printf("close all called.\n");
}

void close_cmd (void) {
    printf("close called.\n");
}

void exit_cmd (void) {
    printf("exit called.\n");
}

void new_cmd (void) {
    printf("new called.\n");
}

void open_cmd (void) {
    printf("open called.\n");
}

void print_cmd (void) {
    printf("print called.\n");
}

void save_all_cmd (void) {
    printf("save all called.\n");
}

void save_as_cmd (void) {
    printf("save as called.\n");
}

void save_cmd (void) {
    printf("save called.\n");
}

int search (char * s0) {
    unsigned long nchars = strlen(s0);
    int ncmds = sizeof(file_cmds) / sizeof(file_cmds[0]);
    for (int i = 0; i < ncmds; i++) {
        char * s1 = file_cmds[i].cmd_name;
        if (strncmp(s0, s1, nchars) == 0) {
            return i;
        }
    }
    return -1;
}

int main (void) {
    int i = search("close all");
    if (i == -1) {
        fprintf(stderr, "Command not found.\n");
        exit(EXIT_FAILURE);
    }
    file_cmds[i].cmd_pointer();
    exit(EXIT_SUCCESS);
}
