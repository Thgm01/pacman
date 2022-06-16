#include <stdio.h>
#include <stdlib.h>
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

    if(!is_empty(&m, next_x, next_y))
        return;

    
    move_on_the_map(&m, hero.x, hero.y, next_x, next_y);
    hero.x = next_x;
    hero.y = next_y;
}

int endgame()
{
    return 0;
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
                printf("here");
                if(is_empty(&m, i, j+1))
                {
                    printf("here");
                    move_on_the_map(&m, i, j, i, j+1);
                }
            }
        }
    }
    free_map(&copy);
}