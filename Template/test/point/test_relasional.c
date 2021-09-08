#include <check.h>

#include "../../src/point.h"
#include "test.h"

START_TEST(sama) {
  POINT p1, p2, p3, p4;
  p1 = MakePOINT(2, 5);
  p2 = MakePOINT(3.143, 8.9233);
  p3 = MakePOINT(2, 5);
  p4 = MakePOINT(3.143, 8.9233);

  ck_assert(!EQ(p1, p2));
  ck_assert(EQ(p1, p3));
  ck_assert(EQ(p2, p4));
  ck_assert(!EQ(p2, p3));
}
END_TEST

START_TEST(taksama) {
  POINT p1, p2, p3, p4;
  p1 = MakePOINT(2, 5);
  p2 = MakePOINT(3.143, 8.9233);
  p3 = MakePOINT(2, 5);
  p4 = MakePOINT(3.143, 8.9233);

  ck_assert(NEQ(p1, p2));
  ck_assert(!NEQ(p1, p3));
  ck_assert(!NEQ(p2, p4));
  ck_assert(NEQ(p2, p3));
}
END_TEST

TCase* test_relasional_point() {
  TCase* tc = tcase_create("Tes Relasional");
  tcase_add_test(tc, sama);
  tcase_add_test(tc, taksama);

  return tc;
}