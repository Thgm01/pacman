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
void print_map(MAP* m);
void free_map(MAP* m);
void find_in_map(MAP* m, POS* p, char c);
int is_empty(MAP* m, int x, int y);
void move_on_the_map(MAP* m, int x_origin, int y_origin, int x_final, int y_final);
void copy_map(MAP* copy, MAP* origin);

