#ifndef GET_NUM_H
#define GET_NUM_H

#define GN_NONNEG   01   //value >= 0
#define GN_GT_0     02   //value > 0

#define GN_ANY_BASE 0100   //value is any base
#define GN_BASE_8   0200    //value is expressed in octal
#define GN_BASE_16  0400    //value is expressed in hexadecial

int getInt(const char *arg, int flags, const char *name);
long getLong(const char *arg, int flags, const char *name);

#endif
