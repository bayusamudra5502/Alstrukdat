#include <check.h>

#include "../../src/point.h"
#include "test.h"

START_TEST(geserx1) {
  POINT p1, p2, p3, p4;
  p1 = MakePOINT(2, 5);
  p2 = MakePOINT(4.143, 8.9233);
  p3 = MakePOINT(0, 0);
  p4 = MakePOINT(3.143, 8.9233);

  ck_assert(EQ(MakePOINT(3, 5), NextX(p1)));
  ck_assert(EQ(MakePOINT(5.143, 8.9233), NextX(p2)));  // Kasus X = 3.143
  ck_assert(EQ(MakePOINT(1, 0), NextX(p3)));
  ck_assert(EQ(MakePOINT(4.143, 8.9233), NextX(p4)));  // Kasus X = 3.143

  ck_assert(EQ(MakePOINT(2, 6), NextY(p1)));
  ck_assert(EQ(MakePOINT(4.143, 9.9233), NextY(p2)));
  ck_assert(EQ(MakePOINT(0, 1), NextY(p3)));
}
END_TEST

START_TEST(cermin) {
  POINT p1, p2, p3;
  p1 = MakePOINT(2, 5);
  p2 = MakePOINT(4.143, 8.9233);
  p3 = MakePOINT(0, 0);

  ck_assert(EQ(MakePOINT(2, -5), MirrorOf(p1, true)));
  ck_assert(EQ(MakePOINT(4.143, -8.9233), MirrorOf(p2, true)));
  ck_assert(EQ(MakePOINT(0, 0), MirrorOf(p3, true)));

  ck_assert(EQ(MakePOINT(-2, 5), MirrorOf(p1, false)));
  ck_assert(EQ(MakePOINT(-4.143, 8.9233), MirrorOf(p2, false)));
  ck_assert(EQ(MakePOINT(0, 0), MirrorOf(p3, false)));
}
END_TEST

START_TEST(plus) {
  POINT p1, p2;
  p1 = MakePOINT(2, 5);
  p2 = MakePOINT(4.1, 8.9);

  ck_assert(EQ(MakePOINT(4, 6.25), PlusDelta(p1, 2, 1.25)));
  ck_assert(EQ(MakePOINT(6.1, 9.9), PlusDelta(p2, 2, 1)));
}
END_TEST

TCase* test_operasi_point() {
  TCase* tc = tcase_create("Tes Operasi");
  tcase_add_test(tc, geserx1);
  tcase_add_test(tc, cermin);
  tcase_add_test(tc, plus);

  return tc;
}