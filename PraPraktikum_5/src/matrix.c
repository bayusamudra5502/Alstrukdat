/* File    : matrix.c
 * Tanggal : 21 September 2021
 * Nama	   : Bayu Samudra
 * NIM     : 13520128
 *
 * Implementasi ABSTRACT DATA TYPE MATRIX
 *
 */

#include "matrix.h"

#include <math.h>
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m) {
  /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di
   * "ujung kiri" memori */
  /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
  /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
  ROWS(*m) = nRow;
  COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j) {
  /* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
  return i < ROW_CAP && j < COL_CAP && i >= 0 && j >= 0;
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m) {
  /* Mengirimkan Index baris terbesar m */
  return ROWS(m) - 1;
}

Index getLastIdxCol(Matrix m) {
  /* Mengirimkan Index kolom terbesar m */
  return COLS(m) - 1;
}

boolean isIdxEff(Matrix m, Index i, Index j) {
  /* Mengirimkan true jika i, j adalah Index efektif bagi m */
  return isIdxValid(i, j) && i < ROWS(m) && j < COLS(m);
}

ElType getElmtDiagonal(Matrix m, Index i) {
  /* Mengirimkan elemen m(i,i) */
  return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
  /* Melakukan assignment MRes = MIn */
  CreateMatrix(ROWS(mIn), COLS(mIn), mRes);

  for (int i = 0; i < ROWS(mIn); i++) {
    for (int j = 0; j < COLS(mIn); j++) {
      ELMT(*mRes, i, j) = ELMT(mIn, i, j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
  /* I.S. isIdxValid(nRow,nCol) */
  /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
  /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
  /* Selanjutnya membaca nilai elemen per baris dan kolom */
  /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
  1 2 3
  4 5 6
  8 9 10
  */

  ElType input;
  CreateMatrix(nRow, nCol, m);

  for (int i = 0; i < nRow; i++) {
    for (int j = 0; j < nCol; j++) {
      scanf("%d", &input);
      ELMT(*m, i, j) = input;
    }
  }
}

void displayMatrix(Matrix m) {
  /* I.S. m terdefinisi */
  /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing
     elemen per baris dipisahkan sebuah spasi */
  /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris
   * dan per kolom */
  /* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
  1 2 3
  4 5 6
  8 9 10
  */

  for (int i = 0; i < ROWS(m); i++) {
    for (int j = 0; j < COLS(m); j++) {
      printf("%d", ELMT(m, i, j));

      if (j < COLS(m) - 1) {
        printf(" ");
      }
    }

    if (i < ROWS(m) - 1) {
      printf("\n");
    }
  }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
  /* Prekondisi : m1 berukuran sama dengan m2 */
  /* Mengirim hasil penjumlahan matriks: m1 + m2 */
  Matrix result;

  CreateMatrix(ROWS(m1), COLS(m1), &result);

  for (int i = 0; i < ROWS(m1); i++) {
    for (int j = 0; j < COLS(m1); j++) {
      ELMT(result, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
    }
  }

  return result;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
  /* Prekondisi : m1 berukuran sama dengan m2 */
  /* Mengirim hasil pengurangan matriks: salinan m1 ??? m2 */
  Matrix result;

  CreateMatrix(ROWS(m1), COLS(m1), &result);

  for (int i = 0; i < ROWS(m1); i++) {
    for (int j = 0; j < COLS(m1); j++) {
      ELMT(result, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
    }
  }

  return result;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
  /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
  /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
  Matrix result;

  CreateMatrix(ROWS(m1), COLS(m2), &result);

  for (int i = 0; i < ROWS(m1); i++) {
    for (int j = 0; j < COLS(m2); j++) {
      ELMT(result, i, j) = 0;

      for (int k = 0; k < COLS(m1); k++) {
        ELMT(result, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
      }
    }
  }

  return result;
}

Matrix multiplyConst(Matrix m, ElType x) {
  /* Mengirim hasil perkalian setiap elemen m dengan x */
  Matrix result;

  copyMatrix(m, &result);
  pMultiplyConst(&result, x);

  return result;
}

void pMultiplyConst(Matrix *m, ElType k) {
  /* I.S. m terdefinisi, k terdefinisi */
  /* F.S. Mengalikan setiap elemen m dengan k */

  for (int i = 0; i < ROWS(*m); i++) {
    for (int j = 0; j < COLS(*m); j++) {
      ELMT(*m, i, j) *= 2;
    }
  }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2) {
  /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
  /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
  /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */

  if (isSizeEqual(m1, m2)) {
    boolean isEq = true;

    for (int i = 0; i < ROWS(m1) && isEq; i++) {
      for (int j = 0; j < COLS(m2) && isEq; j++) {
        isEq = isEq && (ELMT(m1, i, j) == ELMT(m2, i, j));
      }
    }

    return isEq;
  } else {
    return false;
  }
}

boolean isNotEqual(Matrix m1, Matrix m2) {
  /* Mengirimkan true jika m1 tidak sama dengan m2 */
  return !isEqual(m1, m2);
}

boolean isSizeEqual(Matrix m1, Matrix m2) {
  /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif
   * m2
   */
  return COLS(m1) == COLS(m2) && ROWS(m1) == ROWS(m2);
}

/* ********** Operasi lain ********** */
int count(Matrix m) {
  /* Mengirimkan banyaknya elemen m */

  return COLS(m) * ROWS(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
  /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
  return ROWS(m) == COLS(m);
}

boolean isSymmetric(Matrix m) {
  /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
     dan untuk setiap elemen m, m(i,j)=m(j,i) */

  if (isSquare(m)) {
    Matrix p;
    copyMatrix(m, &p);
    transpose(&p);

    return isEqual(m, p);
  } else {
    return false;
  }
}

boolean isIdentity(Matrix m) {
  /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
     setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai
     0
   */
  if (isSquare(m)) {
    boolean result = true;

    for (int i = 0; i < ROWS(m) && result; i++) {
      for (int j = 0; j < COLS(m) && result; j++) {
        if (i == j) {
          result = result && (ELMT(m, i, j));
        } else {
          result = result && (!ELMT(m, i, j));
        }
      }
    }

    return result;
  } else {
    return false;
  }
}

boolean isSparse(Matrix m) {
  /* Mengirimkan true jika m adalah matriks sparse: matriks ???jarang??? dengan
     definisi:
     hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

  int cnt = 0;

  for (int i = 0; i < ROWS(m); i++) {
    for (int j = 0; j < COLS(m); j++) {
      if (ELMT(m, i, j) != 0) {
        cnt++;
      }
    }
  }

  return cnt <= (ROWS(m) * COLS(m) / 20);
}

Matrix inverse1(Matrix m) {
  /* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan
   * (dikalikan -1) */
  Matrix result;
  copyMatrix(m, &result);
  pInverse1(&result);

  return result;
}

void pInverse1(Matrix *m) {
  /* I.S. m terdefinisi */
  /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

  for (int i = 0; i < ROWS(*m); i++) {
    for (int j = 0; j < COLS(*m); j++) {
      ELMT(*m, i, j) = (-1) * ELMT(*m, i, j);
    }
  }
}

Matrix kofaktorMatrix(Matrix m, int row, int col) {
  Matrix result;
  CreateMatrix(ROWS(m) - 1, COLS(m) - 1, &result);
  int rowConstant = 0;

  for (int i = 0; i < ROWS(m); i++) {
    if (i == row) {
      rowConstant = -1;
    } else {
      int colConstant = 0;

      for (int j = 0; j < COLS(m); j++) {
        if (j == col) {
          colConstant = -1;
        } else {
          ELMT(result, i + rowConstant, j + colConstant) = ELMT(m, i, j);
        }
      }
    }
  }

  return result;
}

float determinant(Matrix m) {
  /* Prekondisi: isSquare(m) */
  /* Menghitung nilai determinan m */
  if (ROWS(m) == 1) {
    return ELMT(m, 0, 0);
  } else {
    float result = 0, sign = 1;

    for (int i = 0; i < COLS(m); i++) {
      Matrix kofaktor = kofaktorMatrix(m, 0, i);
      result += determinant(kofaktor) * sign * ELMT(m, 0, i);

      sign *= -1;
    }

    return result == 0 ? 0 : result;
  }
}

void transpose(Matrix *m) {
  /* I.S. m terdefinisi dan isSquare(m) */
  /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan
   * elemen m(j,i) */

  for (int i = 0; i < ROWS(*m); i++) {
    for (int j = i; j < COLS(*m); j++) {
      // SWAPPING
      int tmp = ELMT(*m, i, j);
      ELMT(*m, i, j) = ELMT(*m, j, i);
      ELMT(*m, j, i) = tmp;
    }
  }
}
