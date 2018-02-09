#ifndef MOSTUSE_HD_H
#define MOSTUSE_HD_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "get_num.h" //get number by parse input

#include "error_functions.h"

typedef enum {FALSE, TRUE} Boolean;

#define max(x, y) ((x) < (y) ? (y) : (x))
#define min(x, y) ((x) < (y) ? (x) : (y))

#endif
