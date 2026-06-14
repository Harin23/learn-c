CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

all: leaky

leaky: leaky.c
	$(CC) $(CFLAGS) -o leaky leaky.c

clean:
	rm -f leaky

.PHONY: all clean
