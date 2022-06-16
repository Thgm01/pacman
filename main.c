#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "map.h"

MAP m;

void main()
{
    read_map(&m);

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
    int x, y;

    //find the pacman position
    for(int i = 0; i < m.lines; i ++)
    {
        for(int j = 0; j  < m.columns; j++)
        {
            if(m.matrix[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction)
    {
    case 'a':
        m.matrix[x][y-1] = '@';
        break;
    
    case 'w':
        m.matrix[x-1][y] = '@';
        break;

    case 's':
        m.matrix[x+1][y] = '@';
        break;        

    case 'd':
        m.matrix[x][y+1] = '@';
        break;

    }
    m.matrix[x][y] = '.';
}

int endgame()
{
    return 0;
}