#ifndef _MAP_H_
#define _MAP_H_

struct map //agroup realated variables
{
    char** matrix;
    int lines, columns;
};
typedef struct map MAP; // cread "MAP" as a surname for "struct map"

typedef struct position
{
    int x;
    int y;
} POS;

void read_map(MAP* m);
void map_alloc(MAP* m);
void free_map(MAP* m);
int find_in_map(MAP* m, POS* p, char c);
int is_empty(MAP* m, int x, int y);
void move_on_the_map(MAP* m, int x_origin, int y_origin, int x_final, int y_final);
void copy_map(MAP* copy, MAP* origin);
int can_move(MAP* m, char character, int x, int y);
int is_character (MAP* m, char character, int x, int y);
int is_wall(MAP* m, int x, int y);

#endif