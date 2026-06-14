CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = queue.o main.o

all: jobqueue

jobqueue: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c queue.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f jobqueue $(OBJS)

.PHONY: all clean
