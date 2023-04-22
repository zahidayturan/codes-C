#include <stdio.h>

void yazdir(int[], int);
void yer_degis(int[], int, int);
int parcala(int[], int, int); //divede bolme
void sirala(int[], int, int); //conquer fethet

int main() {
	int a[] = {38, 27, 43, 3, 9, 82, 10, 5};  
    int boyut = sizeof(a) / sizeof(a[0]);
    yazdir(a, boyut);
    sirala(a, 0, boyut - 1); 
    yazdir(a, boyut);
	return 0;
}

void yazdir(int dizi[], int boyut) {
    int i;
    for(i = 0; i < boyut; i++){
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

void yer_degis(int dizi[], int i, int j) {
	int gecici;
	gecici = dizi[i];
	dizi[i] = dizi[j];
	dizi[j] = gecici;
}

int parcala(int dizi[], int bas, int son) {
	int pivot = dizi[son], i = bas - 1, j;
	for(j = bas; j < son; j++)
		if(dizi[j] <= pivot) {
			i++;
			yer_degis(dizi, i, j);
		}
	yer_degis(dizi, i + 1, son);
	return i + 1;
}

void sirala(int dizi[], int bas, int son) {
	int pivot;
	if(bas < son) {
		pivot = parcala(dizi, bas, son);
		sirala(dizi, bas, pivot - 1);
		sirala(dizi, pivot + 1, son);
	}
}
