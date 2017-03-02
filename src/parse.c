#include "parse.h"

/**
 * Tokenize a whitespace separated string and return resulting words as
 * an array of strings.
 * @param raw whitespace-separted string to be processed (note: this is
 * destroyed during processing)
 * @return array of strings consisting of whitespace-tokenized words
 */
argbox *parse(char *raw) {

  // input is whtie space separated
  const char *delim = " \t\n";

  // count the number of words resulting from tokenization
  int count = 0;
  char *sptr;
  for(sptr = raw; sptr; sptr = strpbrk(sptr, delim)){
    count ++;
  }

  //TODO implement

  return NULL;

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
