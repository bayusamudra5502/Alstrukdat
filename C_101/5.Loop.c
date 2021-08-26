#include <stdio.h>

int main()
{
  for (int i = 0, j = 2; i * j <= 100; i++, j += i)
  {
    printf("Halo\n");
  }
  return 0;
}