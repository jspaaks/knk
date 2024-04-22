#include <stdio.h>
#include "string.h"


typedef struct {
    int id;
    char name[25];
} Part;


void test_structs_1 (void);
void test_structs_2 (void);
void test_structs_3 (void);
void test_structs_4 (void);
void test_structs_5 (void);
void test_structs_6 (void);
void test_structs_7 (void);
void print_part (Part *part);


char hrule[] = "------------------------------\n";


int main (void) {

    printf("structs\n%s", hrule);
    test_structs_1();
    test_structs_2();
    test_structs_3();
    test_structs_4();
    test_structs_5();
    test_structs_6();
    test_structs_7();

}


void test_structs_1 (void) {
    printf("struct definition and immediate initialization.\n");
    struct {
        int id;
        char name[25];
    } part = {1, "bearing"};
    printf("part {\n  id: %d\n  name: %s\n}\n", part.id, part.name);
    printf("%s", hrule);
}


void test_structs_2 (void) {
    printf("struct definition and immediate multiple initialization.\n");
    struct {
        int id;
        char name[25];
    } part1 = {2, "bearing"}, part2 = {3, "piston"};

    printf("part1 {\n  id: %d\n  name: %s\n}\n", part1.id, part1.name);
    printf("part2 {\n  id: %d\n  name: %s\n}\n", part2.id, part2.name);
    printf("%s", hrule);
}


void test_structs_3 (void) {
    printf("struct definition via struct tag.\n");
    struct part_tag {
        int id;
        char name[25];
    };
    struct part_tag part1 = {4, "header"};
    printf("part1 {\n  id: %d\n  name: %s\n}\n", part1.id, part1.name);
    printf("%s", hrule);
}


void test_structs_4 (void) {
    printf("struct definition via typedef.\n");
    Part part1 = {5, "block"};
    Part part2 = {6, "filter"};
    printf("part1 {\n  id: %d\n  name: %s\n}\n", part1.id, part1.name);
    printf("part2 {\n  id: %d\n  name: %s\n}\n", part2.id, part2.name);
    printf("%s", hrule);
}

void test_structs_5 (void) {
    printf("struct definition via typedef; passing to a function and referencing fields from inside.\n");
    Part part1 = {7, "head"};
    print_part(&part1);
    Part part2 = {8, "gasket"};
    print_part(&part2);
}


void test_structs_6 (void) {
    printf("struct definition via typedef; partial initialization via named member.\n");
    Part part = {.id = 9};
    print_part(&part);
}


void test_structs_7 (void) {
    printf("struct definition via typedef; partial initialization via named member in subsequent steps.\n");
    Part part;
    print_part(&part);
    strcpy(part.name, "valve");
    print_part(&part);
    part.id = 10;
    print_part(&part);
}


void print_part (Part * part) {
    printf("Part {\n  id: %d\n  name: %s\n}\n", part->id, (*part).name);
    printf("%s", hrule);
}

