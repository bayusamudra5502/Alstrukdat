/* File    : listdinpos.c
 * Tanggal : 16 September 2021
 * Nama	   : Bayu Samudra
 * NIM     : 13520128
 * Topik   :
 *
 * Implementasi ABSTRACT DATA TYPE LIST POSITIF
 *
 */

#include "listdinpos.h"

#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
  /* I.S. l sembarang, capacity > 0 */
  /* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
  /* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

  ElType *hasil = malloc((capacity + 1) * sizeof(ElType));

  if (hasil) {
    BUFFER(*l) = hasil;
    CAPACITY(*l) = capacity + 1;

    for (int i = 0; i < capacity + 1; i++) {
      ELMT(*l, i) = VAL_UNDEF;
    }
  } else {
    exit(1);
  }
}

void dealocate(ListDin *l) {
  /* I.S. l terdefinisi; */
  /* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

  free(BUFFER(*l));
  CAPACITY(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
  /* Mengirimkan banyaknya elemen efektif list */
  /* Mengirimkan nol jika list kosong */
  int cnt = 0;
  boolean end = false;

  for (int i = 0; i < CAPACITY(l) && !end; i++) {
    if (ELMT(l, i) == VAL_UNDEF) {
      end = true;
    } else {
      cnt++;
    }
  }

  return cnt;
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
  /* Prekondisi : List l tidak kosong */
  /* Mengirimkan indeks elemen l terakhir */

  return length(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i) {
  /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
  /* yaitu antara indeks yang terdefinisi utk container*/
  return 0 <= i && i < CAPACITY(l);
}

boolean isIdxEff(ListDin l, IdxType i) {
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
  /* yaitu antara 0..NEFF(l) */

  return 0 <= i && i < length(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
  /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
  /* *** Test list penuh *** */
  return length(l) == 0;
}

boolean isFull(ListDin l) {
  /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
  return length(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
  /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
  /* F.S. List l terdefinisi */
  /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
  /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
  /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <=
   * CAPACITY(l)
   */
  /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
  /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
  /*    Jika N = 0; hanya terbentuk l kosong */

  int n;

  do {
    scanf("%d", &n);
  } while (!(0 <= n && n <= CAPACITY(*l)));

  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);

    insertLast(l, val);
  }
}

void displayList(ListDin l) {
  /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara
     kurung siku; antara dua elemen dipisahkan dengan separator "koma", tanpa
     tambahan
     karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
  /* I.S. l boleh kosong */
  /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika list kosong : menulis [] */

  printf("[");

  for (int i = 0; i < length(l); i++) {
    printf("%d", ELMT(l, i));
    if (i < length(l) - 1) {
      printf(",");
    }
  }

  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
  /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
  /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
   * indeks yang sama dijumlahkan */
  /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
   * elemen l2 pada indeks yang sama */

  const int len = length(l1);

  ListDin res;
  CreateListDin(&res, len);

  for (int i = 0; i < len; i++) {
    ElType cnt;
    if (plus) {
      cnt = ELMT(l1, i) + ELMT(l2, i);
    } else {
      cnt = ELMT(l1, i) - ELMT(l2, i);
    }

    insertLast(&res, cnt);
  }

  return res;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
  /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua
   * elemennya sama */

  const int length1 = length(l1);

  if (length1 == length(l2)) {
    boolean isEq = true;

    for (int i = 0; isEq && i < length1; i++) {
      if (ELMT(l1, i) != ELMT(l2, i)) {
        isEq = false;
      }
    }

    return isEq;
  } else {
    return false;
  }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
  /* Search apakah ada elemen list l yang bernilai val */
  /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
  /* Jika tidak ada, mengirimkan VAL_UNDEF */
  /* Menghasilkan indeks tak terdefinisi (VAL_UNDEF) jika list l kosong */
  /* Skema Searching yang digunakan bebas */
  const int len = length(l);
  boolean isFound = false;
  int i;

  for (i = 0; !isFound && i < len; i++) {
    if (val == ELMT(l, i)) {
      isFound = true;
    }
  }

  if (isFound) {
    return i - 1;
  } else {
    return VAL_UNDEF;
  }
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min) {
  /* I.S. List l tidak kosong */
  /* F.S. max berisi nilai maksimum l;
          min berisi nilai minimum l */

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
void copyList(ListDin lIn, ListDin *lOut) {
  /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
  /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
  /* Proses : Menyalin isi lIn ke lOut */

  const int len = length(lIn);

  CreateListDin(lOut, CAPACITY(lIn));

  for (int i = 0; i < len; i++) {
    insertLast(lOut, ELMT(lIn, i));
  }
}

ElType sumList(ListDin l) {
  /* Menghasilkan hasil penjumlahan semua elemen l */
  /* Jika l kosong menghasilkan 0 */

  int sum = 0;

  const int len = length(l);

  for (int i = 0; i < len; i++) {
    sum += ELMT(l, i);
  }

  return sum;
}

int countVal(ListDin l, ElType val) {
  /* Menghasilkan berapa banyak kemunculan val di l */
  /* Jika l kosong menghasilkan 0 */

  int cnt = 0;
  const int len = length(l);

  for (int i = 0; i < len; i++) {
    if (ELMT(l, i) == val) {
      cnt++;
    }
  }

  return cnt;
}

boolean isAllEven(ListDin l) {
  /* Menghailkan true jika semua elemen l genap. l boleh kosong */

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
void sort(ListDin *l, boolean asc) {
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
void insertLast(ListDin *l, ElType val) {
  /* Proses: Menambahkan X sebagai elemen terakhir list */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
  /* ********** MENGHAPUS ELEMEN ********** */

  ELMT(*l, length(*l)) = val;
}

void deleteLast(ListDin *l, ElType *val) {
  /* Proses : Menghapus elemen terakhir list */
  /* I.S. List tidak kosong */
  /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
  /*      Banyaknya elemen list berkurang satu */
  /*      List l mungkin menjadi kosong */

  const int pos = length(*l) - 1;
  *val = ELMT(*l, pos);

  ELMT(*l, pos) = VAL_UNDEF;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
  /* Proses : Menambahkan kapasitas sebanyak num */
  /* I.S. List sudah terdefinisi */
  /* F.S. Ukuran list bertambah sebanyak num */

  ElType *newBuffer = realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(int));

  if (newBuffer) {
    CAPACITY(*l) += num;
    BUFFER(*l) = newBuffer;
  }
}

void shrinkList(ListDin *l, int num) {
  /* Proses : Mengurangi kapasitas sebanyak num */
  /* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity -
   * num. */
  /* F.S. Ukuran list berkurang sebanyak num. */
  ElType *newBuffer = realloc(BUFFER(*l), (CAPACITY(*l) - num) * sizeof(int));

  if (newBuffer) {
    CAPACITY(*l) -= num;
    BUFFER(*l) = newBuffer;
  }
}

void compactList(ListDin *l) {
  /* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
  /* I.S. List tidak kosong */
  /* F.S. Ukuran Capacity = nEff */

  const int len = length(*l);

  ElType *newBuffer = realloc(BUFFER(*l), len * sizeof(int));

  if (newBuffer) {
    CAPACITY(*l) = len;
    BUFFER(*l) = newBuffer;
  }
}