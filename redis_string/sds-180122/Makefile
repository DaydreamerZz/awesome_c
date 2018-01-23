.PHONY: clean


CFLAGS  := -Wall -g
LD      := gcc
LDLIBS  := ${LDLIBS} -lpthread

APPS    := sds

all: ${APPS}


sds-test: sds.o zmalloc.o
	${LD} -o $@ $^ ${LDLIBS}



clean:
	rm -f *.o ${APPS}
