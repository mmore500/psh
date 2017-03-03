#include "builtin.h"

/*
 * Print a friendly goodbye message and exit.
 */
void builtin_exit() {
  printf("bye!\n");
  exit(0);
}

/*
 * Takes an argbox and attempts to handle it using builtin commands.
 * @param a the argbox containing user-provided arguments
 * @param history array strings with last HISTORY_LEN commands
 * @param silent if true, suppress printing to stdout
 * @return true if the argbox was handled by builtins, false otherwise
 */
bool handle_builtin(argbox *a, char **history, bool silent) {
  char *commandname = *(a->words);
  if(!strcmp(commandname, "exit")) builtin_exit();
  else if(!strcmp(commandname, "pwd")) builtin_pwd(silent);
  else if(!strcmp(commandname, "cd")) builtin_cd(a->count > 1 ? *(a->words + 1) : NULL, silent);
  else if(!strcmp(commandname, "history")) builtin_history(history, silent);
  // if an option wasn't recognized
  else return false;

  // if an option was recognized
  return true;
}

/*
 * Print the current working directory.
 * @param silent if true, suppress printing to stdout
 */
void builtin_pwd(bool silent) {
  long size = pathconf(".", _PC_PATH_MAX);
  char *cwd = (char *)malloc((size_t)size);

  // if buffer for current working directory and successful call to getcwd
  // then seawrch directory for executable, otherwise return NULL
  if (cwd && getcwd(cwd, size)) {
    if (!silent) printf("cur directory: %s\n", cwd);
  }

  free(cwd);

}

/*
 * Change directory.
 * @param path the desired destination directory as a string
 * @param silent if true, suppress printing to stdout
 * @return 0 on success, 1 on failure
 */
int builtin_cd(char *path, bool silent) {
  int res = path ? chdir(path) : 1;
  if (res && !silent) printf("cd failed\n");
  builtin_pwd(silent);
  return res;
}

/*
 * Print last HISTORY_LEN user commands
 * @param history array strings with last HISTORY_LEN commands
 * @param silent if true, suppress printing to stdout
 */
void builtin_history(char **history, bool silent) {
  int i;
  for (i = 0; i < HISTORY_LEN; i++) {
    char *line = history[i];
    if (!silent) printf("%s\n", line);
  }
}
