#include <stdio.h>

int main(void)
{
        int a, b, sum;

        printf("Sayı 1? ");
        printf("scanf %d döndü\n", scanf("%d", &a));

        printf("Sayı 2? ");
        printf("scanf %d döndü\n", scanf("%d", b)); /* HATA: &b yerine b yazılmış */

        sum = a + b;
        printf("Toplam: %d\n", sum);

        return 0;
}
