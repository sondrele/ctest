
INCLUDEPATH=\
    -Iinclude\
    -I/usr/local/include
CC ?= cc
CFLAGS += -std=c99 ${INCLUDEPATH} -g
LDFLAGS += -L/usr/local/lib
SRCS = src/ctest.c test/test_ctest.c
OBJS = ${SRCS:.c=.o}
DEPS = ctest.h

%.o: %.c ${DEPS}
	${CC} ${CFLAGS} -c -o $@ $<

# Default
all: setup ctest

setup: bin obj
	@echo "SRCS = ${SRCS}"
	@echo "OBJS = ${OBJS}"

ctest: ${OBJS}
	${CC} -o bin/$@ $^ ${CFLAGS}
	mv src/*.o obj/
	mv test/*.o obj/

test: all
	bin/ctest

# Cleanup.
.PHONY: clean

clean:
	if [ -e obj ]; then rm -r obj; fi

purge: clean
	if [ -e bin ]; then rm -r bin; fi

# Targets to create directories (when they don't exist already).
bin:
	mkdir bin
obj:
	mkdir obj