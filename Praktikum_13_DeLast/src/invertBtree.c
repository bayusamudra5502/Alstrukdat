#include "bintree.h"

void invertBtree(BinTree *p) {
  /* I.S. Pohon p terdefinisi */
  /* F.S. Pohon p diflip secara vertikal */
  /*      Contoh:
             1
           2   5
          3 4 6
          Menjadi:
             1
           5   2
            6 4 3 */
  if (!isTreeEmpty(*p)) {
    BinTree l = RIGHT(*p);
    BinTree r = LEFT(*p);

    invertBtree(&l);
    invertBtree(&r);

    LEFT(*p) = l;
    RIGHT(*p) = r;
  }
}
