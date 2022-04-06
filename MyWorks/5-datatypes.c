
//Temel veri tipleri (Fundamental data types)
/*
int
Tamsayılar hem sıfır, hem pozitif hem de negatif değerlere sahip, ancak ondalık değer içermeyen tam sayılardır. Örnek: 0, -5, 10
İnt’nin boyutu çoğu derleyicide 4 bayttır (32 bit). Bu nedenle, 232 farklı durum alabilir: -231, -231 + 1, …, -1, 0, 1, 2, …, 231-2, 231-1
yani, -2147483648 ila 2147483647 (2^31-1) arasındadır.

float ve double
float ve double reel sayıları tutmak için kullanılır.
float ve double arasındaki fark nedir?
float boyutu (tek duyarlıklı) 4 bayttır. Ve double boyutu (çift duyarlıklı) 8 bayttır.

char
Char karakteri, karakter tipi değişkenlerini bildirmek için kullanılır

void
void tamamlanmamış (incomplete) bir türdür. “Hiçbir şey” veya “tür yok” anlamına gelir. Boşluğu eksik olarak düşünebilirsiniz.
Örneğin, bir işlev hiçbir şey döndürmüyorsa, dönüş türü geçersiz olmalıdır.

enum
Enum anahtar sözcüğünü kullanarak numaralandırılmış bir tür oluşturabilirsiniz. Bir numaralandırma integral sabitlerinden oluşur

short ve long
long a;
long long b;
long double c; 
Burada a ve b değişkenleri tamsayı değerlerini kaydedebilir. Ve c ondalıklı sayıyı saklayabilir.
Yalnızca küçük bir tamsayı ([−32,767, +32,767] aralığı) kullanacaksanız, short kullanabilirsiniz.

*/

/*Sizeof () operatörünü kullanarak bir değişkenin boyutunu her zaman kontrol edebilirsiniz.

#include <stdio.h>      
int main() {
  short a;
  long b;
  long long c;
  long double d;

  printf("size of short = %d bytes\n", sizeof(a));
  printf("size of long = %d bytes\n", sizeof(b));
  printf("size of long long = %d bytes\n", sizeof(c));
  printf("size of long double= %d bytes\n", sizeof(d));
  return 0;
}
*/


/*
Türetilmiş türler (Derived types)
İşte C’de türetilmiş türlerin bir listesi.

Array (Dizi türü)
Pointer (İşaretçi tipi)
Structure (Yapı tipi)
Union (Union tipi)
Function (Fonksiyon tipi )
Atomic (Atom tipi)
*/