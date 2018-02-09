#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/mostuse_hd.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[])
{
    int infd, outfd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if(argc != 3 || strcmp(argv[1], "--help")==0 )
        usageErr("%s old-file new-file\n", argv[0]);

    infd = open(argv[1], O_RDONLY);
    if(infd == -1)
        errExit("opening file %s", argv[1]);

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR;
    outfd = open(argv[2], openFlags, filePerms);
    if(outfd == -1)
        errExit("opening file %s", argv[2]);

    while((numRead = read(infd, buf, BUF_SIZE)) > 0){
        if(write(outfd, buf, numRead) != numRead)
            fatal("could not write whole buffer");
    }

    if(numRead == -1)
        errExit("read");
    if(close(infd))
        errExit("close input");
    if(close(outfd))
        errExit("close output");
    exit(EXIT_SUCCESS);
}
