


void fonk(void);

int main(void)
{
    char cdizi[40];

    strcpy(cdizi, "78521");
    printf("Karakter dizisi: %s Int değer: %ld\n", cdizi, atol(cdizi));
        
    strcpy(cdizi, "785.21");
    printf("Karakter dizisi: %s Int değer: %ld\n", cdizi, atol(cdizi));

    strcpy(cdizi, "Bilgisayar");
    printf("Karakter dizisi: %s Int değer: %ld", cdizi, atol(cdizi));

    return 0;	
}
//Karakter dizisi: 78521 Int değer: 78521
//Karakter dizisi: 785.21 Int değer: 785
//Karakter dizisi: Bilgisayar Int değer: 0

/*
int atoi(char s[])
{
        int i, n;
        n = 0;
        for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
                n = 10 * n + (s[i] - '0');
        return n;
}
*/