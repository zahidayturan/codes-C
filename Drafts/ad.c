#include <stdio.h>

int a = 5;
int b = 6;
int z;
int main(){
if (a > b)
        z = a;
else
        z = b;
printf(" Hangisi büyük %d veya %d ? En büyük: %d\n",a,b,z);
return 0;
}

//AŞAMA 2
int main(){
z = (a > b) ? a : b;
printf(" Hangisi büyük %d veya %d ? En büyük: %d\n",a,b,z);
return 0;
}
//z = (a > b) ? a : b;  --> a b den büyükse a yaz. büyük değilse b yaz.