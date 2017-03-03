#ifndef BUILTIN_H
#define BUILTIN_H

#define HISTORY_LEN 100

#include <stdbool.h>
#include <unistd.h>
#include "parse.h"

bool handle_builtin(argbox *a, char **history, bool silent);

void builtin_pwd(bool silent);

int builtin_cd(char *path, bool silent);

void builtin_history(char **history, bool silent);

#endif
