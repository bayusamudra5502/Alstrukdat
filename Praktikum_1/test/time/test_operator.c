#include <check.h>

#include "../../src/time.h"
#include "test.h"

START_TEST(operatorTEQ) {
  TIME t1 = MakeTIME(12, 5, 3);
  TIME t2 = MakeTIME(0, 0, 0);
  TIME t3 = DetikToTIME(86400);
  TIME t4 = MakeTIME(12, 5, 3);

  ck_assert(TEQ(t1, t4));
  ck_assert(TEQ(t2, t3));

  ck_assert(!TEQ(t1, t3));
  ck_assert(!TEQ(t2, t4));
}
END_TEST

START_TEST(operatorTNEQ) {
  TIME t1 = MakeTIME(12, 5, 3);
  TIME t2 = MakeTIME(0, 0, 0);
  TIME t3 = DetikToTIME(86400);
  TIME t4 = MakeTIME(12, 5, 3);

  ck_assert(!TNEQ(t1, t4));
  ck_assert(!TNEQ(t2, t3));

  ck_assert(TNEQ(t1, t3));
  ck_assert(TNEQ(t2, t4));
}
END_TEST

START_TEST(operatorTLT) {
  TIME t1 = MakeTIME(12, 5, 3);
  TIME t2 = MakeTIME(0, 0, 0);
  TIME t3 = DetikToTIME(86400);
  TIME t4 = MakeTIME(12, 5, 3);

  ck_assert(!TLT(t1, t4));
  ck_assert(!TLT(t2, t3));

  ck_assert(TLT(t3, t1));
  ck_assert(TLT(t2, t4));

  ck_assert(!TLT(t1, t3));
  ck_assert(!TLT(t4, t2));
}
END_TEST

START_TEST(operatorTGT) {
  TIME t1 = MakeTIME(12, 5, 3);
  TIME t2 = MakeTIME(0, 0, 0);
  TIME t3 = DetikToTIME(86400);
  TIME t4 = MakeTIME(12, 5, 3);

  ck_assert(!TGT(t1, t4));
  ck_assert(!TGT(t2, t3));

  ck_assert(!TGT(t3, t1));
  ck_assert(!TGT(t2, t4));

  ck_assert(TGT(t1, t3));
  ck_assert(TGT(t4, t2));
}
END_TEST

TCase* test_operator() {
  TCase* tc = tcase_create("Tes Operator");
  tcase_add_test(tc, operatorTEQ);
  tcase_add_test(tc, operatorTNEQ);
  tcase_add_test(tc, operatorTLT);
  tcase_add_test(tc, operatorTGT);

  return tc;
}