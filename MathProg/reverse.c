#include <stdio.h>
// sayıyı ters çevirme
int main()
{
  int n, reverse = 0;
 
  printf("Enter a number to reverse\n");
  scanf("%d", &n);
 
  while (n != 0)
  {
    reverse = reverse * 10;
    reverse = reverse + n%10;
    n = n/10;
  }
 // r=0 n=152 --  r=2 n=15 -- r=25 n=1 -- r=251    ** 152-->251 **
  printf("Reverse of entered number is = %d\n", reverse);
 
  return 0;
}