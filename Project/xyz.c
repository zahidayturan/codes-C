int main()
{
    int x = 5;
    int y = 3;
    int z = 0;
    printf("x=%d ve y=%d z=%d\n ", x, y, z);
    printf("\tx ve y nin toplamı şudur: %d\n", x+y);
    printf("Z yeni değer = %d\n", x+y);
    z = x+y;
    x = 0;
    x += y;
    printf("X yeni değer = %d\n", x);
    printf("Y yeni değer = %d\n", x+z);
    y = x+z;
    printf("x%d y%d z%d\n", x, y, z);
    return 0;
}