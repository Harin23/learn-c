/*
 * Lab 4.4 — POSIX shared memory starter
 * Compile: gcc -Wall -Wextra -std=c11 -pthread -o shm_demo main.c
 * Link: -lrt -pthread (if needed)
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/learn_c_shm_demo"

typedef struct {
	int counter;
} ShmData;

int main(void)
{
	int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0600);

	if (fd < 0) {
		perror("shm_open");
		return 1;
	}

	if (ftruncate(fd, sizeof(ShmData)) != 0) {
		perror("ftruncate");
		return 1;
	}

	ShmData *data = mmap(NULL, sizeof(*data), PROT_READ | PROT_WRITE,
			     MAP_SHARED, fd, 0);

	if (data == MAP_FAILED) {
		perror("mmap");
		return 1;
	}

	/* TODO: increment counter, print, demonstrate second process or fork */
	data->counter++;
	printf("counter=%d\n", data->counter);

	munmap(data, sizeof(*data));
	close(fd);
	shm_unlink(SHM_NAME);
	return 0;
}
