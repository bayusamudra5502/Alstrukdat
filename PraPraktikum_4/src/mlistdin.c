#include <stdio.h>
#include <string.h>

#include "listdin.h"

int main() {
  ListDin l;

  CreateListDin(&l, 10);
  readList(&l);

  displayList(l);

  return 0;
}