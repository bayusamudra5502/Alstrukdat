#include <check.h>
#include <stdlib.h>

#include "../../src/point.h"
#include "test.h"

START_TEST(tesorigin) {
  POINT p1, p2;
  p1 = MakePOINT(0, 0);
  p2 = MakePOINT(rand() + 1, rand() + 1);

  ck_assert(IsOrigin(p1));
  ck_assert(!IsOrigin(p2));
}
END_TEST

START_TEST(tesx) {
  POINT p1, p2, p3, p4, p5, p6;
  p1 = MakePOINT(0, 0);
  p2 = MakePOINT(10, 0);
  p3 = MakePOINT(-10, 0);
  p4 = MakePOINT(rand(), 0);

  p5 = MakePOINT(0, 1);
  p6 = MakePOINT(0, rand());

  ck_assert(IsOnSbX(p1));
  ck_assert(IsOnSbX(p2));
  ck_assert(IsOnSbX(p3));
  ck_assert(IsOnSbX(p4));
  ck_assert(!IsOnSbX(p5));
  ck_assert(!IsOnSbX(p6));
}
END_TEST

START_TEST(teskuadran) {
  POINT p1, p2, p3, p4;
  p1 = MakePOINT(1, 2);
  p2 = MakePOINT(-1, 2);
  p3 = MakePOINT(-1, -2);
  p4 = MakePOINT(1, -2);

  ck_assert_int_eq(Kuadran(p1), 1);
  ck_assert_int_eq(Kuadran(p2), 2);
  ck_assert_int_eq(Kuadran(p3), 3);
  ck_assert_int_eq(Kuadran(p4), 4);
}
END_TEST

START_TEST(tesy) {
  POINT p1, p2, p3, p4, p5, p6;
  p1 = MakePOINT(0, 0);
  p2 = MakePOINT(0, 10);
  p3 = MakePOINT(0, -10);
  p4 = MakePOINT(0, rand());

  p5 = MakePOINT(1, 0);
  p6 = MakePOINT(rand(), 0);

  ck_assert(IsOnSbY(p1));
  ck_assert(IsOnSbY(p2));
  ck_assert(IsOnSbY(p3));
  ck_assert(IsOnSbY(p4));
  ck_assert(!IsOnSbY(p5));
  ck_assert(!IsOnSbY(p6));
}
END_TEST

TCase* test_lokasi_point() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, tesorigin);
  tcase_add_test(tc, tesx);
  tcase_add_test(tc, tesy);
  tcase_add_test(tc, teskuadran);

  return tc;
}