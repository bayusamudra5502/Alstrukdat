#include <check.h>
#include <stdlib.h>

#include "listdin/test.h"

int main() {
  int no_failed = 0;

  Suite* s0 = listdin_suite();
  SRunner* run = srunner_create(s0);

  // srunner_add_suite(run, point_suite());

  srunner_run_all(run, CK_NORMAL);
  no_failed = srunner_ntests_failed(run);
  srunner_free(run);

  return no_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
