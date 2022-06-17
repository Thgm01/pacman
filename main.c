#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "map.h"

MAP m;
POS hero;

void main()
{
    read_map(&m);
    find_in_map(&m, &hero, '@');

    do
    {
        print_map(&m);

        char command;
        scanf(" %c", &command);
        move(command);
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