#include <check.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(tes_length) {
  ListPos l1;
  CreateListPos(&l1);

  for (int i = 0; i < CAPACITY; i++) {
    ck_assert_int_eq(l1.contents[i], VAL_UNDEF);
  }
}
END_TEST

TCase* test_constructor_listpos() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, tes_length);

  return tc;
}