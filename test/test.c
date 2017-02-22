/*
 * test.c
 *
 *  Created on: Jan 7, 2017
 *      Author: Matthew Moreno
 */

#include <stdbool.h>
#include <stdio.h>

#include "test_builtin.h"
#include "test_local.h"
#include "test_path.h"
#include "test_qotd.h"
/*
 * Run all registered unit tests, print results
 */
int main()
{
  bool pass = true;
  pass &= runtests_builtin();
  pass &= runtests_local();
  pass &= runtests_path();
  pass &= runtests_qotd();
  printf("----------------------------\n");
  printf("Test battery status: %s.\n", pass ? "PASSED" : "FAILED");

  return 0;
}
