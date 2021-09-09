/* File    : libpost.c
 * Tanggal : 7 September 2021
 * Nama	   : Bayu Samudra
 * NIM     : 13520128
 * Topik   :
 *
 * Implementasi ABSTRACT DATA TYPE LIST POSITIF
 *
 */

#include "listpos.h"

#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */

void CreateListPos(ListPos *l) {
  /* I.S. l sembarang */
  /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
  /* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

  int i;
  for (i = 0; i < CAPACITY; i++) {
    ELMT(*l, i) = VAL_UNDEF;
  }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

int length(ListPos l) {
  /* Mengirimkan banyaknya elemen efektif List */
  /* Mengirimkan nol jika List kosong */
  int length = 0;
  while (ELMT(l, length) != VAL_UNDEF && length < CAPACITY) length++;

  return length;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i) {
  /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
  /* yaitu antara indeks yang terdefinisi utk container*/
  return 0 <= i && i < CAPACITY;
}

boolean isIdxEff(ListPos l, int i) {
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
  /* yaitu antara 0..length(l)-1 */
  return 0 <= i && i < length(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l) {
  /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
  return length(l) == 0;
}

/* *** Test List penuh *** */
boolean isFull(ListPos l) {
  /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
  return length(l) == CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l) {
  /* I.S. l sembarang */
  /* F.S. List l terdefinisi */
  /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
  /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
  /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY
   */
  /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
  /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
            Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
  /*    Jika n = 0; hanya terbentuk List kosong */

  int n, i, input;

  CreateListPos(l);

  do {
    scanf("%d", &n);
  } while (!(n >= 0 && n <= CAPACITY));

  for (i = 0; i < n; i++) {
    scanf("%d", &input);
    ELMT(*l, i) = input;
  }
}

void displayList(ListPos l) {
  /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara
     kurung siku; antara dua elemen dipisahkan dengan separator "koma", tanpa
     tambahan
     karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
  /* I.S. l boleh kosong */
  /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika List kosong : menulis [] */

  int i;
  int len = length(l);

  printf("[");

  for (i = 0; i < len; i++) {
    printf("%d", ELMT(l, i));

    if (i < len - 1) {
      printf(",");
    }
  }

  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus) {
  /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
  /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
         indeks yang sama dijumlahkan */
  /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
         elemen l2 pada indeks yang sama */

  ListPos res;
  CreateListPos(&res);

  int i, len = length(l1);
  for (i = 0; i < len; i++) {
    if (plus) {
      ELMT(res, i) = ELMT(l1, i) + ELMT(l2, i);
    } else {
      ELMT(res, i) = ELMT(l1, i) - ELMT(l2, i);
    }
  }

  return res;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2) {
  /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
     elemennya sama */

  int len = length(l1);

  if (len == length(l2)) {
    int i = 0;
    boolean isEq = true;

    while (isEq && i < len) {
      if (ELMT(l1, i) != ELMT(l2, i)) isEq = false;

      i++;
    }

    return isEq;

  } else {
    return false;
  }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val) {
  /* Search apakah ada elemen List l yang bernilai val */
  /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
  /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
  /* Skema Searching yang digunakan bebas */
  int i = 0, len = length(l);
  boolean isFound = false;

  while (!isFound && i < len) {
    if (ELMT(l, i) == val) {
      isFound = true;
    } else {
      i++;
    }
  }

  return isFound ? i : IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min) {
  /* I.S. List l tidak kosong */
  /* F.S. Max berisi nilai terbesar dalam l;
          Min berisi nilai terkecil dalam l */

  *min = ELMT(l, 0);
  *max = ELMT(l, 0);

  int i, len = length(l);
  for (i = 1; i < len; i++) {
    if (ELMT(l, i) > *max) {
      *max = ELMT(l, i);
    }

    if (ELMT(l, i) < *min) {
      *min = ELMT(l, i);
    }
  }
}

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l) {
  /* Menghailkan true jika semua elemen l genap */

  boolean isEven = true;
  int i = 0, len = length(l);

  while (i < len && isEven) {
    if (ELMT(l, i) % 2 > 0) {
      isEven = false;
    }
    i++;
  }

  return isEven;
}

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc) {
  /* I.S. l boleh kosong */
  /* F.S. Jika asc = true, l terurut membesar */
  /*      Jika asc = false, l terurut mengecil */
  /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
     algoritma bebas */

  int i, j, idx, tmp;
  int len = length(*l);

  for (i = 0; i < len; i++) {
    idx = i;

    for (j = i + 1; j < len; j++) {
      if ((asc && ELMT(*l, idx) > ELMT(*l, j)) ||
          (!asc && ELMT(*l, idx) < ELMT(*l, j))) {
        idx = j;
      }
    }

    // SWAPPING
    tmp = ELMT(*l, i);
    ELMT(*l, i) = ELMT(*l, idx);
    ELMT(*l, idx) = tmp;
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val) {
  /* Proses: Menambahkan val sebagai elemen terakhir List */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */

  ELMT(*l, length(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val) {
  /* Proses : Menghapus elemen terakhir List */
  /* I.S. List tidak kosong */
  /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
  /*      Banyaknya elemen List berkurang satu */
  /*      List l mungkin menjadi kosong */
  *val = ELMT(*l, length(*l) - 1);
  ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}
