// İsmet Zahid AYTURAN - 21060607 - OMÜ Bilgisayar Müh.
// Algoritmalar Dersi Sıralama Algoritmalarının Pekiştirilmesi Ödevi
// 20.04.2023

#include <stdio.h>
#include <stdlib.h>

// Counting sort kullanarak verilen dizi için radix sort uygular
void radixSort(int array[], int n) {
    // Verilen dizinin en büyük sayısını bularak basamak sayısını hesaplıyoruz
    int maxNum = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxNum) {
            maxNum = array[i];
        }
    }
    // Basamak sayısı
    int numDigits = 0;
    while (maxNum > 0) {
        numDigits++;
        maxNum /= 10;
    }

    // Counting sort kullanarak radix sort uyguluyoruz
    int control = 1;
    int *output = (int *) malloc(n * sizeof(int));
    int *count = (int *) calloc(10, sizeof(int));
    for (int i = 0; i < numDigits; i++) {
        // Her basamak için sayıları sayıyoruz
        for (int j = 0; j < n; j++) {
            int digit = (array[j] / control) % 10;
            count[digit]++;
        }

        // Dizini her öğesini basamaklara göre topluyoruz
        for (int j = 1; j < 10; j++) {
            count[j] += count[j-1];
        }

        // Aynı basamakta ki aynı sayıları sıralıyoruz
        for (int j = n-1; j >= 0; j--) {
            int digit = (array[j] / control) % 10;
            output[count[digit]-1] = array[j];
            count[digit]--;
        }

        // Çıktı dizisine kopyalıyoruz
        for (int j = 0; j < n; j++) {
            array[j] = output[j];
        }

        // Bir sonraki basamağa geçiyoruz
        control *= 10;

        // Sayma işlemi için sayacı sıfırlıyoruz
        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }

        // Güncel diziyi yazdırıyoruz
        printf("Basamak %d: ", i+1);
        for (int j = 0; j < n; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");
    }
    free(output);
    free(count);
}

int main (){
   int i;
   int array[10] = {125, 21, 159, 63, 999, 1, 100, 9, 38, 33};
   int n = sizeof(array) / sizeof(array[0]); //10
   printf ("Başlangıç Dizisi : ");
     for (int i = 0; i < n; i++)
      printf ("%d ", array[i]);
    printf ("\n");
   radixSort (array, 10);
   printf ("Sıralanan dizi : ");
   for (i = 0; i < 10; i++)
      printf ("%d ", array[i]);
   printf ("\n");
   return 0;
}