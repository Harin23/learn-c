/*
 * Lab 6.4 / Project 37 — fstat tool starter
 * Usage: fstat path
 */
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s path\n", argv[0]);
		return 1;
	}

	struct stat st;

	if (lstat(argv[1], &st) != 0) {
		perror("lstat");
		return 1;
	}

	/* TODO: print inode, nlink, size, blksize, blocks, dev */
	printf("file: %s\n", argv[1]);
	printf("inode: %lu\n", (unsigned long)st.st_ino);

	return 0;
}
