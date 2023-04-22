#include <stdio.h>
#include <stdlib.h>

void countingSort(int [], int);
void yaz(int [], int);

int main() {
  int dizi[] = {5, 6, 1, 9, 3, 4, 61, 21, 1}; // slaytdaki A dizisi
  int n = sizeof(dizi) / sizeof(dizi[0]);
  countingSort(dizi, n);
  yaz(dizi, n);
  return 0;
}

void countingSort(int dizi[], int n) {
	int *yedek; // sirali hali -> slaytdaki B dizisi
	int *count; // slaytdaki C dizisi
	yedek = (int*) malloc(n * sizeof(int));
	int max = dizi[0];
	int i;
	//en buyuk eleman bulunuyor
  	for(i = 1; i < n; i++) {
		if(dizi[i] > max)
			max = dizi[i];
	}
	count = (int*) malloc((max + 1) * sizeof(int));
	for(i = 0; i < max + 1; i++)
		count[i] = 0; // bos dizi 0 ile doldurulur

	for(i = 0; i < n; i++)
		count[dizi[i]]++;

	for(i = 1; i < max + 1; i++)
		count[i] += count[i - 1];

	for(i = n - 1; i >= 0; i--) {
		yedek[count[dizi[i]] - 1] = dizi[i];
		count[dizi[i]]--;
	}

	for(i = 0; i < n; i++)
		dizi[i] = yedek[i];
	free(yedek);
	free(count);
}

void yaz(int dizi[], int n) {
	int i;
  	for (i = 0; i < n; ++i) {
    	printf("%d  ", dizi[i]);
  	}
  	printf("\n");
}
