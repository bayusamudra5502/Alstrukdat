#include <check.h>

#include "../../src/matrix.h"
#include "test.h"

START_TEST(tc_copy) {
  // Testing copyMatrix
  int data1[4][4] = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}};
  int data2[3][4] = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}};
  int data3[5][4] = {
      {1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}, {5, 0, 0, 0}};

  Matrix m1 = arrayToMatrix((int*)data1, 4, 4);
  Matrix m2 = arrayToMatrix((int*)data2, 3, 4);
  Matrix m3 = arrayToMatrix((int*)data3, 5, 4);

  Matrix c1, c2, c3;

  copyMatrix(m1, &c1);
  copyMatrix(m2, &c2);
  copyMatrix(m3, &c3);

  ck_assert(isEqual(m1, c1));
  ck_assert(isEqual(m2, c2));
  ck_assert(isEqual(m3, c3));

  ck_assert(isSizeEqual(m1, c1));
  ck_assert(isSizeEqual(m2, c2));
  ck_assert(isSizeEqual(m3, c3));
}
END_TEST

TCase* test_copy_matrix() {
  TCase* tc = tcase_create("Tes Copy");
  tcase_add_test(tc, tc_copy);

  return tc;
}