#ifndef LOCAL_H
#define LOCAL_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char *searchcwd(char *command, char *buffer, int buffsize);

char *searchbins(char *command, char *buffer, int buffsize);

#endif
