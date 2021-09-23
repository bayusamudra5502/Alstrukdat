#include <check.h>
#include <stdlib.h>

#include "../../src/matrix.h"
#include "test.h"

START_TEST(tc_isIdxValid) {
  // Tes positif
  ck_assert(isIdxValid(0, 0));
  ck_assert(isIdxValid(0, 1));
  ck_assert(isIdxValid(1, 0));
  ck_assert(isIdxValid(12, 15));
  ck_assert(isIdxValid(99, 0));
  ck_assert(isIdxValid(0, 99));

  // Tes Negatif
  ck_assert(!isIdxValid(0, COL_CAP));
  ck_assert(!isIdxValid(ROW_CAP, 0));
  ck_assert(!isIdxValid(-1, 0));
  ck_assert(!isIdxValid(0, -1));
  ck_assert(!isIdxValid(-1, -1));
  ck_assert(!isIdxValid(ROW_CAP + rand(), COL_CAP + rand()));
}
END_TEST

START_TEST(tc_isIdxEff) {
  // Tes Positif
  Matrix t;
  CreateMatrix(20, 50, &t);

  ck_assert(isIdxEff(t, 1, 2));
  ck_assert(isIdxEff(t, 0, 0));
  ck_assert(isIdxEff(t, 19, 49));

  ck_assert(!isIdxEff(t, -1, 0));
  ck_assert(!isIdxEff(t, 0, -1));
  ck_assert(!isIdxEff(t, 20, 20));
  ck_assert(!isIdxEff(t, 19, 50));
  ck_assert(!isIdxEff(t, 123, 321));
  ck_assert(!isIdxEff(t, 80, 85));
}
END_TEST

START_TEST(tc_getLastIdx) {
  // Tes Positif
  Matrix t;
  CreateMatrix(20, 50, &t);

  ck_assert_int_eq(getLastIdxCol(t), 49);
  ck_assert_int_eq(getLastIdxRow(t), 19);
}
END_TEST

START_TEST(tc_elmtDiagonal) {
  int data1[4][4] = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}};
  int data2[3][4] = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}};
  int data3[5][4] = {
      {1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}, {5, 0, 0, 0}};

  Matrix m1 = arrayToMatrix((int*)data1, 4, 4);
  Matrix m2 = arrayToMatrix((int*)data2, 3, 4);
  Matrix m3 = arrayToMatrix((int*)data3, 5, 4);

  ck_assert_int_eq(getElmtDiagonal(m1, 1), 2);
  ck_assert_int_eq(getElmtDiagonal(m2, 1), 2);
  ck_assert_int_eq(getElmtDiagonal(m3, 1), 2);

  ck_assert_int_eq(getElmtDiagonal(m1, 2), 3);
  ck_assert_int_eq(getElmtDiagonal(m2, 2), 3);
  ck_assert_int_eq(getElmtDiagonal(m3, 2), 3);
}
END_TEST

TCase* test_selektor_matrix() {
  TCase* tc = tcase_create("Tes Selektor");
  tcase_add_test(tc, tc_isIdxValid);
  tcase_add_test(tc, tc_isIdxEff);
  tcase_add_test(tc, tc_getLastIdx);
  tcase_add_test(tc, tc_elmtDiagonal);

  return tc;
}