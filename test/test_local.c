#include "test_local.h"

// unit test for local search for executable
static bool test_searchcwd() {
  bool pass = true;

  long size = pathconf(".", _PC_PATH_MAX);
  char *buff = (char *)malloc((size_t)size);

  pass &= !!searchcwd("runtest", buff, 1024);
  pass &= !searchcwd("dsfasdfasdfasf", buff, 1024);

  free(buff);

  return pass;
}

// unit test for bin search for executable
static bool test_searchbins() {
  bool pass = true;

  char buff[1024];

  pass &= (0 == strcmp("/bin/ls",searchbins("ls", buff, 1024)));
  pass &= !searchbins("dsfasdfasdfasf", buff, 1024);

  return pass;
}

// run all unit tests in this file
bool runtests_local() {
  bool pass = true;
  pass &= runtest(test_searchcwd, "searchcwd");
  pass &= runtest(test_searchbins, "searchbins");
  return pass;
}
