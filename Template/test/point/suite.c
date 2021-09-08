#include <check.h>

#include "test.h"

Suite* point_suite() {
  Suite* s = suite_create("Point Suite");

  // Add All Test Case
  suite_add_tcase(s, test_constructor_point());
  suite_add_tcase(s, test_jarak_point());
  suite_add_tcase(s, test_relasional_point());
  suite_add_tcase(s, test_operasi_point());
  suite_add_tcase(s, test_transformasi_point());
  suite_add_tcase(s, test_lokasi_point());

  return s;
}