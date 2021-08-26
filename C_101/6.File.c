#include <stdio.h>

int main()
{
  FILE *f = fopen("halo.txt", "w");

  fprintf(f, "Halo, Dunia");

  fclose(f);
  return 0;
}