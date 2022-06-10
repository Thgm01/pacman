#include <stdio.h>
#include <stdlib.h>


void main()
{
    char map[5][11];

    FILE* fp = fopen("map.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
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

}