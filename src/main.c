/**
 *
 *
 * Author: Matthew
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "builtin.h"
#include "local.h"
#include "path.h"
#include "qotd.h"

#define MAX_INPUT_LEN 256

char buffer[MAX_INPUT_LEN];


int main(int argc, char *argv[]) {

  // welcome user to shell
  printf("Welcome to the Puget Sound Shell!\n");

  // print qotd file if it's present
  // argument 0 makes it verbose
  print_qotd(0);

  while(true) {
    // get string data from user
    printf("psh>");

    // clear input buffer
    fseek(stdin,0,SEEK_END);

    fgets(buffer, MAX_INPUT_LEN, stdin);

    //TODO check if & is last argument

    //TODO look for / prepended commands

    //TODO look in the user PATH

    // invalid command
    printf("error: invalid command\n");

    }

  printf("goodbye\n" );
}
