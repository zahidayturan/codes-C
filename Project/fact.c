#include <stdio.h>
//0 fakt =1
int main(){
	int sayi,i,sonuc=1;
	
	printf("Faktoriyel alinmasini istediginiz sayi : ");
	scanf("%d",&sayi);

	for(int i=2; i<=sayi ; i++)     
		sonuc = sonuc * i; 

	printf("%d sayisinin faktoriyeli : %d\n", sayi,sonuc); 
    return 0;
}