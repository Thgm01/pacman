#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char** map;
int lines, columns;

void main()
{
    read_map();

    do
    {
        print_map();

        char command;
        scanf(" %c", &command);

        move(command);


    }while(!endgame());

    free_map();

}



void read_map()
{
    FILE* fp = fopen("map.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &lines, &columns); //scan the number os lines and columns

    map_alloc();
    
    for(int i = 0; i < 5; i++)
    {
        fscanf(fp,"%s", map[i]);
    }
    fclose(fp);
}

void map_alloc() //allocation suficient memory for the map
{ 
    map = malloc(sizeof(char*) * lines); //alloc the number of pointers (lines) 
    for(int i = 0; i < lines; i++)
    {
        map[i] = malloc(sizeof(char) * columns+1); //alloc the number of chars in the pointer (columns)
    }
}

void print_map()
{
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }
}

void free_map() //frees the memory allocated by the map
{
    for(int i = 0; i < lines; i++)
    {
        free(map[i]);
    }
    free(map);
}

void move(char direction)
{
    int x, y;

    //find the pacman position
    for(int i = 0; i < lines; i ++)
    {
        for(int j = 0; j  < columns; j++)
        {
            if(map[i][j] == '@')
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
        map[x][y-1] = '@';
        break;
    
    case 'w':
        map[x-1][y] = '@';
        break;

    case 's':
        map[x+1][y] = '@';
        break;        

    case 'd':
        map[x][y+1] = '@';
        break;

    }
    map[x][y] = '.';
}

int endgame()
{
    return 0;
}