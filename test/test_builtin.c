#include "test_builtin.h"

// unit test for builtin pwd
static bool test_builtin_pwd() {
  int pass = true;

  builtin_pwd(true);

  return pass;
}

// unit test for builtin cd
static bool test_builtin_cd() {
  int pass = true;

  builtin_cd("test", true);

  builtin_cd("..", true);

  return pass;
}

// unit test for builtin history
static bool test_builtin_history() {
  int pass = true;

  char *entry = "entry";
  char *history[HISTORY_LEN];
  int i;
  for(i = 0; i < HISTORY_LEN; i ++) {
    history[i] = entry;
  }

  builtin_history(history, true);

  return pass;
}

// unit test for handle builtin
static bool test_handle_builtin() {
  int pass = true;

  char *entry = "entry";
  char *history[HISTORY_LEN];
  int i;
  for(i = 0; i < HISTORY_LEN; i ++) {
    history[i] = entry;
  }

  argbox *a = parse("pwd");
  pass &= handle_builtin(a, history, true);
  destroy_argbox(a);

  a = parse("cd test");
  pass &= handle_builtin(a, history, true);
  destroy_argbox(a);

  a = parse("cd ..");
  pass &= handle_builtin(a, history, true);
  destroy_argbox(a);

  a = parse("history");
  pass &= handle_builtin(a, history, true);
  destroy_argbox(a);

  a = parse("ls");
  pass &= !handle_builtin(a, history, true);
  destroy_argbox(a);

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
