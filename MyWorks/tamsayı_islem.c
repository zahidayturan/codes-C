#include <stdio.h>
int main()
{
    int number;

// Alınan Sayıyı Yazdırma
    // printf () formatlanmış çıktıyı gösterir 
    printf("Bir tamsayı girin: ");  
    
    // scanf () formatlanmış girişi okur ve saklar
    scanf("%d", &number);  
    
    // printf () biçimlendirilmiş çıktıyı görüntüler
    printf("Girdiğiniz sayı: %d\n", number);



// İki Sayı Toplama
    int firstNumber, secondNumber, sumOfTwoNumbers;
    
    printf("iki tam sayı giriniz: ");

    // girilen iki tam sayı scanf () fonsiyonu kullanılarak saklanır.
    scanf("%d %d", &firstNumber, &secondNumber);

    // iki değişkenin toplamı sumOfTwoNumbers öğesinde depolanır.
    sumOfTwoNumbers = firstNumber + secondNumber;

    // Toplamı görüntüler 
    printf("%d + %d = %d\n", firstNumber, secondNumber, sumOfTwoNumbers);


// İki Sayı Çarpma
    double firstNumber1, secondNumber1, product1;     
    printf("Enter two numbers: ");     
    // Stores two floating point numbers in variable firstNumber and secondNumber respectively     
    scanf("%lf %lf", &firstNumber1, &secondNumber1);         
    // Performs multiplication and stores the result in variable productOfTwoNumbers     
    product1 = firstNumber1 * secondNumber1;       
    // Result up to 2 decimal point is displayed using %.2lf     
    printf("Product = %.2lf\n", product1);


    return 0;
}