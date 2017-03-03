#include "test_builtin.h"

// unit test for builtin pwd
static bool test_builtin_pwd() {
  int pass = true;
  return pass;
}

// unit test for builtin cd
static bool test_builtin_cd() {
  int pass = true;
  return pass;
}

// unit test for builtin history
static bool test_builtin_history() {
  int pass = true;
  return pass;
}

// unit test for handle builtin
static bool test_handle_builtin() {
  int pass = true;
  return pass;
}

// run all unit tests in this file
bool runtests_builtin() {
  bool pass = true;
  pass &= runtest(test_builtin_pwd, "builtin pwd");
  pass &= runtest(test_builtin_cd, "builtin cd");
  pass &= runtest(test_builtin_history, "builtin history");
  pass &= runtest(test_handle_builtin, "handle builtin");
  return pass;
}
