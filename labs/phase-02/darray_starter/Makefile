CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = darray.o main.o

all: darray

darray: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c darray.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f darray $(OBJS)

.PHONY: all clean
