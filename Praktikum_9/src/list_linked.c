/**
 * Nama : Bayu Samudra
 * NIM : 13520128
 */
#include "list_linked.h"

#include <stdio.h>

boolean lastActionFailed = false;

void CreateList(List *l) {
  /* I.S. sembarang             */
  /* F.S. Terbentuk list kosong */
  FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) { /* Mengirim true jika list kosong */
  return !FIRST(l);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
  /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. Mengembalikan nilai elemen l pada indeks idx */

  Address p = FIRST(l);

  for (int i = idx; i > 0; i--) {
    p = NEXT(p);
  }

  return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
  /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

  Address p = FIRST(*l);

  for (int i = idx; i > 0; i--) {
    p = NEXT(p);
  }

  INFO(p) = val;
}

int indexOf(List l, ElType val) {
  /* I.S. l, val terdefinisi */
  /* F.S. Mencari apakah ada elemen list l yang bernilai val */
  /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
  /* Mengembalikan IDX_UNDEF jika tidak ditemukan */

  int i = 0;
  boolean found = false;
  Address p = FIRST(l);

  do {
    if (INFO(p) == val) {
      found = true;
    } else {
      i++;
      p = NEXT(p);
    }
  } while (p && !found);

  if (found) {
    return i;
  } else {
    return IDX_UNDEF;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
  /* I.S. l mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
  /* Jika alokasi gagal: I.S.= F.S. */

  Address n = newNode(val);

  if (n) {
    NEXT(n) = FIRST(*l);
    FIRST(*l) = n;
  } else {
    lastActionFailed = true;
  }
}

void insertLast(List *l, ElType val) {
  /* I.S. l mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen list di akhir: elemen terakhir yang baru */
  /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

  if (isEmpty(*l)) {
    insertFirst(l, val);
  } else {
    Address n = newNode(val);

    if (n) {
      Address p = FIRST(*l);

      while (NEXT(p) != NULL) {
        p = NEXT(p);
      }

      NEXT(p) = n;
    } else {
      lastActionFailed = true;
    }
  }
}

void insertAt(List *l, ElType val, int idx) {
  /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu
   * 0..length(l) */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di
   * i)
   */
  /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

  if (idx == 0) {
    insertFirst(l, val);
  } else {
    Address p = FIRST(*l);
    Address n = newNode(val);

    if (n) {
      for (int i = 0; i < idx - 1; i++) {
        p = NEXT(p);
      }

      NEXT(n) = NEXT(p);
      NEXT(p) = n;
    } else {
      lastActionFailed = true;
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
  /* I.S. List l tidak kosong  */
  /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
  /*      dan alamat elemen pertama di-dealokasi */

  Address p = FIRST(*l);
  *val = INFO(p);

  FIRST(*l) = NEXT(p);
  free(p);
}

void deleteLast(List *l, ElType *val) {
  /* I.S. list tidak kosong */
  /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
  /*      dan alamat elemen terakhir di-dealokasi */

  if (length(*l) > 1) {
    Address p = FIRST(*l);
    Address pl = NULL;

    while (NEXT(p) != NULL) {
      pl = p;
      p = NEXT(p);
    }

    *val = INFO(p);

    NEXT(pl) = NULL;
    free(p);
  } else {
    deleteFirst(l, val);
  }
}

void deleteAt(List *l, int idx, ElType *val) {
  /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l)
   */
  /* F.S. val diset dengan elemen l pada indeks ke-idx. */
  /*      Elemen l pada indeks ke-idx dihapus dari l */

  if (idx == 0) {
    deleteFirst(l, val);
  } else {
    Address p = FIRST(*l);
    Address ptmp = NULL;

    for (int i = 0; i < idx - 1; i++) {
      p = NEXT(p);
    }

    ptmp = NEXT(p);
    *val = INFO(ptmp);

    NEXT(p) = NEXT(ptmp);
    free(ptmp);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
  // void printInfo(List l);
  /* I.S. List mungkin kosong */
  /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika list kosong : menulis [] */
  /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
  printf("[");

  Address p = FIRST(l);

  while (p) {
    printf("%d", INFO(p));

    if (NEXT(p)) {
      printf(",");
    }

    p = NEXT(p);
  }

  printf("]");
}

int length(List l) {
  /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

  int len = 0;
  Address p = FIRST(l);

  while (p) {
    p = NEXT(p);
    len++;
  }

  return len;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
  /* I.S. l1 dan l2 sembarang */
  /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
  /* Konkatenasi dua buah list : l1 dan l2    */
  /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan).
   */
  /* Tidak ada alokasi/dealokasi pada prosedur ini */

  List result;
  CreateList(&result);

  Address p = FIRST(l1);
  while (p) {
    insertLast(&result, INFO(p));
    p = NEXT(p);
  }

  p = FIRST(l2);
  while (p) {
    insertLast(&result, INFO(p));
    p = NEXT(p);
  }

  return result;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
  /* Mencari apakah ada elemen list yang beralamat P */
  /* Mengirimkan true jika ada, false jika tidak ada */
  Address p = FIRST(L);
  boolean isFound = false;

  while (!isFound && p) {
    if (p == P) {
      isFound = true;
    } else {
      p = NEXT(p);
    }
  }

  return isFound;
}

Address searchPrec(List L, ElType X) {
  /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
  /* Mencari apakah ada elemen list dengan Info(P)=X */
  /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
  /* Jika tidak ada, mengirimkan Nil */
  /* Jika P adalah elemen pertama, maka Prec=Nil */
  /* Search dengan spesifikasi seperti ini menghindari */
  /* traversal ulang jika setelah Search akan dilakukan operasi lain */
  Address p = FIRST(L);
  Address pl = NULL;
  boolean isFound = false;

  while (!isFound && p) {
    if (INFO(p) == X) {
      isFound = true;
    } else {
      pl = p;
      p = NEXT(p);
    }
  }

  if (isFound) {
    return pl;
  } else {
    return NULL;
  }
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List L) {
  /* Mengirimkan nilai info(P) yang maksimum */
  return INFO(adrMax(L));
}

Address adrMax(List L) {
  /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
  Address p = FIRST(L);
  Address maxp = p;

  while (p) {
    if (INFO(p) > INFO(maxp)) {
      maxp = p;
    }

    p = NEXT(p);
  }

  return maxp;
}

ElType min(List L) {
  /* Mengirimkan nilai info(P) yang minimum */
  return INFO(adrMin(L));
}

Address adrMin(List L) {
  /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
  Address p = FIRST(L);
  Address minp = p;

  while (p) {
    if (INFO(p) < INFO(minp)) {
      minp = p;
    }

    p = NEXT(p);
  }

  return minp;
}

float average(List L) {
  /* Mengirimkan nilai rata-rata info(P) */
  if (isEmpty(L)) {
    return 0;
  } else {
    int len = 0;
    Address p = FIRST(L);
    int sum = 0;

    while (p) {
      sum += INFO(p);
      len++;

      p = NEXT(p);
    }

    float avg = ((float)sum) / len;
    return (avg == 0) ? 0 : avg;
  }
}

void delAll(List *L) {
  /* Delete semua elemen list dan alamat elemen di-dealokasi */
  Address p = FIRST(*L);

  while (p) {
    Address stage = p;
    p = NEXT(p);

    free(stage);
  }

  *L = NULL;
}

void inverseList(List *L) {
  /* I.S. sembarang. */
  /* F.S. elemen list dibalik : */
  /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
  /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

  Address p = FIRST(*L);
  Address pl = NULL, pn;

  while (p) {
    pn = NEXT(p);
    NEXT(p) = pl;
    pl = p;
    p = pn;
  }

  *L = pl;
}

List fInverseList(List L) {
  /* Mengirimkan list baru, hasil invers dari L */
  /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
  /* Jika alokasi gagal, hasilnya list kosong */
  /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
  Address p = FIRST(L);
  List result;
  lastActionFailed = false;

  CreateList(&result);
  while (p && !lastActionFailed) {
    insertFirst(&result, INFO(p));
    p = NEXT(p);
  }

  if (lastActionFailed) {
    delAll(&result);
  }

  return result;
}

void copyList(List *L1, List *L2) {
  /* I.S. L1 sembarang. F.S. L2=L1 */
  /* L1 dan L2 "menunjuk" kepada list yang sama.*/
  /* Tidak ada alokasi/dealokasi elemen */

  *L2 = *L1;
}

List fCopyList(List L) {
  /* Mengirimkan list yang merupakan salinan L */
  /* dengan melakukan alokasi. */
  /* Jika ada alokasi gagal, hasilnya list kosong dan */
  /* semua elemen yang terlanjur di-alokasi, harus didealokasi */

  Address p = FIRST(L);
  List result;
  lastActionFailed = false;

  CreateList(&result);
  while (p && !lastActionFailed) {
    insertLast(&result, INFO(p));
    p = NEXT(p);
  }

  if (lastActionFailed) {
    delAll(&result);
  }

  return result;
}

void cpAllocList(List Lin, List *Lout) {
  /* I.S. Lin sembarang. */
  /* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
  /* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
   * dialokasi, didealokasi */
  /* dengan melakukan alokasi elemen. */
  /* Lout adalah list kosong jika ada alokasi elemen yang gagal */

  *Lout = fCopyList(Lin);
}

void splitList(List *L1, List *L2, List L) {
  /* I.S. L mungkin kosong */
  /* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
  /* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
  /* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
  /* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */

  CreateList(L1);
  CreateList(L2);

  int len = length(L);
  Address p = FIRST(L);

  for (int i = 0; i < len / 2; i++) {
    insertLast(L1, INFO(p));
    p = NEXT(p);
  }

  while (p) {
    insertLast(L2, INFO(p));
    p = NEXT(p);
  }
}