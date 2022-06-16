struct map //agroup realated variables
{
    char** matrix;
    int lines, columns;
};
typedef struct map MAP; // cread "MAP" as a surname for "struct map"

void read_map(MAP* m);
void map_alloc(MAP* m);
void print_map(MAP* m);
void free_map(MAP* m);

