#include "test_qotd.h"

// unit test
static bool test_print_qotd() {
  int pass = true;

  char *hPath = getenv("HOME");

  // +1 for concatenating slash
  int nChar = strlen(hPath) + strlen(QOTD_FILENAME) + 1;
  char *fullPath = malloc(sizeof(char) * nChar);
  // ensure that string starts empty
  fullPath[0] = '\0';

  // concatenate the path
  strcat(fullPath, hPath);
  strcat(fullPath, "/");
  strcat(fullPath, QOTD_FILENAME);

  if (fopen(fullPath, "r")) {
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
