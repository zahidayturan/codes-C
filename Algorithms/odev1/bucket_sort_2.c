// İsmet Zahid AYTURAN - 21060607 - OMÜ Bilgisayar Müh.
// Algoritmalar Dersi Sıralama Algoritmalarının Pekiştirilmesi Ödevi
// 20.04.2023

#include <stdio.h>
#include <stdlib.h>

#define ARRAYLENGTH 10   // Dizi Uzunluğu
#define BUCKETCOUNT 6  // Kova Sayısı
#define BUCKETSIZE 10  // Her kovanın alabileceği eleman sayısı

//Kovaların sıralanmamış halini de görebilmek için struct
struct Bucket {
    int count;
    int* value;
};

// Genel Sıralama Algoritması
void bucketSort(int array[]) {
    int i, j, k;
    struct Bucket buckets[BUCKETCOUNT];

    // Kovaların hazırlanması
    for (i = 0; i < BUCKETCOUNT; ++i) {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * ARRAYLENGTH);
    }

    // Dizi elemanlarını uygun olduğu kovaya eklenmesi
    for (i = 0; i < ARRAYLENGTH; ++i) {
        for (j = 0; j < BUCKETCOUNT; ++j) {
            if (array[i] >= j * BUCKETSIZE && array[i] <= (j + 1) * BUCKETSIZE - 1) {
                buckets[j].value[buckets[j].count++] = array[i];
                break;
            }
        }
    }

    // Henüz sıralanmamış kovaların yazdırılması
    printf("Henüz sıralanmamış kovalar:\n");
    for (i = 0; i < BUCKETCOUNT; ++i) {
        printf("Kova %d: ", i);
        for (j = 0; j < buckets[i].count; ++j) {
            printf("%d ", buckets[i].value[j]);
        }
        printf("\n");
    }

    // Kovaların kendi içerisinde sıralanması (bubble sort ile)
    for (i = 0; i < BUCKETCOUNT; ++i) {
        for (j = 0; j < buckets[i].count - 1; ++j) {
            for (k = 0; k < buckets[i].count - j - 1; ++k) {
                if (buckets[i].value[k] > buckets[i].value[k + 1]) {
                    int temp = buckets[i].value[k];
                    buckets[i].value[k] = buckets[i].value[k + 1];
                    buckets[i].value[k + 1] = temp;
                }
            }
        }
    }

    // Sıralanmış kovaların tek tek yazdırılması
    printf("Sıralanmış kovalar:\n");
    for (i = 0; i < BUCKETCOUNT; ++i) {
        printf("Kova %d: ", i);
        for (j = 0; j < buckets[i].count; ++j) {
            printf("%d ", buckets[i].value[j]);
        }
        printf("\n");
    }

    // Sıralanmış kovalardan son durumu alarak sıralanmış dizinin oluşturulması
    for (i = 0, j = 0; i < BUCKETCOUNT; ++i) {
        for (k = 0; k < buckets[i].count; ++k) {
            array[j++] = buckets[i].value[k];
        }
    }

    // Hafızanın free edilmesi
    for (i = 0; i < BUCKETCOUNT; ++i) {
        free(buckets[i].value);
    }
}

int main() {
    int array[] = {5, 13, 21, 11, 9, 1, 24, 29, 7, 3};
    //int array[] = {46, 40, 33, 15, 11, 7, 24, 56, 1, 20};
    int n = sizeof(array) / sizeof(array[0]); //10

    printf ("Sıralanacak olan dizi: ");
    for (int i = 0; i < n; i++)
      printf ("%d ", array[i]);
    printf ("\n");
    printf("Oluşturalacak kova sayısı: %d \n",BUCKETCOUNT);
    printf("Bir kovanın en fazla alabileceği eleman sayısı: %d \n",BUCKETSIZE);

    printf("Sıralamadan önce: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Elemanlar uygun oldukları kovaya aktarılıyor!\n");
    bucketSort(array);
    printf("Elemanlar sıralandıkları kovalardan diziye çekiliyor!\n");
    printf("Sıralamadan sonra: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
