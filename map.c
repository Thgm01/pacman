#include <stdio.h>
#include <stdlib.h>
#include "map.h"



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

void print_map(MAP* m)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", m->matrix[i]);
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
