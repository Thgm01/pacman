#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "map.h"

MAP m;
POS hero;
int have_pill = 0;

void main()
{
    read_map(&m);
    find_in_map(&m, &hero, '@');

    do
    {   
        printf("Have Pill: %s\n\n", (have_pill ? "YES" : "NO"));

        print_map(&m);

        char command;
        scanf(" %c", &command);
        move(command);
        if(command == BOMB) explode_pill();
        ghosts();


    }while(!endgame());

    free_map(&m);

}

void move(char direction)
{
    int next_x = hero.x;
    int next_y = hero.y;

    switch (direction)
    {
    case LEFT:
        next_y --;
        break;
    
    case UP:
        next_x --;
        break;

    case DOWN:
        next_x ++;
        break;        

    case RIGHT:
        next_y ++;
        break;
    default:
        return;
        break;
    }

    if(!can_move(&m, HERO, next_x, next_y))
        return;

    if(is_character(&m, PILL, next_x, next_y))
    {
        have_pill = 1;
    }
    
    move_on_the_map(&m, hero.x, hero.y, next_x, next_y);
    hero.x = next_x;
    hero.y = next_y;
}

int endgame()
{
    POS position;
    int find_hero = find_in_map(&m, &position, HERO);
    return !find_hero;
}

void ghosts()
{
    MAP copy;

    copy_map(&copy, &m);

    for(int i=0; i<m.lines; i++)
    {
        for(int j=0; j<m.columns; j++)
        {
            if(copy.matrix[i][j] == GHOST)
            {
                int x_final;
                int y_final;

                int find = ghost_movement(i,j, &x_final, &y_final);
                
                if(find)
                {
                    move_on_the_map(&m, i, j, x_final, y_final);
                }
            }
        }
    }
    free_map(&copy);
}

int ghost_movement(int x_origin, int y_origin, int* x_final, int* y_final)
{
    int options[4][2]=
    {
        {x_origin, y_origin+1},
        {x_origin+1, y_origin},
        {x_origin, y_origin-1},
        {x_origin-1, y_origin}
    };

    srand(time(NULL));
    for(int i=0; i<10; i++)
    {
        int position = rand() % 4;

        if(can_move(&m, GHOST, options[position][0], options[position][1]))
        {
            *x_final = options[position][0];
            *y_final = options[position][1];
            return 1;
        }
    }
    return 0;
}

void explode_pill()
{
    if(!have_pill) return;
    explode_pill_directions(hero.x, hero.y, 0, 1, 3);
    explode_pill_directions(hero.x, hero.y, 0, -1, 3);
    explode_pill_directions(hero.x, hero.y, 1, 0, 3);
    explode_pill_directions(hero.x, hero.y, -1, 0, 3);

    have_pill = 0;
}

void explode_pill_directions(int x, int y, int sum_x, int sum_y, int qtd)
{
    if(qtd == 0 || is_wall(&m, x+sum_x, y+sum_y)) return;
    m.matrix[x+sum_x][y+sum_y] = '.';

    explode_pill_directions(x+sum_x, y+sum_y, sum_x, sum_y, qtd - 1);

}