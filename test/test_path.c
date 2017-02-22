#include "test_path.h"

// unit test
static bool test_something() {
  int pass = true;
  return pass;
}

// run all unit tests in this file
bool runtests_path() {
  bool pass = true;
  pass &= runtest(test_something, "something");
  return pass;
}
