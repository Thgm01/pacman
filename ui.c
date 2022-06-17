#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "map.h"
#include "ui.h"

char wall_drawing[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char hero_drawing[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char ghost_drawing[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char pill_drawing[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char empty_drawing[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void print_part(char draw[4][7], int part)
{
    printf("%s", draw[part]);
}

void print_map(MAP* m)
{
    for(int i = 0; i < m->lines; i++)
    {
        for(int parts=0; parts < 4; parts++)
        {
            for(int j=0; j< m->columns; j++)
            {
                switch (m->matrix[i][j])
                {
                case GHOST:
                    print_part(ghost_drawing, parts);                    
                    break;
                
                case HERO:
                    print_part(hero_drawing, parts);                    
                    break;

                case PILL:
                    print_part(pill_drawing, parts);                    
                    break;

                case VERTICAL_WALL:
                case HORIZONTAL_WALL:
                    print_part(wall_drawing, parts);                    
                    break;

                case EMPTY:
                    print_part(empty_drawing, parts);                    
                    break;
                }
            }
            printf("\n");
        }

    }
}