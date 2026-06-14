CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRCS = main.c gradebook.c io.c
OBJS = $(SRCS:.c=.o)

all: gradebook

gradebook: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

debug: CFLAGS += -O0
debug: gradebook

%.o: %.c gradebook.h io.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f gradebook $(OBJS)

.PHONY: all debug clean
