#include "bintree.h"

#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree) {
  /* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika
     alokasi berhasil Menghasilkan pohon kosong (NULL) jika alokasi gagal */
  BinTree tree;
  CreateTree(root, left_tree, right_tree, &tree);

  return tree;
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree,
                BinTree *p) {
  /* I.S. Sembarang
     F.S. Menghasilkan sebuah pohon p
     Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi
     berhasil
     Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

  Address n = newTreeNode(root);

  if (n) {
    ROOT(n) = root;
    LEFT(n) = left_tree;
    RIGHT(n) = right_tree;
    *p = n;
  } else {
    *p = NULL;
  }
}

Address newTreeNode(ElType val) {
  /* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
  /* Mengirimkan address hasil alokasi sebuah elemen bernilai val
     Jika alokasi berhasil, maka address tidak NULL, dan misalnya
     menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
     Jika alokasi gagal, mengirimkan NULL */
  Address n = malloc(sizeof(TreeNode));

  if (n) {
    ROOT(n) = val;
    LEFT(n) = NULL;
    RIGHT(n) = NULL;
  } else {
    return NULL;
  }
}

void deallocTreeNode(Address p) {
  /* I.S. p terdefinisi
     F.S. p dikembalikan ke sistem
     Melakukan dealokasi/pengembalian address p */
  free(p);
}

boolean isTreeEmpty(BinTree p) {
  /* Mengirimkan true jika p adalah pohon biner yang kosong */
  return !p;
}

boolean isOneElmt(BinTree p) {
  /* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
  return p && !LEFT(p) && !RIGHT(p);
}

boolean isUnerLeft(BinTree p) {
  /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft:
     hanya mempunyai subpohon kiri */
  return p && !RIGHT(p) && LEFT(p);
}

boolean isUnerRight(BinTree p) {
  /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright:
     hanya mempunyai subpohon kanan */
  return p && !LEFT(p) && RIGHT(p);
}

boolean isBinary(BinTree p) {
  /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner:
    mempunyai subpohon kiri dan subpohon kanan */
  return p && LEFT(p) && RIGHT(p);
}

/* ****** Display Tree ***** */
void printPreorder(BinTree p) {
  /* I.S. p terdefinisi */
  /* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan
     pohon kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung
     tutup
     (). Pohon kosong ditandai dengan (). Tidak ada tambahan karakter apa pun di
     depan, tengah, atau akhir. */
  /* Contoh:
     (A()()) adalah pohon dengan 1 elemen dengan akar A
     (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan
     subpohon kanan (C()()) */
  printf("(");
  if (!isTreeEmpty(p)) {
    printf("%d", ROOT(p));
    printPreorder(LEFT(p));
    printPreorder(RIGHT(p));
  }
  printf(")");
}

void printInorder(BinTree p) {
  /* I.S. p terdefinisi */
  /* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan
     pohon kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung
     tutup (). Pohon kosong ditandai dengan ().
     Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
  /* Contoh:
     (()A()) adalah pohon dengan 1 elemen dengan akar A
     ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan
     subpohon kanan (()C()) */
  printf("(");

  if (!isTreeEmpty(p)) {
    printInorder(LEFT(p));
    printf("%d", ROOT(p));
    printInorder(RIGHT(p));
  }

  printf(")");
}

void printPostorder(BinTree p) {
  /* I.S. p terdefinisi */
  /* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon
     kanan, dan akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung
     tutup (). Pohon kosong ditandai dengan ().
     Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
  /* Contoh:
     (()()A) adalah pohon dengan 1 elemen dengan akar A
     ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan
     subpohon kanan (()()C) */
  printf("(");

  if (!isTreeEmpty(p)) {
    printPostorder(LEFT(p));
    printPostorder(RIGHT(p));
    printf("%d", ROOT(p));
  }

  printf(")");
}

void treePrinter(BinTree p, int h, int aras) {
  if (!isTreeEmpty(p)) {
    // Membuat Tabnya
    for (int i = 0; i < h * aras; i++) {
      printf(" ");
    }

    printf("%d\n", ROOT(p));

    treePrinter(LEFT(p), h, aras + 1);
    treePrinter(RIGHT(p), h, aras + 1);
  }
}

void printTree(BinTree p, int h) {
  /* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
  /* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
  /* Penulisan akar selalu pada baris baru (diakhiri newline) */
  /* Contoh, jika h = 2:
  1) Pohon preorder: (A()()) akan ditulis sbb:
  A
  2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
  A
    B
    C
  3) Pohon preorder: (A(B(D()())())(C()(E()())) akan ditulis sbb:
  A
    B
      D
    C
      E
  Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini
  jika diperlukan
  */

  if (isTreeEmpty(p)) {
    printf("\n");
  } else {
    treePrinter(p, h, 0);
  }
}