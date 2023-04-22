#include <stdio.h>

int* bubble(int *, int);
int main() {
	int dizi[] = {8, 5, 2, 4, 6, 1};
	int i;
	for(i = 0; i < 6; i++)
		printf("%d", *(dizi + i));
	int *p = bubble(dizi, 6);
	printf("\n");
	for(i = 0; i < 6; i++)
		printf("%d", *(p + i));
	return 0;
}

int* bubble(int *A, int N) {
	int i, j;
	for(i = N - 1; i >= 1; i--)
		for(j = 1; j <= i; j++)
			if(A[j - 1] > A[j]) {
				int gecici = A[j - 1];
				A[j - 1] = A[j];
				A[j] = gecici;
			}
	return A;
}
