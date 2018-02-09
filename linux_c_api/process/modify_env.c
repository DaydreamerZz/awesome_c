#include <stdlib.h>
#include "../lib/mostuse_hd.h"

/*
gcc modify_env.c ../lib/error_functions.c
*/
extern char **environ;
int main(int argc, char *argv[])
{
    int j;
    char **ep;
    // for(ep = environ; *ep != NULL; ep++)
    //     puts(*ep);
    clearenv();

    for(j = 1; j < argc; j++)
        if(putenv(argv[j]) != 0)
            errExit("putenv");

    if(setenv("AAA", "CCC", 1) == -1)
        errExit("setenv");

    for(ep = environ; *ep != NULL; ep++)
        puts(*ep);
    return 0;
}
