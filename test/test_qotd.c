#include "test_qotd.h"

// unit test
static bool test_print_qotd() {
  int pass = true;

  if (open_qotd()) {
    // if qotd file exists
    pass &= (0 == print_qotd(1));
  } else {
    // if qotd file doesn't exist
    pass &= (1 == print_qotd(1));
  }

  return pass;
}

// run all unit tests in this file
bool runtests_qotd() {
  bool pass = true;
  pass &= runtest(test_print_qotd, "print quote of the day");
  return pass;
}
