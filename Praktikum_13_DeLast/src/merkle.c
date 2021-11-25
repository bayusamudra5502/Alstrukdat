#include <math.h>
#include <stdio.h>

#include "bintree.h"

boolean isPowerTwo(int x) {
  double cnt = log2(x);
  return floor(cnt) == cnt;
}

int main() {
  int n;
  scanf("%d", &n);

  if (n > 0 && isPowerTwo(n)) {
    BinTree b[n + 5];

    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      b[i] = newTreeNode(tmp);
    }

    while (n > 1) {
      for (int i = 0, j = 0; i < n; i += 2, j++) {
        int rootval = ROOT(b[i]) + ROOT(b[i + 1]);
        BinTree newRoot = NewTree(rootval, b[i], b[i + 1]);
        b[j] = newRoot;
      }

      n >>= 1;
    }

    printTree(b[0], 2);
  } else {
    printf("Jumlah masukan tidak sesuai\n");
  }
}