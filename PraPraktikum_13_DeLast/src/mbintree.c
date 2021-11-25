#include <stdio.h>

#include "bintree.h"

int main() {
  Address a = newTreeNode(1);
  Address b = newTreeNode(2);

  BinTree t[5];
  t[0] = NULL;
  t[1] = NewTree(9, NULL, NULL);
  t[2] = NewTree(99, a, NULL);
  t[3] = NewTree(999, NULL, b);
  t[4] = NewTree(9999, a, b);

  BinTree h = NewTree(10, a, t[4]);
  h = NewTree(3, t[2], h);

  printf("Print Tree:\n");
  for (int i = 0; i < 5; i++) {
    printf("Tree %d:\n", i);
    printTree(t[i], 2);
    printf("\n");
  }
  printf("\n");

  printf("isEmpty: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", isTreeEmpty(t[i]));
  }
  printf("\n");

  printf("isOneElmt: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", isOneElmt(t[i]));
  }
  printf("\n");

  printf("isUnerLeft: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", isUnerLeft(t[i]));
  }
  printf("\n");

  printf("isUnerRight: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", isUnerRight(t[i]));
  }
  printf("\n");

  printTree(h, 2);

  printf("Print Preorder:\n");
  for (int i = 0; i < 5; i++) {
    printf("Tree %d:\n", i);
    printPreorder(t[i]);
    printf("\n");
  }
  printPreorder(h);
  printf("\n");
  printf("\n");

  printf("Print Inorder:\n");
  for (int i = 0; i < 5; i++) {
    printf("Tree %d:\n", i);
    printInorder(t[i]);
    printf("\n");
  }
  printInorder(h);
  printf("\n");
  printf("\n");

  printf("Print Postorder:\n");
  for (int i = 0; i < 5; i++) {
    printf("Tree %d:\n", i);
    printPostorder(t[i]);
    printf("\n");
  }
  printPostorder(h);
  printf("\n");
  printf("\n");
}