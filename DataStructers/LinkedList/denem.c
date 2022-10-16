#include<stdio.h>

int main(){

int i, k, eleman_sayisi, liste_sayisi, liste_sirasi;

printf("Kaç tane bağlı liste oluşturmak istersiniz? ");
scanf("%d",&liste_sayisi);

for(i=0;i<liste_sayisi;i++){
    printf("%d\n", liste_sayisi);
}

printf("Birleştirmek istedğiniz bağlı listeler hangi sırada birleştirilsin? ");
scanf("%d",&liste_sirasi);

for(i=0;i<liste_sayisi;i++){
    printf("%d. sıra hangisi?", i+1);
}

printf("Bir liste kaç eleman içersin? ");
scanf("%d",&eleman_sayisi);

float arr[eleman_sayisi]; // float arr[size]->declaration of array
for(i=0;i<eleman_sayisi;i++){
    printf("%d. listeyi giriniz\n",i+1);
    
    for(k=0;k<eleman_sayisi;k++){
    printf(".liste 1.eleman: ");
    scanf("%f",&arr[k]); // accepting elements and inserting in the array
    // sum=sum+arr[i]; // performing sum of previous value & new accepting value
    }
}
/*
printf("İlk listeyi giriniz:\n");
*/
//printf("Result is: %f",arr);
return 0;
}

