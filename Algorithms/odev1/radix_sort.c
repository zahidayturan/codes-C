#include<stdio.h>

//Dizinin en büyük elemanını buluyoruz
int getMaxNum (int array[], int n){
   int max = array[0];
   for (int i = 1; i < n; i++)
      if (array[i] > max)
         max = array[i];
   return max;
}

//Genel Sıralama Algoritması
void radixSort (int array[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divider = 1, lar, pass;
   lar = getMaxNum (array, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (array[i] / divider) % 10;
         bucket[r][bucket_cnt[r]] = array[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            array[i] = bucket[k][j];
            i++;
         }
      }
      divider *= 10;
      printf ("Sıralanan basamak %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", array[i]);
      printf ("\n");
   }
}

int main (){
   int i;
   int array[10] = {250, 135, 15, 99, 119, 200, 87, 9, 63, 11};
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