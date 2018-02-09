#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "../lib/mostuse_hd.h"

/*
gcc seek.c ../lib/get_num.c ../lib/error_functions.c
*/
int main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd, index, j;
    ssize_t numRead, numWritren;

    if(argc < 4 || (strcmp(argv[1], "--help")==0))
        usageErr("%s file s<length> {r<length>|R<length>|w<string>}\n", argv[0]);
    fd = open(argv[1], O_RDWR | O_CREAT);
    if(fd == -1)
        errExit("open error");

    for(index = 2; index < argc; index++){
        switch (argv[index][0]) {
            case 's':
                offset = getLong(&argv[index][1], GN_ANY_BASE, argv[index]);
                if(lseek(fd, offset, SEEK_SET) == -1)
                    errExit("lseek");
                printf("%s: seek succeeded\n", argv[index]);
                break;
            case 'w':
                numWritren = write(fd, &argv[index][1], strlen(&argv[index][1]));
                if(numWritren == -1)
                    errExit("write");
                printf("%s: wrote %d bytes\n", argv[index], (long)numWritren);
                break;
            case 'r':
            case 'R':
                len = getLong(&argv[index][1], GN_ANY_BASE, argv[index]);
                char *buf = malloc(len);
                if(buf == NULL)
                    errExit("malloc");
                numRead = read(fd, buf, len);
                if(numRead == -1)
                    errExit("read");
                if(numRead == 0)
                    printf("%s: end of the file\n", argv[index]);
                else{
                    printf("%s: \n", argv[index]);
                    for(j = 0; j < numRead; j++){
                        printf("%c\n", buf[j]);
                    }
                }

                break;
        }
    }
}
