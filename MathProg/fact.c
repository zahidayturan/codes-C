#include <stdio.h>

int main(){
	float sayi;
	float sonuc=1;
	int i;
	
	printf("Faktoriyel alinmasini istediginiz sayi : ");
	scanf("%f",&sayi);

	for(int i=2; i<=sayi ; i++)     
		sonuc = sonuc * i; 

	printf("%f sayisinin faktoriyeli : %f\n", sayi,sonuc); 
    return 0;
}