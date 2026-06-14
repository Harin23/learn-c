CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = list.o main.o

all: list_demo

list_demo: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c list.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f list_demo $(OBJS)

.PHONY: all clean
