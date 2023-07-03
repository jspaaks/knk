#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define STACKSIZE 100


// EXTERNAL VARIABLES
int contents[STACKSIZE];
int nitems = 0;

int evaluate_rpn_expression(char *);
bool is_empty (void);
bool is_full (void);
void make_empty (void);
int pop (void);
void push (int i);
void print (void);
int read(char *);


int evaluate_rpn_expression(char *expression) {
    char *p = expression;
    while (*p != '\0') {
        printf("%s\n", p);
        if (*p == ' ') {
            ;
        } else if ('0' <= *p && *p <= '9') {
            push(*p - '0');
        } else if (*p == '*') {
            int b = pop();
            int a = pop();
            push(a * b);
        } else if (*p == '/') {
            int b = pop();
            int a = pop();
            push(a / b);
        } else if (*p == '+') {
            int b = pop();
            int a = pop();
            push(a + b);
        } else if (*p == '-') {
            int b = pop();
            int a = pop();
            push(a - b);
        } else if (*p == '=') {
            break;
        } else {
            printf("Invalid input, aborting.\n");
            exit(EXIT_FAILURE);
        }
        p++;
    }
    if (nitems == 1) {
        return contents[nitems - 1];
    } else {
        printf("Stack is not scalar, aborting.\n");
        exit(EXIT_FAILURE);
    }
}

bool is_empty (void) {
    return nitems == 0;
}

bool is_full (void) {
    return nitems == STACKSIZE;
}

int main (void) {
    char expression[1000] = "";
    while (true) {
        make_empty();
        printf("Enter a reverse Polish notation expression (q to quit): ");
        read(expression);
        int result = evaluate_rpn_expression(expression);
        printf("Value of expression: %d\n", result);
    }
    return EXIT_SUCCESS;
}

void make_empty (void) {
    nitems = 0;
}

int pop (void) {
    if ( is_empty() ) {
        printf("Not enough operands in expression, aborting.\n");
        exit(EXIT_FAILURE);
    } else {
        int r = contents[nitems - 1];
        nitems -= 1;
        return r;
    }
}

void push (int i) {
    if ( is_full() ) {
        printf("Expression too complex, aborting.\n");
        exit(EXIT_FAILURE);
    } else {
        contents[nitems] = i;
        nitems += 1;
    }
}


void print (void) {
    printf("[");
    for (int i = 0; i < nitems; i++) {
        printf("%d", contents[i]);
        if (i < nitems - 1 ) {
            printf(", ");
        }
    }
    printf("]\n");
}

int read(char *expression) {
    char *p = expression;
    while (true) {
        int c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == 'q') {
            exit(EXIT_SUCCESS);
        }
        *p = c;
        p++;
    }
    return p - expression;
}
