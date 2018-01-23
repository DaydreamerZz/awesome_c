#ifndef __SDS_H
#define __SDS_H

/*
 * 最大预分配长度
 */
#define SDS_MAX_PREALLOC (1024*1024)

#include <sys/types.h>
#include <stdarg.h>

/*
 * 类型别名，用于指向 sdshdr 的 buf 属性
 */
typedef char *sds;

/*
 * 保存字符串对象的结构
 */
struct sdshdr {
    
    // buf 中已占用空间的长度
    int len;

    // buf 中剩余可用空间的长度
    int free;

    // 数据空间
    char buf[];
};

/*
 * 返回 sds 实际保存的字符串的长度
 *
 * T = O(1)
 */
static inline size_t sdslen(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->len;
}

/*
 * 返回 sds 可用空间的长度
 *
 * T = O(1)
 */
static inline size_t sdsavail(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->free;
}

static inline size_t sdsAllocSize(sds s) {
    struct sdshdr *sh = (void*) (s-(sizeof(struct sdshdr)));
    return sizeof(*sh) + sh->len + sh->free + 1;
}

size_t sdslen(const sds s);
size_t sdsavail(const sds s);


sds sdsnewlen(const void *init, size_t initlen);
sds sdsnew(const char *init);

sds sdsempty(void);
sds sdsdup(const sds s);
void sdsfree(sds s);
void sdsclear(sds s);
void sdsdisplqy(sds s);


sds sdsMakeRoomFor(sds s, size_t addlen);
sds sdsgrowzero(sds s, size_t len);

sds sdscatlen(sds s, const void *t, size_t len);
sds sdscat(sds s, const char *t);
sds sdscatsds(sds s, const sds t);

sds sdscpylen(sds s, const char *t, size_t len);
sds sdscpy(sds s, const char *t);

sds sdstrim(sds s, const char *cset);
void sdsrange(sds s, int start, int end);

int sdscmp(const sds s1, const sds s2);

void sdstolower(sds s);
void sdstoupper(sds s);


sds sdscatvprintf(sds s, const char *fmt, va_list ap);
sds sdscatprintf(sds s, const char *fmt, ...);
sds sdscatfmt(sds s, char const *fmt, ...);
/*


void sdsupdatelen(sds s);

sds *sdssplitlen(const char *s, int len, const char *sep, int seplen, int *count);
void sdsfreesplitres(sds *tokens, int count);

sds sdsfromlonglong(long long value);
sds sdscatrepr(sds s, const char *p, size_t len);
sds *sdssplitargs(const char *line, int *argc);
sds sdsmapchars(sds s, const char *from, const char *to, size_t setlen);
sds sdsjoin(char **argv, int argc, char *sep);

*//* Low level functions exposed to the user API *//*

void sdsIncrLen(sds s, int incr);
sds sdsRemoveFreeSpace(sds s);
size_t sdsAllocSize(sds s);*/

#endif
