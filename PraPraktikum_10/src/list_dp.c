/**
 * Nama : Bayu Samudra
 * NIM : 13520128
 *
 * Double Linked List
 */

#include "list_dp.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

boolean isEmpty(List l) {
  /* Mengirim true jika list kosong. Lihat definisi di atas. */
  return FIRST(l) == NULL && LAST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  /* I.S. l sembarang  */
  /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
  FIRST(*l) = NULL;
  LAST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
  /* Mengirimkan address hasil alokasi sebuah elemen */
  /* Jika alokasi berhasil, maka address tidak NULL. */
  /* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
  /* Jika alokasi gagal, mengirimkan NULL. */
  Address result = malloc(sizeof(Node));

  if (result) {
    NEXT(result) = NULL;
    PREV(result) = NULL;
    INFO(result) = val;
  }

  return result;
}

void deallocate(Address p) {
  /* I.S. p terdefinisi */
  /* F.S. p dikembalikan ke sistem */
  /* Melakukan dealokasi/pengembalian Address P */

  free(p);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
  /* Mencari apakah ada elemen list dengan INFO(P)=val */
  /* Jika ada, mengirimkan Address elemen tersebut. */
  /* Jika tidak ada, mengirimkan NULL */
  boolean isFound = false;
  Address p = FIRST(l);

  while (!isFound && p) {
    if (INFO(p) == val) {
      isFound = true;
    } else {
      p = NEXT(p);
    }
  }

  return p;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
  /* I.S. List l terdefinisi */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
  Address n = allocate(val);

  if (n) {
    if (isEmpty(*l)) {
      FIRST(*l) = n;
      LAST(*l) = n;
    } else {
      NEXT(n) = FIRST(*l);
      PREV(FIRST(*l)) = n;
      FIRST(*l) = n;
    }
  }
}

void insertLast(List *l, ElType val) {
  /* I.S. List l terdefinisi */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen list di akhir: elemen terakhir yang baru */
  /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

  if (isEmpty(*l)) {
    insertFirst(l, val);
  } else {
    Address n = allocate(val);

    if (n) {
      PREV(n) = LAST(*l);
      NEXT(LAST(*l)) = n;
      LAST(*l) = n;
    }
  }
}

void insertAfter(List *L, Address p, Address pRec) {
  /* I.S. pRec pasti elemen list; p sudah dialokasi */
  /* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */
  Address pn = FIRST(*L);

  while (pn != pRec) {
    pn = NEXT(pn);
  }

  NEXT(p) = NEXT(pRec);

  if (NEXT(pRec)) {
    PREV(NEXT(pRec)) = p;
  } else {
    LAST(*L) = p;
  }

  PREV(p) = pn;
  NEXT(pn) = p;
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
  /* I.S. List l tidak kosong  */
  /* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
  /*      dan alamat elemen pertama di-dealokasi */
  Address p = FIRST(*l);
  *val = INFO(p);

  FIRST(*l) = NEXT(p);

  if (NEXT(p)) {
    PREV(FIRST(*l)) = NULL;
  } else {
    LAST(*l) = NULL;
  }

  deallocate(p);
}

void deleteLast(List *l, ElType *val) {
  /* I.S. list l tidak kosong */
  /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
  /*      dan alamat elemen terakhir di-dealokasi */
  if (FIRST(*l) == LAST(*l)) {
    deleteFirst(l, val);
  } else {
    Address p = LAST(*l);
    *val = INFO(p);

    LAST(*l) = PREV(p);
    NEXT(LAST(*l)) = NULL;

    deallocate(p);
  }
}
void deleteAfter(List *l, Address *pDel, Address pRec) {
  /* I.S. List tidak kosong. pRec adalah anggota list.
          NEXT(pRec)!=NULL */
  /* F.S. Menghapus NEXT(pRec): */
  Address p = FIRST(*l);

  while (p != pRec) {
    p = NEXT(p);
  }

  *pDel = NEXT(p);

  Address pNext = NEXT(*pDel);
  NEXT(p) = pNext;

  if (pNext) {
    PREV(pNext) = p;
  } else {
    LAST(*l) = p;
  }

  NEXT(*pDel) = NULL;
  PREV(*pDel) = NULL;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
  /* I.S. List mungkin kosong */
  /* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
  /* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika list kosong : menulis [] */
  /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
  printf("[");

  boolean isFirst = true;
  Address p = FIRST(l);

  while (p) {
    if (!isFirst) {
      printf(",");
    } else {
      isFirst = false;
    }

    printf("%d", INFO(p));
    p = NEXT(p);
  }

  printf("]");
}

void displayListBackwards(List l) {
  /* I.S. List mungkin kosong */
  /* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
  /* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
  /* Jika list kosong : menulis [] */
  /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
  printf("[");

  boolean isFirst = true;
  Address p = LAST(l);

  while (p) {
    if (!isFirst) {
      printf(",");
    } else {
      isFirst = false;
    }

    printf("%d", INFO(p));
    p = PREV(p);
  }

  printf("]");
}
