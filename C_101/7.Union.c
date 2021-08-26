#include <stdio.h>
#include <string.h>

typedef union Uniku
{
  int a;
  long int b;
  char str[100];
} Uniku;

int main()
{
  Uniku asam;
  strcpy(asam.str, "Bacang");

  printf("%x\n", asam.a);
  printf("%lx", asam.b);
  printf("\n%s\n", asam.str);

  return 0;
}