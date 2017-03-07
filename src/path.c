#include "path.h"

/*
 * Attepts to execute an executable file at the given path
 * @param path the path to the executable file as a string
 * @param wantwait if true, will wait on execution of executable
 * @param silent silences printed alert of invalid command in no wait mode
 * @return 0 on success, 1 on invalid command failure, -1 on other failure
 */
int exec_path(char *path, char **args, bool wantwait, bool silent) {
  pid_t fork_val = fork();

  // if we don't want to wait, use double forking to prevent zombie processes
  // fork a grandchild and then remove the original child
  if (!wantwait && !fork_val) {
    // if original child in double forked process, exit immediately
    if(fork()) {
      exit(0);
    }
  }

  // when using double forking, original parent needs to wait on original child
  if (!wantwait && fork_val) {
    waitpid(fork_val, NULL, 0);
  }

  // res will be set to 1 if an invalid command was used in wait mode
  int res = 0;
  if (fork_val > 0 && wantwait){
    // if parent process and we want to wait on child
    int exitcode = 0;
    waitpid(fork_val, &exitcode, 0);
    // C's system call multiplies by exit codes by 256
    if (exitcode == COMMAND_NOT_FOUND * 256) res = 1;
  } else if (fork_val == 0) {
    // if child`process
    // attempt to run executable
    execv(path, args);
    // if still executing, something went wrong
    // if we're not waiting, still print to let the user know
    // they entered an invalid command
    if (!wantwait && !silent) printf("psh: invalid command\n");
    // exit with code "command not found"
    exit(COMMAND_NOT_FOUND);
  } else if (fork_val < 0) {
    // if problem forking (fork_val < 0)
    res = -1;
  }
  return res;
}
