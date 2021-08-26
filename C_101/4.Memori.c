#include <stdio.h>

int main()
{
  int a = 100;

  printf("Satu : %p \n Dua : %p", (void *)a, &a);
  return 0;
}