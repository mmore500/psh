#include "test_path.h"

// unit test for execute path
static bool test_exec_path() {
  int pass = true;
  return pass;
}

// run all unit tests in this file
bool runtests_path() {
  bool pass = true;
  pass &= runtest(test_exec_path, "execute path");
  return pass;
}
