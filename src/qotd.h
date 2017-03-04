#ifndef QOTD_H
#define QOTD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QOTD_FILENAME ".psh_motd"
#define MAX_QOTD_PATH_LEN 1024

int print_qotd(int silent);

FILE *open_qotd();

#endif
