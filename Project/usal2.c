#include <stdio.h>
#include <math.h>
// 2 üssü sayı
int main() {
 
    int a,  i=0 , b=0 ; 
 
    printf("Sayiyi Giriniz: ");
    scanf("%d", &a);
        printf("n           2^n\n");
        printf("---------------\n");
    while (i < a)
    {    i++; 
        b = pow(2, i); 
 
    printf("%2d\t %5d\n", i, b);
    }

    return 0;
}