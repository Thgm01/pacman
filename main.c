#include <stdio.h>
#include <stdlib.h>

char** map;
int lines, columns;

void main()
{


    FILE* fp = fopen("map.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &lines, &columns); //scan the number os lines and columns

    //allocation suficient memory for the map 
    map = malloc(sizeof(char*) * lines); //alloc the number of pointers (lines) 
    for(int i = 0; i < lines; i++)
    {
        map[i] = malloc(sizeof(char) * columns+1); //alloc the number of chars in the pointer (columns)
    }
    

    for(int i = 0; i < 5; i++)
    {
        fscanf(fp,"%s", map[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }
    fclose(fp);

    for(int i = 0; i < lines; i++)
    {
        free(map[i]);
    }
    free(map);

}