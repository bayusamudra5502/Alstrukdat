#include <check.h>

#include "../../src/matrix.h"
#include "test.h"

START_TEST(tc_tambah) {
  int d1[3][2] = {{1, 5}, {8, 0}, {2, 1}};
  int d2[3][2] = {{3, -2}, {2, 9}, {1, 1}};
  int dans[3][2] = {{4, 3}, {10, 9}, {3, 2}};

  Matrix m1 = arrayToMatrix((int*)d1, 3, 2);
  Matrix m2 = arrayToMatrix((int*)d2, 3, 2);
  Matrix mans = arrayToMatrix((int*)dans, 3, 2);

  Matrix res = addMatrix(m1, m2);

  isEqualTC(mans, res);
}
END_TEST

START_TEST(tc_kurang) {
  int d1[3][2] = {{1, 5}, {8, 0}, {2, 1}};
  int d2[3][2] = {{3, -2}, {2, 9}, {1, 1}};
  int dans[3][2] = {{-2, 7}, {6, -9}, {1, 0}};

  Matrix m1 = arrayToMatrix((int*)d1, 3, 2);
  Matrix m2 = arrayToMatrix((int*)d2, 3, 2);
  Matrix mans = arrayToMatrix((int*)dans, 3, 2);

  Matrix res = subtractMatrix(m1, m2);

  isEqualTC(mans, res);
}
END_TEST

START_TEST(tc_kaliMatriks) {
  int d1[3][2] = {{1, 5}, {8, 0}, {2, 1}};
  int d2[2][4] = {{3, -2, 1, 0}, {2, 9, 0, 10}};
  int dans[3][4] = {{13, 43, 1, 50}, {24, -16, 8, 0}, {8, 5, 2, 10}};

  Matrix m1 = arrayToMatrix((int*)d1, 3, 2);
  Matrix m2 = arrayToMatrix((int*)d2, 2, 4);
  Matrix mans = arrayToMatrix((int*)dans, 3, 4);

  Matrix res = multiplyMatrix(m1, m2);

  isEqualTC(mans, res);
}
END_TEST

START_TEST(tc_kali_konstan) {
  int d1[3][2] = {{1, 5}, {8, 0}, {2, 1}};
  int dans[3][2] = {{2, 10}, {16, 0}, {4, 2}};

  Matrix m1 = arrayToMatrix((int*)d1, 3, 2);
  Matrix mans = arrayToMatrix((int*)dans, 3, 2);

  Matrix res = multiplyConst(m1, 2);

  isEqualTC(mans, res);
}
END_TEST

TCase* test_aritmatika_matrix() {
  TCase* tc = tcase_create("Tes Aritmatika");
  tcase_add_test(tc, tc_tambah);
  tcase_add_test(tc, tc_kurang);
  tcase_add_test(tc, tc_kaliMatriks);
  tcase_add_test(tc, tc_kali_konstan);

  return tc;
}