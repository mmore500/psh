#include "qotd.h"

FILE *open_qotd() {

  FILE *fp = NULL;

  char *hPath = getenv("HOME");

  // +1 for concatenating slash
  int nChar = strlen(hPath) + strlen(QOTD_FILENAME) + 1;

  char fullPath[MAX_QOTD_PATH_LEN];

  // if the path to the qotd file will fit in the buffer
  if(nChar < MAX_QOTD_PATH_LEN) {
    // ensure that string starts empty
    fullPath[0] = '\0';

    // concatenate the path
    strcat(fullPath, hPath);
    strcat(fullPath, "/");
    strcat(fullPath, QOTD_FILENAME);

    fp = fopen(fullPath, "r");
  }

  return fp;

}

/*
 * Print the quote of the day from the user's home directory.
 * @arg silent 0 for verbose behavior, silent otherwise
 * @return 0 on success and 1 on failure
 */
int print_qotd(int silent) {
  FILE *fp = open_qotd();

  if (fp) {
    char c;
    for(c = '\0'; c != EOF ; c = getc(fp)) {
      if (!silent) putchar(c);
    }
    if (!silent) putchar('\n');
    fclose(fp);

    return 0;
  } else {
    if (!silent) printf("No quote of the day for today!\n");
    return 1;
  }

}
