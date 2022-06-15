#include <stdio.h>
#include <stdlib.h>
#define COUNT_OF(array) (sizeof(array)/sizeof(array[0]))

struct point { int x; int y;};

void point_print(const struct point *this)   
{
        printf(
        "(%d,%d)\n", 
        this->x, 
        this->y        );
}

void points_dump(const struct point points[], int nelem)
{
        for (int i = 0; i < nelem; i++)
                point_print(&points[i]);
}

int main(void)
{
        struct point points[] = {
                { .x = 13, .y = 5  },
                { .x = -3, .y = 9  },
                { .x = 9,  .y = 1  },
                { .x = 3,  .y = -2 },
                { .x = 0,  .y = 19 },
        };

        points_dump(points, COUNT_OF(points));

        return 0;
}

// cc -o struct struct.c && ./struct