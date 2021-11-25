#include <stdio.h>

#include "listrec.h"

List splitOddIndex(List l) {
  /* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada
  indeks ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan
  indeks 1. Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
  if (isEmpty(l)) {
    return NULL;
  } else if (isOneElmt(l)) {
    return l;
  } else {
    return konso(splitOddIndex(tail(tail(l))), head(l));
  }
}

List splitEvenIndex(List l) {
  /* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada
  indeks genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan
  indeks 1. Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
  if (isOneElmt(l) || isEmpty(l)) {
    return NULL;
  } else {
    return splitOddIndex(tail(l));
  }
}

List splitBeforeX(List l, ElType x) {
  /* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan
  elemen dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada
  pada list, maka kembalikan list l. Jika tidak ada elemen yang bisa diambil,
  kembalikan NULL */
  if (isEmpty(l) || head(l) == x) {
    return NULL;
  } else {
    return konso(splitBeforeX(tail(l), x), head(l));
  }
}

List reverseList(List l) {
  /* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list
  l. Jika l kosong, kembalikan list kosong. */
  if (isEmpty(l)) {
    return NULL;
  } else {
    return konsb(reverseList(tail(l)), head(l));
  }
}

int main() {
  char command = '\0';
  List peserta = NULL;

  while (command != 'X') {
    scanf("%c", &command);
    int val;

    switch (command) {
      case 'B':
        scanf("%d", &val);
        peserta = konsb(peserta, val);
        break;
      case 'F':
        scanf("%d", &val);
        peserta = konso(peserta, val);
        break;
      case 'O':
        peserta = splitOddIndex(peserta);
        break;
      case 'E':
        peserta = splitEvenIndex(peserta);
        break;
      case 'P':
        scanf("%d", &val);
        peserta = splitBeforeX(peserta, val);
        break;
      case 'R':
        peserta = reverseList(peserta);
        break;
    }
  }

  if (peserta) {
    displayList(peserta);
  } else {
    printf("Semua gugur\n");
  }

  return 0;
}