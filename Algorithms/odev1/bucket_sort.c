#include <stdio.h>
#include <stdlib.h>

#define NARRAY 10   // Array size
#define NBUCKET 6  // Number of buckets
#define INTERVAL 5  // Each bucket capacity

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);



// GENEL SIRALAMA İŞLEMİ
void BucketSort(int arr[]) {
  int i, j;
  struct Node **buckets;

  // BELLEKTE KOVA OLUŞTURMA
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

  // BÜTÜN KOVALARI BOŞ OLARAK BELİRLEME
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = NULL;
  }

  // DİZİNİN ELEMANLARINI UYGUN OLDUKLARI KOVAYA YERLEŞTİRME
  for (i = 0; i < NARRAY; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // HER KOVAYI TEK TEK YAZDIRMA
  for (i = 0; i < NBUCKET; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  // KOVALARI KENDİ İÇERİSİNDE SIRALAMA
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  printf("-------------\n");
  printf("Bucktets after sorting\n");
  for (i = 0; i < NBUCKET; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  // KENDİ İÇERİSİNDE DE SIRALANAN KOVALARI BİR DİZİDE BİRLEŞTİRME
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

// KOVALARI KENDİ İÇERİSİNDE SIRALAMA
struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

//KOVANIN İNDEXİNİ ALMA
int getBucketIndex(int value) {
  return value / INTERVAL;
}

//DİZİ YAZDIRMA
void print(int ar[]) {
  int i;
  for (i = 0; i < NARRAY; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

// KOVALARI YAZDIRMA
void printBuckets(struct Node *list) {
  struct Node *cur = list;
  printf("ilk");
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

//TEST KODU
int main(void) {
  int array[NARRAY] = {5, 13, 21, 11, 9, 1, 24, 29, 7, 3};

  printf("Başlangıç dizisi: ");
  print(array);
  printf("-------------\n");

  BucketSort(array);
  printf("-------------\n");
  printf("Sıralanmış dizi: ");
  print(array);
  return 0;
}