#include <stdio.h>

int ara(int[], int, int);
int main() {
	int dizi[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	printf("%d\n", ara(dizi, boyut, 26));
	printf("%d\n", ara(dizi, boyut, 6));
	printf("%d\n", ara(dizi, boyut, 3));
	return 0;
}

int ara(int dizi[], int N, int aranan) {
	int bas = 0;
	int son = N - 1;
	while(bas <= son) {
		int orta = (bas + son) / 2;
		if(dizi[orta] == aranan)
			return orta;
		else if(dizi[orta] > aranan) // sol kisim
			son = orta - 1;
		else                         // sag kisim
			bas = orta + 1;
	}
	return -1;
}
