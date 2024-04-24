#ifndef ANSICMDS_H
#define ANSICMDS_H

void clear_screen (void);
void move_cursor (int, int);
void show_screen_create_part (void);



void clear_screen (void);
void move_cursor_down (int nlines);
void move_cursor_left (int ncols);
void move_cursor_right (int ncols);
void move_cursor_to_pos (int irow, int icol);
void move_cursor_up (int nlines);


#endif


