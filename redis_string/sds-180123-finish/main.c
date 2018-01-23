#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sds.h"

int main() {

    sds x = sdsnew("foo");
    sdsdisplqy(x);
    int i = 0;
    for(; i < 10; i++){
        x = sdscat(x, "Hello world");
        sdsdisplqy(x);
    }
    return 0;
}