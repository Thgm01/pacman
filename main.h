#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define BOMB 'b'

#define HERO '@'
#define GHOST 'G'
#define PILL 'P'

#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define EMPTY '.'

void move(char direction);
int endgame();
void ghosts();
int ghost_movement(int x_origin, int y_origin, int* x_final, int* y_final);
void explode_pill_directions(int x, int y, int sum_x, int sum_y, int qtd);
void explode_pill();

