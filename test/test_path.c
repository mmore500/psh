#include "test_path.h"

// unit test for execute path
static bool test_exec_path() {
  int pass = true;

  char *arg = NULL;

  pid_t pid_orig = getpid();

  pass &= (0 == exec_path("/usr/bin/true", &arg, true, false));
  pass &= (0 == exec_path("/usr/bin/false", NULL, true, true));
  pass &= (1 == exec_path("asdfksadfasdfasdf", &arg, true, false));

  pass &= (getpid() == pid_orig);

  pass &= (0 == exec_path("/usr/bin/true", &arg, true, true));
  pass &= (0 == exec_path("/usr/bin/false", NULL, false, true));
  pass &= (0 == exec_path("asdfksadfasdfasdf", &arg, false, true));

  pass &= (getpid() == pid_orig);

  return pass;
}

// run all unit tests in this file
bool runtests_path() {
  bool pass = true;
  pass &= runtest(test_exec_path, "execute path");
  return pass;
}
