/**
 * File: listrec.c
 * Tanggal: 2021-11-17
 * Nama : Bayu Samudra
 * NIM : 13520128
 *
 * Implementasi List rekursif
 *
 */
#include "listrec.h"

#include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x) {
  /* Mengirimkan address hasil alokasi sebuah elemen */
  /* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
     menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
  /* Jika alokasi gagal, mengirimkan NULL */
  Address n = malloc(sizeof(Node));
  INFO(n) = x;
  NEXT(n) = NULL;

  return n;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
  /* Mengirimkan true jika l kosong dan false jika l tidak kosong */
  return !l;
}

int isOneElmt(List l) {
  /* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau
   * kosong
   */
  return !!l && !NEXT(l);
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
  /* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
  return INFO(l);
}

List tail(List l) {
  /* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong
   */
  if (!isEmpty(l)) {
    return NEXT(l);
  } else {
    return NULL;
  }
}

List konso(List l, ElType e) {
  /* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi
     terlebih dahulu. Jika alokasi gagal, mengirimkan l */
  Address nNode = newNode(e);

  if (nNode) {
    NEXT(nNode) = l;
    return nNode;
  } else {
    return l;
  }
}

List konsb(List l, ElType e) {
  /* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
  /* e harus dialokasi terlebih dahulu */
  /* Jika alokasi e gagal, mengirimkan L */
  Address nNode = newNode(e);

  if (nNode) {
    List p = l;

    if (isEmpty(p)) {
      return nNode;
    } else {
      while (!isOneElmt(p)) {
        p = tail(p);
      }

      NEXT(p) = nNode;
      return l;
    }

  } else {
    return nNode;
  }
}

/* Fungsi dan Prosedur Lain */
int length(List l) {
  /* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
  if (isEmpty(l)) {
    return 0;
  } else {
    return 1 + length(tail(l));
  }
}

void displayList(List l) {
  /* I.S. List l mungkin kosong */
  /* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
  /*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
    1
    20
    30
   */
  /* Jika list kosong, tidak menuliskan apa-apa  */
  if (!isEmpty(l)) {
    printf("%d\n", INFO(l));
    displayList(tail(l));
  }
}