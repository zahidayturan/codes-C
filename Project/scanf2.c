#include <stdio.h>

int main(void)
{
        int a, b, c, r;

        printf("Bir sayı? ");
        r = scanf("%d", &a);
        printf("Okunanlar: %d, scanf return değeri: %d\n", a, r);

        printf("İki sayı? ");
        r = scanf("%d %d", &a, &b);
        printf("Okunanlar: %d %d, scanf return değeri: %d\n", a, b, r);

        printf("Üç sayı? ");
        r = scanf("%d %d %d", &a, &b, &c);
        printf("Okunanlar: %d %d %d, scanf return değeri: %d\n", a, b, c, r);

        return 0;
}
