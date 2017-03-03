/**
 *
 *
 * Author: Matthew
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "builtin.h"
#include "local.h"
#include "path.h"
#include "qotd.h"

#define MAX_INPUT_LEN 256

char buffer[HISTORY_LEN+1][MAX_INPUT_LEN];
char *strarray[HISTORY_LEN+1];

int main(int argc, char *argv[]) {

  // welcome user to shell
  printf("Welcome to the Puget Sound Shell!\n");

  // print qotd file if it's present
  // argument 0 makes it verbose
  print_qotd(0);

  // initialize all history buffer to empty strings
  // initialize an array of char pointers to point in there
  int j;
  for(j = 0; j < HISTORY_LEN + 1; j ++) {
    buffer[j][0] = '\0';
    strarray[j] = &buffer[j][0];
  }

  // buffer for path
  long pbsize = pathconf(".", _PC_PATH_MAX);
  char *pathbuff = (char *)malloc((size_t)pbsize);


  int cur_hist;
  for(cur_hist = 0; true; cur_hist = (cur_hist + 1) % (HISTORY_LEN+1)) {

    // get string data from user
    printf("psh> ");

    fgets(buffer[cur_hist], MAX_INPUT_LEN, stdin);

    argbox *a = parse(buffer[cur_hist]);

    // if no arguments then just show prompt again
    if (a->count == 0) continue;

    // look for trailing & on commands
    bool wait = true;
    if (!strcmp((a->words)[a->count-1],"&")) {
      wait = false;
      // remove & from args once it is parsed
      (a->words)[a->count-1] = NULL;
      a->count --;
    }

    // see if it can be handled as a builtin
    if (handle_builtin(a, (char **)strarray, cur_hist, false)) continue;

    // path to exebutable to try
    char *res = NULL;

    // if prepended by a / try to execute raw
    if ((a->words[0])[0] == '/') res = a->words[0];
    // try to look in current directory
    else if ((res = searchcwd(a->words[0], pathbuff, pbsize)))
    ;
    // try to look in bins on user's path
    else if ((res = searchbins(a->words[0], pathbuff, pbsize)))
    ;

    // attempt to execute path
    if(exec_path(res, a->words, wait, false)) {
      printf("psh: invalid command\n");
    }

    // deallocate resources
    destroy_argbox(a);

  }

  // deallocate resources
  free(pathbuff);

  printf("goodbye\n" );
}
