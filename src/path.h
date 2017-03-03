#ifndef PATH_H
#define PATH_H

#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define COMMAND_NOT_FOUND 127

int exec_path(char *path, char **args, bool wantwait, bool silent);

#endif
