#include "local.h"

/*
 * Search a directory for an executable.
 * @param command the name of the executable to search for
 * @param dir the full path of the directory to search
 * @param buffer on success the full path to the executable will be placed here
 * @param buffsize the length of the buffer
 * @return on success a pointer to the buffer, on failure NULL
 */
char *dir_contains(char *command, char *dir, char *buffer, int buffsize) {
  // +1 for concatenating slash
  int nChar = strlen(dir) + strlen(command) + 1;
  // if not enough room in the buffer, return NULL
  if (buffsize - 1 < nChar) return NULL;

  // ensure that buffer starts empty
  buffer[0] = '\0';
  // concatenate the path
  strcat(buffer, dir);
  strcat(buffer, "/");
  strcat(buffer, command);

  // test if there is an executable at the address
  struct stat sb;
  bool res = (stat(buffer, &sb) == 0 && sb.st_mode & S_IXUSR);

  return res ? buffer : NULL;
}

/*
 * Search the current working directory for an executable.
 * @param command the name of the executable to search for
 * @param buffer on success the full path to the executable will be placed here
 * @param buffsize the length of the buffer
 * @return on success a pointer to the buffer, on failure NULL
 */
char *searchcwd(char *command, char *buffer, int buffsize) {
  long size = pathconf(".", _PC_PATH_MAX);
  char *cwd = (char *)malloc((size_t)size);

  // if buffer for current working directory and successful call to getcwd
  // then seawrch directory for executable, otherwise return NULL
  char *ret = cwd && getcwd(cwd, size) ? dir_contains(command, cwd, buffer, buffsize) : NULL;

  free(cwd);

  return ret;
}

/*
 * Search the user's bins for an executable.
 * @param command the name of the executable to search for
 * @param buffer on success the full path to the executable will be placed here
 * @param buffsize the length of the buffer
 * @return on success a pointer to the buffer, on failure NULL
 */
char *searchbins(char *command, char *buffer, int buffsize) {

  char *bins = getenv("PATH");

  char *sptr = strdup(bins);
  for(sptr = strtok(sptr, ":"); sptr; sptr = strtok(NULL, ":")) {
    char *res = dir_contains(command, sptr, buffer, buffsize);
    if (res) return res;
  }

  free(sptr);

  return NULL;
}
