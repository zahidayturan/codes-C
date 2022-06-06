#include <stdio.h>

void fonk1(void);
void fonk2(void);

#define MAK01 5

int main(void)
{
  #define MAK02 10

  int id;

  for (id=0; id<MAK01; id++) 
  printf("%d ", id+1);
  printf("\n");

  fonk1();
  fonk2();

  return 0;
}

void fonk1(void)
{
  #define MAK03 15

  int id;

  for (id=0; id<MAK02; id++) 
  printf("%d ", id+1);
  printf("\n");
}

void fonk2(void)
{
  int id;

  for (id=0; id<MAK03; id++) 
  printf("%d ", id+1);
}