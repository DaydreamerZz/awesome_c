#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *sds;

/*
 * 保存字符串对象的结构
 */
struct sdshdr {
    int len;
    int free;
    char buf[];
};


//static int sdslen(const sds s) {
//    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
//    return sh->len;
//}

int main() {
    printf("Hello, World!\n");

    printf("%d\n", sizeof(struct sdshdr));

    struct sdshdr *tmp = malloc(sizeof(struct sdshdr)+20);
    tmp->len = 3;
    tmp->free = 10;
//    tmp->buf = malloc(20);
    strcpy(tmp->buf, "ab");

    printf("%d %d %s\n", tmp->len, tmp->free, tmp->buf);

    sds the_buf = tmp->buf;
    int res = sdslen(the_buf);
    printf("%d\n", res);
    return 0;
}