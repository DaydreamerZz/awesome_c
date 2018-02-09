#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "../lib/mostuse_hd.h"

/*
gcc fileio_practice.c ../lib/get_num.c ../lib/error_functions.c
*/

/*
5.2 O_APPEND opean a file，把偏移量置于文件开始再写入
5.5 验证文件描述符和其副本是否共享文件偏移量
*/

void function5_2()
{
    printf("in function5_2\n");
    int fd = open("bak", O_RDWR | O_APPEND);
    lseek(fd, 0, SEEK_SET);
    if(fd == -1)
        errExit("open");
    char buf[10] = "abcdedg";
    int writeNum = write(fd, buf, strlen(buf));
    if(writeNum == -1)
        errExit("write");
    if(close(fd) == -1)
        errExit("close");
}
void function5_5()
{
    int oldfd, newfd;
    oldfd = open("bak", O_RDWR);
    if(oldfd == -1)
        errExit("open oldfd");
    newfd = dup(oldfd);
    if(newfd == -1)
        errExit("dup");
    lseek(oldfd, 0, SEEK_SET);
    char buf1[10] = "hello new";
    char buf2[10] = "hello old";
    int writeNum = write(newfd, buf1, strlen(buf1));
    lseek(newfd, 10, SEEK_CUR);
    writeNum = write(oldfd, buf2, strlen(buf2));
}

void function5_6()
{
    int fd1, fd2, fd3;
    //fd1 = open("bak", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    //fd2 = dup(fd1);
    fd3 = open("bak", O_RDWR);
    //write(fd1, "Hello,", 6);
    //write(fd2, "World,", 6);
    //lseek(fd2, 0, SEEK_SET);
    //write(fd1, "hello,", 6);
    write(fd3, "hello,", 6);
}
int main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd, index, j;
    ssize_t numRead, numWritren;

    if((strcmp(argv[1], "--help")==0))
        usageErr("%s file s<length> {r<length>|R<length>|w<string>}\n", argv[0]);
    switch (argv[1][0]) {
        case '2':
            function5_2();
            break;
        case '5':
            function5_5();
            break;
        case '6':
            function5_6();
            break;
    }

    return 0;

}
