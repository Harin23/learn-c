#include <stdio.h>
#include <unistd.h>

int main(void)
{
	long ps = sysconf(_SC_PAGESIZE);

	printf("page size: %ld bytes\n", ps);
	return 0;
}
