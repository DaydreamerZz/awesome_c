#include <pwd.h>
#include <grp.h>
#include <ctype.h>
#include "../lib/mostuse_hd.h"

/*
gcc ugid_functions.c ../lib/error_functions.c
*/
char *userNameFromId(uid_t uid)
{
    struct passwd *pwd;
    pwd = getpwuid(uid);
    return pwd == NULL ? NULL : pwd->pw_name;
}

uid_t userIdFromName(const char *name)
{
    struct passwd *pwd;
    uid_t u;
    char *endptr;
    if(name == NULL || *name == '\0')
        return -1;
    u = strtol(name, &endptr, 10);
    if(*endptr == '\0')
        return u;
    pwd = getpwnam(name);

    return pwd == NULL ? -1 : pwd->pw_uid;
}

char *groupNameFromId(gid_t gid)
{
    struct group *grp;
    grp = getgrgid(gid);
    return grp == NULL ? NULL : grp->gr_name;
}

gid_t groupIdFromName(const char *name)
{
    struct group *grp;
    gid_t g;
    char *endptr;
    if(name == NULL || *name == '\0')
        return -1;
    g = strtol(name, &endptr, 10);
    if(*endptr == '\0')
        return g;
    grp = getgrnam(name);
    return grp == NULL ? -1 : grp->gr_gid;
}

int main(int argc, char *argv[])
{
    char *buf;
    buf = malloc(20);
    if(buf == NULL)
        errExit("malloc");
    buf = userNameFromId(0);
    uid_t id = userIdFromName("lab4");
    printf("%s\n", buf);
    printf("%d\n", id);
    return 0;
}
