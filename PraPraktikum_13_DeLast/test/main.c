#include <check.h>
#include <stdlib.h>

#include "linked_list/test.h"

int main(int argc, char* argv[]) {
  int no_failed = 0;

  Suite* s0 = linked_suite();
  SRunner* run = srunner_create(s0);

  // srunner_add_suite(run, point_suite());

  if (argc > 1) {
    if (!strcmp(argv[1], "-tno-fork")) {
      srunner_set_fork_status(run, CK_NOFORK);
    }
  }

  srunner_run_all(run, CK_NORMAL);
  no_failed = srunner_ntests_failed(run);
  srunner_free(run);

  return no_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
