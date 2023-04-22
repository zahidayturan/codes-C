#include <stdio.h>

int* insertion(int *, int);
int main() {
	// 1, 2, 3, 4, 5
	int dizi[] = {8, 5, 2, 4, 6, 1, 3, 9};
	int i;
	for(i = 0; i < 8; i++)
		printf("%d", *(dizi + i));
	int *p = insertion(dizi, 8);
	printf("\n");
	for(i = 0; i < 8; i++)
		printf("%d", *(p + i));
	return 0;
}

int* insertion(int *A, int N) {
	int i, j, b;
	for(i = 1; i <= N - 1; i++) {
		b = A[i]; j = i;
		while(j > 0 && A[j - 1] > b) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = b;
	}
	return A;
}
