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


    }while(!endgame());

    free_map(&m);

}

void move(char direction)
{
    m.matrix[hero.x][hero.y] = '.';

    switch (direction)
    {
    case 'a':
        hero.y --;
        break;
    
    case 'w':
        hero.x --;
        break;

    case 's':
        hero.x ++;
        break;        

    case 'd':
        hero.y ++;
        break;

    }
    m.matrix[hero.x][hero.y] = '@';
}

int endgame()
{
    return 0;
}