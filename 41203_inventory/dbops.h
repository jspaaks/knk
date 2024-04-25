#ifndef DBOPS_H
#define DBOPS_H

#define NAME_LEN 16

typedef struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} Part;


int find_part (int *, Part (*)[], int);
void insert (int *, Part (*)[], int);
void search (int *, Part (*)[]);
void update (int *, Part (*)[]);
void print (int *, Part (*)[]);


#endif
