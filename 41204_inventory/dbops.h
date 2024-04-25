#ifndef DBOPS_H
#define DBOPS_H

#define NAME_LEN 16

typedef struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    int price;
} Part;


int find_part (const int *, Part (*)[], const int);
void insert (int *, Part (*)[], const int);
void search (const int *, Part (*)[]);
void update (const int *, Part (*)[]);
void print (const int *, Part (*)[]);


#endif
