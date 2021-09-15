#include <check.h>

#include "test.h"

Suite* listdin_suite() {
  Suite* s = suite_create("ADT ListDin Suite");

  // Add All Test Case
  suite_add_tcase(s, test_constructor_listdin());
  suite_add_tcase(s, test_selektor_listdin());
  suite_add_tcase(s, test_kosong_listdin());
  suite_add_tcase(s, test_math_listdin());
  suite_add_tcase(s, test_op_listdin());
  suite_add_tcase(s, test_cari_listdin());
  suite_add_tcase(s, test_sort_listdin());
  suite_add_tcase(s, test_pushpop_listdin());

  return s;
}