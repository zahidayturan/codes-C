// İsmet Zahid AYTURAN - 21060607 - OMÜ Bilgisayar Müh.
// Algoritmalar Dersi Hash Veri Yapısının Uygulanması Ödevi
// 01.05.2023

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7 // Hash tablosunun boyutu
#define MAX_HEAP_SIZE 100 // Maksimum heap boyutu

struct Hash {
    int key;
    int value;
};

struct Heap {
    struct Hash array[MAX_HEAP_SIZE];
    int size;
};

int hash(int key) {
    return key % MAX_SIZE; // Mod 7 ile hashing
}

void heapMax(struct Heap* heap, int index) {
    int biggest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->array[left].value > heap->array[biggest].value) {
        biggest = left;
    }
    if (right < heap->size && heap->array[right].value > heap->array[biggest].value) {
        biggest = right;
    }
    if (biggest != index) {
        struct Hash temp = heap->array[index];
        heap->array[index] = heap->array[biggest];
        heap->array[biggest] = temp;
        heapMax(heap, biggest);
    }
}

void insertToHeap(struct Heap* heap, int key, int value) {
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Heap doldu.\n");
        return;
    }
    int index = heap->size;
    heap->array[index].key = key;
    heap->array[index].value = value;
    while (index != 0 && heap->array[(index-1)/2].value < heap->array[index].value) {
        struct Hash temp = heap->array[index];
        heap->array[index] = heap->array[(index-1)/2];
        heap->array[(index-1)/2] = temp;
        index = (index-1)/2;
    }
    heap->size++;
}

struct Hash deleteMax(struct Heap* heap) {
    struct Hash max = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    heap->size--;
    heapMax(heap, 0);
    return max;
}

void insertToHashTable(struct Heap* hashTable[], int key, int value) {
    int hashIndex = hash(key);
    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = (struct Heap*) malloc(sizeof(struct Heap));
        hashTable[hashIndex]->size = 0;
    }
    insertToHeap(hashTable[hashIndex], key, value);
}

void printHashTable(struct Heap* hashTable[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d: ", i);
        if (hashTable[i] == NULL) {
            printf("NULL\n");
            continue;
        }
        while (hashTable[i]->size > 0) {
            struct Hash max = deleteMax(hashTable[i]);
            printf("(%d, %d) ", max.key, max.value);
        }
        printf("\n");
    }
}

int main() {
    struct Heap* hashTable[MAX_SIZE] = { NULL };
    insertToHashTable(hashTable, 7, 2);
    insertToHashTable(hashTable, 4, 1);
    insertToHashTable(hashTable, 9, 3);
    insertToHashTable(hashTable, 2, 4);
    insertToHashTable(hashTable, 12, 5);
    insertToHashTable(hashTable, 17, 6);
    insertToHashTable(hashTable, 23, 7);
    insertToHashTable(hashTable, 11, 8);
    insertToHashTable(hashTable, 8, 9);
    printHashTable(hashTable);
    return 0;
}
