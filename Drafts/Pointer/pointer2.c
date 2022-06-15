#include<stdio.h>

void swap(int *x, int *y)
{
        int ara;
        ara = *x;
        *x = *y;
        *y = ara;
        
}

int main(void)
{
        int x = 19, y = 42;

        printf("before: a = %d, b = %d\n", x, y);

        swap(&x, &y);

        printf("before: a = %d, b = %d\n", x, y);

        return 0;
}

// cc     pointer2.c   -o pointer2 && ./pointer2

// & görünce adresi * görünce içeriği