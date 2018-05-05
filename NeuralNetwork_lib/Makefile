CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c99 -pedantic
#-g
LIB=../lib/*.c ../Matrix_lib/*.c
GIVEN1=neural.c


NEURAL:
	$(CC) $(CFLAGS) -DDEBUG $(LIB) $(GIVEN1) main.c \
		-o test