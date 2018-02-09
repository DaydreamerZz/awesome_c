#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "get_num.h"

static void getFail(const char *fname, const char *msg, const char *arg, const char *name)
{
    fprintf(stderr, "%s error", fname);
    if(name != NULL)
        fprintf(stderr, "(in %s)", name);
    fprintf(stderr, ": %s\n", msg);
    if(arg != NULL && *arg != '\0')
        fprintf(stderr, "    offending text: %s\n", arg);

    exit(EXIT_FAILURE);
}

static long getNum(const char *fname, const char *arg, int flags, const char *name)
{
    long res;
    char *endptr;
    int base;
    if(arg == NULL || *arg == '\0')
        getFail(fname, "null or empty string", arg, name);

    base = (flags & GN_ANY_BASE) ? 0 : (flags & GN_BASE_8) ? 8 : (flags & GN_BASE_16) ? 16 : 10;

    errno = 0;
    res = strtol(arg, &endptr, base); //endptr is a point behind value, e.g 111 abc, so endptr point to abc
    if(errno != 0)
        getFail(fname, "strtol() failed", arg, name);

    if(*endptr != '\0')
        getFail(fname, "nonnumeric characters", arg, name);
    if((flags & GN_NONNEG) && res < 0)
        getFail(fname, "negative value not allowed", arg, name);
    if((flags & GN_GT_0) && res <= 0)
        getFail(fname, "value must be > 0", arg, name);

    return res;
}

long getLong(const char *arg, int flags, const char *name)
{
    return getNum("getLong", arg, flags, name);
}

int getInt(const char *arg, int flags, const char *name)
{
    long res;
    res = getNum("getInt", arg, flags, name);
    if(res > INT_MAX || res < INT_MIN)
        getFail("getInt", "Integer out of range", arg, name);
    return (int)res;
}
