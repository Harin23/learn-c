CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = hashmap.o main.o

all: hashmap_demo

hashmap_demo: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c hashmap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f hashmap_demo $(OBJS)

.PHONY: all clean
