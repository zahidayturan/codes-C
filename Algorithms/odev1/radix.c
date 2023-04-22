#include <stdio.h>
#include <stdlib.h>

void radixSort(int dizi[], int n, int exp) {
    int *output = (int*)malloc(n*sizeof(int));
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(dizi[i]/exp)%10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(dizi[i]/exp)%10] - 1] = dizi[i];
        count[(dizi[i]/exp)%10]--;
    }

    for (int i = 0; i < n; i++)
        dizi[i] = output[i];

    free(output);
}
void radixSortAlgorithm(int dizi[], int n) {
    int m = dizi[0], exp;

    for (int i = 1; i < n; i++)
        if (dizi[i] > m)
            m = dizi[i];

    for (exp = 1; m/exp > 0; exp *= 10)
        radixSort(dizi, n, exp);
}
void printdizi(int dizi [], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",dizi[i]);
    }
}
int main() {
    int dizi[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(dizi)/sizeof(dizi[0]);
    
    printf("Dizinin orijinal hali: ");
    printdizi(dizi, n);
    radixSortAlgorithm(dizi, n);
    printf("\nDizinin siralanmis hali: ");
    printdizi(dizi, n);

    return 0;
}