
#include <stdio.h>

struct point {
        int x;
        int y;
};

int main(void)
{
        struct point a = { .x = 3, .y = 5 };

        printf("(%d,%d)\n", a.x, a.y);

        return 0;
}
