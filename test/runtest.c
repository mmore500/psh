#include "runtest.h"

/*
 * Run a unit test, which returns true if it passed, and print the results.
 *
 * @param funptr A pointer to the unit test to run.
 * @param name A string describing the unit test being run.
 * @return A boolean value that is true of the test passed, false otherwise.
 */
bool runtest(bool (*funptr)(), const char *name) {

  printf("Running test %s...\n", name);
  bool pass = (*funptr)();
  printf("Test %s status: %s.\n", name, pass ? "passed" : "failed");

  return(pass);

}
