#include <check.h>

#include "../../src/matrix.h"
#include "test.h"

START_TEST(tc_determinan) {
  Matrix m1;

  int arr1[4][4] = {
      {13, 43, 1, 50}, {26, -16, 8, 0}, {8, 5, 2, 10}, {10, 3, 2, 1}};

  m1 = arrayToMatrix(arr1, 4, 4);

  ck_assert_float_eq(determinant(m1), 1098);
}
END_TEST

TCase* test_determinant_matrix() {
  TCase* tc = tcase_create("Tes Determinan");
  tcase_add_test(tc, tc_determinan);

  return tc;
}