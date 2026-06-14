CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = bst.o main.o

all: bst_demo

bst_demo: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c bst.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f bst_demo $(OBJS)

.PHONY: all clean
