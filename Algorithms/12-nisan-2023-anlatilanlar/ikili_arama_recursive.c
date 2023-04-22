#include <stdio.h>

int ara(int [], int, int, int);
int main() {
	int dizi[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	printf("%d\n", ara(dizi, 0, boyut - 1, 26));
	printf("%d\n", ara(dizi, 0, boyut - 1, 6));
	printf("%d\n", ara(dizi, 0, boyut - 1, 3));
	return 0;
}

int ara(int dizi[], int bas, int son, int aranan) {
	if(bas <= son) {
		int orta = (bas + son) / 2;
		if(aranan == dizi[orta])
			return orta;
		else if(aranan > dizi[orta])   // sag kisim
			return ara(dizi, orta + 1, son, aranan);
		else						   // sol kisim
			return ara(dizi, bas, orta - 1, aranan);
	}
	return -1;
}
