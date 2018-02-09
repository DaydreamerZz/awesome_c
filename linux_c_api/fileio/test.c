#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd;
    fd = open("bak", O_RDONLY | O_CREAT, "644");
    if(fd == -1)
        printf("open error\n");
    return 0;
}
