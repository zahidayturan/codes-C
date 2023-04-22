#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) // max heap agac
{
    int left, right, largest;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) //siralama
{
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = { 20, 13, 34, 56, 12, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");    
    heap_sort(arr, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
