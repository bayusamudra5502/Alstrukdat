#include "list_circular.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

boolean isEmpty(List l) {
  /* Mengirim true jika list kosong. Lihat definisi di atas. */
  return FIRST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  /* I.S. l sembarang             */
  /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
  FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
  /* Mengirimkan Address hasil alokasi sebuah elemen */
  /* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
  /* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
  /* Jika alokasi gagal, mengirimkan NULL */

  Address p = malloc(sizeof(ElmtList));

  if (p) {
    NEXT(p) = NULL;
    INFO(p) = val;
  }

  return p;
}

void deallocate(Address P) {
  /* I.S. P terdefinisi */
  /* F.S. P dikembalikan ke sistem */
  /* Melakukan dealokasi/pengembalian Address P */

  free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
  /* Mencari apakah ada elemen list dengan INFO(P)= val */
  /* Jika ada, mengirimkan Address elemen tersebut. */
  /* Jika tidak ada, mengirimkan NULL */

  if (isEmpty(l)) {
    return NULL;
  } else {
    boolean isFound = false;
    Address p = FIRST(l);

    do {
      if (INFO(p) == val) {
        isFound = true;
      } else {
        p = NEXT(p);
      }
    } while (p != FIRST(l) && !isFound);

    return isFound ? p : NULL;
  }
}

boolean addrSearch(List l, Address p) {
  /* Mencari apakah ada elemen list l yang beralamat p */
  /* Mengirimkan true jika ada, false jika tidak ada */
  if (isEmpty(l)) {
    return false;
  } else {
    boolean isFound = false;
    Address pp = FIRST(l);

    do {
      if (pp == p) {
        isFound = true;
      } else {
        pp = NEXT(pp);
      }
    } while (pp != FIRST(l) && !isFound);

    return isFound;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
  /* I.S. List l terdefinisi, mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
  /* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */

  Address n = allocate(val);

  if (n) {
    if (isEmpty(*l)) {
      NEXT(n) = n;
      FIRST(*l) = n;
    } else {
      Address p = FIRST(*l);

      do {
        p = NEXT(p);
      } while (NEXT(p) != FIRST(*l));

      NEXT(n) = FIRST(*l);
      NEXT(p) = n;
      FIRST(*l) = n;
    }
  }
}

void insertLast(List *l, ElType val) {
  /* I.S. List l terdefinisi, mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen list di akhir: elemen terakhir yang baru */
  /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  /* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */

  if (isEmpty(*l)) {
    insertFirst(l, val);
  } else {
    Address n = allocate(val);

    if (n) {
      Address p = FIRST(*l);

      do {
        p = NEXT(p);
      } while (NEXT(p) != FIRST(*l));

      NEXT(p) = n;
      NEXT(n) = FIRST(*l);
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
  /* I.S. List l tidak kosong  */
  /* F.S. val adalah elemen pertama List l sebelum penghapusan */
  /*      Elemen list berkurang satu (mungkin menjadi kosong) */
  /*      First element yg baru adalah suksesor elemen pertama yang lama */
  /*      Jika list baru tidak kosong, Last element menunjuk ke First element
   * baru
   */
  /*      Jika list baru kosong, maka FIRST(*l) = NULL */
  /*      Alamat elemen pertama list lama di-dealokasi */
  Address p = FIRST(*l);
  *val = INFO(p);

  if (p == NEXT(p)) {
    FIRST(*l) = NULL;
  } else {
    Address pp = p;

    do {
      pp = NEXT(pp);
    } while (p != NEXT(pp));

    NEXT(pp) = NEXT(p);
    FIRST(*l) = NEXT(p);
  }

  deallocate(p);
}

void deleteLast(List *l, ElType *val) {
  /* I.S. List l tidak kosong */
  /* F.S. val adalah elemen terakhir list sebelum penghapusan */
  /*      Elemen list berkurang satu (mungkin menjadi kosong) */
  /*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada
   */
  /*      Jika list baru tidak kosong, Last element baru menunjuk ke First
   * element
   */
  /*      Jika list baru kosong, maka FIRST(*l) = NULL */
  /*      Alamat elemen terakhir list lama di-dealokasi */
  Address p = FIRST(*l);

  if (p == NEXT(p)) {
    deleteFirst(l, val);
  } else {
    Address pp = p;
    Address pl = p;

    do {
      pl = pp;
      pp = NEXT(pp);
    } while (NEXT(pp) != p);

    NEXT(pl) = p;
    *val = INFO(pp);
    deallocate(pp);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
  /* I.S. List l mungkin kosong */
  /* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika list kosong : menulis [] */
  /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
  if (isEmpty(l)) {
    printf("[]");
  } else {
    boolean isFirst = true;
    Address p = FIRST(l);

    printf("[");
    do {
      if (isFirst) {
        isFirst = false;
      } else {
        printf(",");
      }

      printf("%d", INFO(p));
      p = NEXT(p);
    } while (p != FIRST(l));
    printf("]");
  }
}
