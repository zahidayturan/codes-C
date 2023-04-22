#include <stdio.h>

int* selection(int *, int);
int main() {
	int dizi[] = {5, 2, 4, 6, 1, 3};
	int i;
	for(i = 0; i < 6; i++)
		printf("%d", *(dizi + i));
	int *p = selection(dizi, 6);
	printf("\n");
	for(i = 0; i < 6; i++)
		printf("%d", *(p + i));
	return 0;
}

int* selection(int *A, int N) {
	int i, j, pos, min;
	for(i = 0; i < N - 1; i++) {
		min = A[i];
		pos = i;
		for(j = i + 1; j < N; j++) {
			if(A[j] < min) {
				min = A[j];
				pos = j;
			}
		}
		if(pos != i) {
			A[pos] = A[i];
			A[i] = min;
		}
	}
	return A;
}
