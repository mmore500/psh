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
  return false;
}

/*
 * Search the current working directory for an executable.
 * @param command the name of the executable to search for
 * @param buffer on success the full path to the executable will be placed here
 * @param buffsize the length of the buffer
 * @return on success a pointer to the buffer, on failure NULL
 */
char *searchcwd(char *command, char *buffer, int buffsize) {
  return NULL;
}

/*
 * Search the user's bins for an executable.
 * @param command the name of the executable to search for
 * @param buffer on success the full path to the executable will be placed here
 * @param buffsize the length of the buffer
 * @return on success a pointer to the buffer, on failure NULL
 */
char *searchbins(char *command, char *buffer, int buffsize) {
  return NULL;
}
