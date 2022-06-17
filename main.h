#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

#define HERO '@'
#define GHOST 'G'

#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

void move(char direction);
int endgame();
void ghosts();
int ghost_movement(int x_origin, int y_origin, int* x_final, int* y_final);

