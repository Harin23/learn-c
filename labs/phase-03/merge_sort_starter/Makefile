CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = sort.o main.o

all: sort_demo

sort_demo: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c sort.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f sort_demo $(OBJS)

.PHONY: all clean
