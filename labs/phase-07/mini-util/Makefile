CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

BINS = mu-wc mu-cat

all: $(BINS)

mu-wc: src/mu_wc.c include/common.h
	$(CC) $(CFLAGS) -o $@ src/mu_wc.c

mu-cat: src/mu_cat.c include/common.h
	$(CC) $(CFLAGS) -o $@ src/mu_cat.c

test:
	./tests/run_tests.sh

clean:
	rm -f $(BINS)

.PHONY: all test clean
