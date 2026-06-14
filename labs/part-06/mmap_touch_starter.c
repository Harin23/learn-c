/*
 * Lab 6.2 — mmap and touch pages
 */
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void)
{
	size_t size = 1024 * 1024;
	char *p = mmap(NULL, size, PROT_READ | PROT_WRITE,
		       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (p == MAP_FAILED) {
		perror("mmap");
		return 1;
	}

	for (size_t i = 0; i < size; i += sysconf(_SC_PAGESIZE))
		p[i] = 1;

	printf("touched 1 MiB — check VmRSS in /proc/self/status\n");
	munmap(p, size);
	return 0;
}
