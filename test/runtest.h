#ifndef RUNTEST_H
#define RUNTEST_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool runtest(bool (*funptr)(), const char *name);

#endif
