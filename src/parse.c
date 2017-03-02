#include "parse.h"

/**
 * Creates an empty argbox struct that is ready to store words.
 * @param count the number of words the argbox should store
 * @return the newly created argbox
 */
argbox *create_argbox(int count) {
  argbox *a = malloc(sizeof(argbox));
  if(a) {
    a->count = count;
    a->words = malloc(sizeof(char *) * count);
  }
  return a;

}

/**
 * Puts an argument in the argbox
 * @param a the argbox to set the argument in
 * @param which the index of the argument to set
 * @param arg the string to put in the argbox
 * @return 0 on success, 1 on failure
 */
int setarg(argbox *a, int which, char *arg) {
  if (which < 0 || which >= a->count) {
    return 1;
  } else {
    *(a->words + which) = arg;
    return 0;
  }
}

/**
 * Tokenize a whitespace separated string and return resulting words as
 * an array of strings.
 * @param raw whitespace-separted string to be processed
 * @return array of strings consisting of whitespace-tokenized words
 */
argbox *parse(char *raw) {

  // input is whtie space separated
  const char *delim = " \t\n";

  char *temp = strdup(raw);

  char *sptr;

  // count the number of words resulting from tokenization
  int count = 0;
  for(sptr = strtok(temp, delim); sptr; sptr = strtok(NULL, delim)) {
    count ++;
  }

  // make a fresh copy of the string
  free(temp);
  temp = strdup(raw);

  // make an argbox to hold the words resulting from tokenization
  argbox *abox = create_argbox(count);

  // fill the argbox
  int i;
  for(sptr = strtok(temp, delim), i = 0; sptr; sptr = strtok(NULL, delim), i++) {
    abox->words[i] = strdup(sptr);
  }

  free(temp);

  return abox;
}

/**
 * Frees the resources associated with an argbox struct.
 * @param a a pointer to the argbox to be destroyed
 */
void destroy_argbox(argbox *a) {
  // free all strings stored in the argbox
  int i;
  for( i=0; i < a->count; i ++) {
    free(*(a->words + i));
  }
  // free the argbox itself
  free(a);
}

/**
 * Retrieves an argument word from an argbox
 * @param a the argbox to retrieve the argument from
 * @param which the index of the argument to retrieve
 * @return the retrieved argument string or NULL for an invalid argument request
 */
char *getarg(argbox *a, int which) {
  if (which < 0 || which >= a->count) {
    return NULL;
  } else {
    return *(a->words + which);
  }
}
