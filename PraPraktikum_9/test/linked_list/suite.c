#include <check.h>

#include "test.h"

Suite* linked_suite() {
  Suite* s = suite_create("LInked List Suite");

  // Add All Test Case
  suite_add_tcase(s, test_constructor());
  suite_add_tcase(s, test_insertf());
  suite_add_tcase(s, test_helper());
  suite_add_tcase(s, test_idxo());
  suite_add_tcase(s, test_length());
  suite_add_tcase(s, test_concat());
  suite_add_tcase(s, test_insert());
  suite_add_tcase(s, test_delete());
  suite_add_tcase(s, test_setget());

  return s;
}