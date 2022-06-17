#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "main.h"
#include "ui.h"

void read_map(MAP* m)
{
    FILE* fp = fopen("map.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &(m->lines), &(m->columns)); //scan the number os lines and columns

    map_alloc(m); // m is a pointer 
    
    for(int i = 0; i < 5; i++)
    {
        fscanf(fp,"%s", m->matrix[i]);
    }
    fclose(fp);
}

void map_alloc(MAP* m) //allocation suficient memory for the map
{ 
    m->matrix = malloc(sizeof(char*) * m->lines); //alloc the number of pointers (lines) 
    for(int i = 0; i < m->lines; i++)
    {
        m->matrix[i] = malloc(sizeof(char) * m->columns+1); //alloc the number of chars in the pointer (columns)
    }
}

void free_map(MAP* m) //frees the memory allocated by the map
{
    for(int i = 0; i < m->lines; i++)
    {
        free(m->matrix[i]);
    }
    free(m->matrix);
}

int find_in_map(MAP* m, POS* p, char c)
{
    //find the pacman position
    for(int i = 0; i < m->lines; i ++)
    {
        for(int j = 0; j  < m->columns; j++)
        {
            if(m->matrix[i][j] == c)
            {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
}

int is_empty(MAP* m, int x, int y)
{
    return m->matrix[x][y] == '.';
}

void move_on_the_map(MAP* m, int x_origin, int y_origin, int x_final, int y_final)
{
    char character = m->matrix[x_origin][y_origin];
    m->matrix[x_final][y_final] = character;
    m->matrix[x_origin][y_origin] = '.';
}

void copy_map(MAP* copy, MAP* origin)
{
    copy->lines = origin->lines;
    copy->columns = origin->columns;

    map_alloc(copy);
    for (int i=0; i<origin->lines; i++)
    {
        strcpy(copy->matrix[i], origin->matrix[i]);
    }

}

int can_move(MAP* m, char character, int x, int y)
{
    return
        !is_wall(m, x, y) &&
        !is_character(m, character, x, y);

}

int is_wall(MAP* m, int x, int y)
{
    return
        m->matrix[x][y] == VERTICAL_WALL ||
        m->matrix[x][y] == HORIZONTAL_WALL;

}

int is_character (MAP* m, char character, int x, int y)
{
    return m->matrix[x][y] == character;
}
