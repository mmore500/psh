#include "test_local.h"

// unit test for local search for executable
static bool test_searchcwd() {
  int pass = true;
  return pass;
}

// unit test for bin search for executable
static bool test_searchbins() {
  int pass = true;
  return pass;
}

// run all unit tests in this file
bool runtests_local() {
  bool pass = true;
  pass &= runtest(test_searchcwd, "searchcwd");
  pass &= runtest(test_searchbins, "searchbins");
  return pass;
}
