#include <stdio.h>

#include "listrec.h"

int main() {
  // Halo
  List l = NULL;

  l = konsb(l, 1);
  l = konsb(l, 1);
  l = konsb(l, 1);
  l = konsb(l, 1);

  printf("max: %d\n", maxList(l));
  printf("min: %d\n", minList(l));
  printf("sum: %d\n", sumList(l));
  printf("avg: %f\n", averageList(l));

  List balik = inverseList(l);
  displayList(balik);

  List l1, l2;
  // splitPosNeg(NULL, &l1, &l2);
  // splitOnX(l, 3, &l1, &l2);
  // displayList(l1);
  // printf("-----\n");
  // displayList(l2);

  List lt1 = NULL, lt2 = NULL;
  // lt1 = konsb(lt1, 1);
  // lt1 = konsb(lt1, 2);
  // lt1 = konsb(lt1, 3);
  // lt1 = konsb(lt1, 4);

  // lt2 = konsb(lt2, 1);
  // lt2 = konsb(lt2, 2);
  // // lt2 = konsb(lt2, 3);
  // // lt2 = konsb(lt2, 3);
  // lt2 = konsb(lt2, 4);

  // printf("\n> %d\n", isAllExist(lt1, lt2));

  return 0;
}