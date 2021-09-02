#include <check.h>

#include "test.h"

Suite* time_suite() {
  Suite* s = suite_create("Time Suite");

  // Add All Test Case
  suite_add_tcase(s, test_constructor());
  suite_add_tcase(s, test_predikat());
  suite_add_tcase(s, test_konversi());
  suite_add_tcase(s, test_operator());
  suite_add_tcase(s, test_operasi());
  suite_add_tcase(s, test_durasi());

  return s;
}