#include<stdio.h>

void task(int *x, int *y)
{
        *x = *x + 1;
        *y = *y + 1;
        
}

int main(void)
{
        int x = 19, y = 42;

        printf("before: a = %d, b = %d\n", x, y);

        task(&x, &y);

        printf("before: a = %d, b = %d\n", x, y);

        return 0;
}

// cc     pointer.c   -o pointer && ./pointer

// & görünce adresi * görünce içeriği