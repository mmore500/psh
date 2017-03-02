#ifndef PARSE_H
#define PARSE_H

#include <string.h>
#include <stdlib.h>

typedef struct argbox {
  int count;
  char **words;
} argbox;

argbox *parse(char *raw);

void destroy_argbox(argbox *a);

argbox *create_argbox(int count);

#endif
