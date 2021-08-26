#include <stdio.h>
#include <stdlib.h>

typedef struct Hewan
{
  int umur;
} Hewan;

int main()
{
  Hewan *kucing = malloc(sizeof(Hewan));
  char halo[20];
  int angka = 0;

  kucing->umur = 12;

  printf("Masukin string : ");
  scanf("%[^\n]s", halo);

  printf("Angka kamu: %d\n", angka);
  printf("String kamu : %s\n", halo);
  printf("Umur Kucing: %d\n", kucing->umur);
}