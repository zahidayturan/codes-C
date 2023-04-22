#include <stdio.h>

void sirala(int[], int, int); 
void birlestir(int[], int, int, int);
void yazdir(int[], int);

int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10, 5};  
    int boyut = sizeof(a) / sizeof(a[0]);
    yazdir(a, boyut);
    sirala(a, 0, boyut - 1); 
    yazdir(a, boyut);
    return 0;
}

void sirala(int dizi[], int sol, int sag) {
    int orta;
    if(sol < sag)
    {
        orta = (sol + sag) / 2;
        sirala(dizi, sol, orta);
        sirala(dizi, orta + 1, sag);
        birlestir(dizi, sol, orta, sag);
    }
}

void birlestir(int dizi[], int sol, int orta, int sag) {
    int i, j, k;
    int n1 = orta - sol + 1;
    int n2 = sag - orta;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) //n1
        L[i] = dizi[sol + i];
    for (j = 0; j < n2; j++) //n2
        R[j] = dizi[orta + 1 + j];
    i = 0;
    j = 0;
    k = sol;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) {
            dizi[k] = L[i];
            i++;
        }
        else {
            dizi[k] = R[j];
            j++;
        }
        k++;
    } 
    while (i < n1) {
        dizi[k] = L[i];
        i++;
        k++;
    } 
    while (j < n2) {
        dizi[k] = R[j];
        j++;
        k++;
    }
}

void yazdir(int dizi[], int boyut) {
    int i;
    for(i = 0; i < boyut; i++){
        printf("%d ", dizi[i]);
    }
    printf("\n");
}
