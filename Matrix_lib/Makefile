CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c99 -pedantic
#-g
LIB=../lib/*.c
GIVEN1=matrix.c


MATRIX:
	$(CC) $(CFLAGS) -DDEBUG $(LIB) $(GIVEN1) main.c \
	     -o test
