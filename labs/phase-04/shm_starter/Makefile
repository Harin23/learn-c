CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDLIBS = -pthread -lrt

all: shm_demo

shm_demo: main.c
	$(CC) $(CFLAGS) -o $@ main.c $(LDLIBS)

clean:
	rm -f shm_demo

.PHONY: all clean
