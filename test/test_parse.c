#include "test_parse.h"

// unit test for parse function
static bool test_parse() {
  bool pass = true;

  const int count = 4;
  const char *words[count] = {"boop", "beep", "meep", "to"};
  char *rawwords = "boop beep  meep\t to";

  argbox *a = parse(rawwords);

  int i;
  // check args
  for(i = 0; i < count; i ++) {
    pass &= (0 == strcmp(getarg(a, i), words[i]));
  }

  destroy_argbox(a);

  return pass;
}

// run all unit tests in this file
bool runtests_parse() {
  bool pass = true;

  pass &= runtest(test_parse, "parse");
  return pass;
}
