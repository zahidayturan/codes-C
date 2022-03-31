#include <stdio.h>
// sayı üssü 2
int main() {
 
    int a,  i=0 , b=0 ; 
 
    printf("Sayiyi Giriniz: ");
    scanf("%d", &a);
        printf("n           n^2\n");
        printf("---------------\n");
    while (i < a)
    {    i++; 
        b = (i * i); 
 
    printf("%2d\t %5d\n", i, b);
    }

    return 0;
}