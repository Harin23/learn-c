CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = stack.o main.o

all: rpn

rpn: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f rpn $(OBJS)

.PHONY: all clean
