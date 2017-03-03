#include "builtin.h"

/*
 * Takes an argbox and attempts to handle it using builtin commands.
 * @param a the argbox containing user-provided arguments
 * @param history array strings with last HISTORY_LEN commands
 * @param silent if true, suppress printing to stdout
 * @return true if the argbox was handled by builtins, false otherwise
 */
bool handle_builtin(argbox *a, char **history, bool silent) {
  return false;
}

/*
 * Print a friendly goodbye message and exit.
 */
void builtin_exit() {

}

/*
 * Print the current working directory.
 * @param silent if true, suppress printing to stdout
 */
void builtin_pwd(bool silent) {

}

/*
 * Change directory.
 * @param path the desired destination directory as a string
 * @param silent if true, suppress printing to stdout
 * @return 0 on success, 1 on failure
 */
int builtin_cd(char *path, bool silent) {
  return 1;
}

/*
 * Print last HISTORY_LEN user commands
 * @param history array strings with last HISTORY_LEN commands
 * @param silent if true, suppress printing to stdout
 */
void builtin_history(char **history, bool silent) {

}
