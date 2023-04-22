// İsmet Zahid AYTURAN - 21060607 - OMÜ Bilgisayar Müh.
// Algoritmalar Dersi Sıralama Algoritmalarının Pekiştirilmesi Ödevi
// 20.04.2023

#include <stdio.h>
#include <stdlib.h>

// Kova sıralama (bucket sort) algoritmasını kullanarak verilen dizi içindeki sayıları taban sıralama işlemine göre sıralar
void bucketSort(int array[], int n, int cnt) {
    int i, 
    count[10] = {0};
    int *output = (int*)malloc(n*sizeof(int));
    
    // Kova sayısını belirliyoruz
    for (i = 0; i < n; i++)
        count[(array[i]/cnt)%10]++;
    
    // Kova sayılarını işleme alıyoruz
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    
    // Kovaları sıralıyoruz
    for (i = n-1; i >= 0; i--) {
        output[count[(array[i]/cnt)%10]-1] = array[i];
        count[(array[i]/cnt)%10]--;
    }
    
    // Yeni düzenlenmiş diziyi gönderiyoruz
    for (i = 0; i < n; i++)
        array[i] = output[i];
    
    free(output);
}

// Taban Sıralama algoritması
void radixSort(int array[], int n) {
    int i, 
    max = array[0];
    
    // En büyük sayıyı bululuyoruz
    for (i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    
    // Basamak değerlerine göre kova sıralama işlemine gönderiyoruz
    for (int cnt = 1; max/cnt > 0; cnt *= 10) {
        bucketSort(array, n, cnt);

        // Her basamak için sıralanmış diziyi ekrana yazdırırıyoruz
        printf("Basamak %d: ", cnt);
        for (i = 0; i < n; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}

int main() {
    int array[] = {165, 299, 42, 12, 332, 722, 100, 9, 88, 69};
    int n = sizeof(array) / sizeof(array[0]);
     printf ("Başlangıç Dizisi : ");
     for (int i = 0; i < n; i++)
      printf ("%d ", array[i]);

    printf ("\n");

    radixSort(array, n);
    
    printf("Sıralanmış dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}
