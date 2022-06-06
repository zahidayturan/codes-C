#include <stdio.h>

/* DİZİ UZUNLUĞU */

#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *kelime = "Bilgisayar ";
    int islev;

    islev = strlen(kelime);

    printf("%s karakter dizisinin uzunluğu: %d\n", kelime, islev);

// ÇIKTI ::: Bilgisayar karakter dizisinin uzunluğu: 11 . 
// *kelime = "" böyle olsaydı sonuç 0. Çünkü doğru bir ifade

    return 0;
}

//ana ifade :::
/* strlen: return length of s 

int strlen(char s[])
{
        int i = 0;
        while (s[i] != '\0')
                ++i;
        return i;
}
*/