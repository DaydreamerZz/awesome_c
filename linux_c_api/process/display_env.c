#include <stdlib.h>
#include "../lib/mostuse_hd.h"
extern char **environ;
int main(int argc, char *argv[])
{
    char **ep;
    // for(ep = environ; *ep != NULL; ep++)
    //     puts(*ep);

    char *buf = malloc(200);
    buf = getenv("JAVA_HOME");
    puts(buf);
    return 0;
}
