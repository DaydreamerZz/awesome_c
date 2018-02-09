#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "../lib/mostuse_hd.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif
/*
gcc tee.c ../lib/error_functions.c

get data from stdin and output data to the file
tee output
tee -a output   //appent end of the file
*/
int main(int argc, char const *argv[]) {
    size_t len; //data length
    int infd, outfd, index;
    Boolean isappend = FALSE;
    ssize_t numRead, numWritren;

    if(argc < 2 || (strcmp(argv[1], "--help")==0))
        usageErr("%s [-a(append)] outfile\n", argv[0]);

    infd = open("/dev/tty", O_RDONLY);
    if(infd == -1)
        errExit("open infd");

    // for(index = 1; index < argc; index++){
    //     if(argv[index][0] == '-') {
    //         printf("-a option\n");
    //         isappend = TRUE;
    //     }else{
    //         printf("not -a option\n");
    //         outfd = open(argv[index], O_RDWR | O_CREAT);
    //     }
    // }
    if(argv[1][0] == '-'){
        isappend = TRUE;
        outfd = open(argv[2], O_RDWR | O_CREAT);
    }else{
        outfd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC);
    }

    if(isappend){
        lseek(outfd, 0, SEEK_END);
    }else{
        lseek(outfd, 0, SEEK_SET);
    }

    char *buf;
    buf = malloc(BUF_SIZE);
    if(buf == NULL)
        errExit("malloc");

    while((numRead = read(infd, buf, BUF_SIZE))){
        numWritren = write(outfd, buf, numRead);
        if(numWritren != numRead){
            printf("can not write whole buf\n");
        }
    }

    if(close(infd) == -1)
        errExit("close infd");
    if(close(outfd) == -1)
        errExit("close outfd");
    return 0;
}
