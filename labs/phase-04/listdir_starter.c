/*
 * Lab 4.1 — Directory listing starter
 * Usage: ./listdir path
 */
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s dir\n", argv[0]);
		return 1;
	}

	DIR *dir = opendir(argv[1]);

	if (!dir) {
		perror("opendir");
		return 1;
	}

	struct dirent *ent;

	while ((ent = readdir(dir)) != NULL) {
		if (ent->d_name[0] == '.')
			continue;

		/* TODO: stat each entry, print name and size */
		printf("%s\n", ent->d_name);
	}

	closedir(dir);
	return 0;
}
