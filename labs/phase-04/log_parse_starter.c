/*
 * Lab 4.1 — Parse one log line
 */
#include <stdio.h>
#include <string.h>

int parse_log_line(const char *line, char *host_out, size_t host_len,
		   int *status_out, long *size_out)
{
	/* TODO: parse simplified combined log format */
	(void)line;
	(void)host_out;
	(void)host_len;
	(void)status_out;
	(void)size_out;
	return -1;
}

int main(void)
{
	const char *line =
		"127.0.0.1 - alice [10/Oct/2025:13:55:36 +0000] "
		"\"GET /index.html HTTP/1.1\" 200 2326";
	char host[64];
	int status;
	long size;

	if (parse_log_line(line, host, sizeof(host), &status, &size) == 0)
		printf("host=%s status=%d size=%ld\n", host, status, size);
	else
		puts("parse failed");

	return 0;
}
