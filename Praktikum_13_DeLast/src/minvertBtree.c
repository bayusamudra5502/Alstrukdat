#include <stdio.h>

#include "bintree.h"

extern void invertBtree(BinTree *p);

int main() {
  Address a = newTreeNode(1);
  Address b = newTreeNode(2);

  BinTree t[5];
  t[0] = NULL;
  t[1] = NewTree(9, NULL, NULL);
  t[2] = NewTree(99, a, NULL);
  t[3] = NewTree(999, NULL, b);
  t[4] = NewTree(9999, a, b);

  BinTree ta, tb, tc;
  ta = newTreeNode(3);
  tb = newTreeNode(4);
  tc = newTreeNode(6);

  ta = NewTree(2, ta, tb);
  tb = NewTree(5, tc, NULL);
  ta = NewTree(1, ta, tb);

  printf("Print Tree:\n");
  // for (int i = 0; i < 5; i++) {
  //   printInorder(t[i]);
  //   printf("\n");
  // }
  printInorder(ta);

  printf("\nInverting...\n");
  // for (int i = 0; i < 5; i++) {
  //   invertBtree(&t[i]);
  // }
  invertBtree(&ta);
  printf("\n");

  printf("Print Tree:\n");
  printInorder(ta);
  // for (int i = 0; i < 5; i++) {
  //   printInorder(t[i]);
  //   printf("\n");
  // }
  printf("\n");
}