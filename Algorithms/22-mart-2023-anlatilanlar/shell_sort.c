#include <stdio.h>

int* shell(int *, int);
int main() {
	int dizi[] = {8, 5, 2, 4, 6, 1, 3, 9};
	int i;
	for(i = 0; i < 8; i++)
		printf("%d", *(dizi + i));
	int *p = shell(dizi, 8);
	printf("\n");
	for(i = 0; i < 8; i++)
		printf("%d", *(p + i));
	return 0;
}

int* shell(int *A, int N) {
	int i, j, t, k, fark;
	int arttirim[] =  {1, 3, 7, 15}; // 2, 4, 6, 8 Shell'in onerdigi arttirim dizisi
	for(k = 0; k < 4; k++) {
		fark = arttirim[k];
		for(j = fark; j < N; j++) {
			t = A[j];
			i = j - fark;
			while(i >= 0 && A[i] > t) {
				A[i + fark] = A[i];
				i = i - fark;
			}
			A[i + fark] = t;
		}
	}
	return A;
}
