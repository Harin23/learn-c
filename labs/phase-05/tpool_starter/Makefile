CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDLIBS = -pthread

OBJS = tpool.o main.o

all: tpool_demo

tpool_demo: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c tpool.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f tpool_demo $(OBJS)

.PHONY: all clean
