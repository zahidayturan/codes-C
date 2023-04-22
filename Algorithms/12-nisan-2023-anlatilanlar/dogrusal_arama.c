#include <stdio.h>

int ara(int[], int, int);
int ara_v2(int[], int, int);
int main() {
	int dizi[] = { 8, 6, 7, 10, 5, 3 };
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	printf("%d\n", ara(dizi, boyut, 26));
	printf("%d\n", ara(dizi, boyut, 6));
	printf("%d\n", ara(dizi, boyut, 3));
	
	int a[] = { 1, 2, 5, 8, 9, 10 };
	boyut = sizeof(a) / sizeof(a[0]);
	printf("%d\n", ara_v2(a, boyut, 26));
	printf("%d\n", ara_v2(a, boyut, 8));
	printf("%d\n", ara_v2(a, boyut, 3));
	return 0;
}

int ara(int dizi[], int N, int aranan) {
	int i;
	for(i = 0; i < N; i++) {
		if(dizi[i] == aranan)
			return i;
	}
	return -1; // en kotu durum: bir elemanin olmamasi veya dizinin son elemaninda arananin bulunmasi
}
//siralanmis bir dizi input olarak 
//verildiginde daha verimli calisir ara_v2 fonksiyonu
int ara_v2(int dizi[], int N, int aranan) {
	int i;
	for(i = 0; i < N; i++) {
		if(dizi[i] == aranan)
			return i;
		else if(dizi[i] > aranan)
			return -1;
	}
	return -1;
}
