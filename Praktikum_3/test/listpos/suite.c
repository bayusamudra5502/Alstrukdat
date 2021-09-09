#include <check.h>

#include "test.h"

Suite* listpos_suite() {
  Suite* s = suite_create("Point Suite");

  // Add All Test Case
  suite_add_tcase(s, test_constructor_listpos());
  suite_add_tcase(s, test_selektor_listpos());
  suite_add_tcase(s, test_kosong_listpos());
  suite_add_tcase(s, test_math_listpos());
  suite_add_tcase(s, test_op_listpos());
  suite_add_tcase(s, test_cari_listpos());
  suite_add_tcase(s, test_sort_listpos());
  suite_add_tcase(s, test_pushpop_listpos());

  return s;
}