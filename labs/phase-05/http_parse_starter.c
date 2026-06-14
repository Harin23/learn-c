/*
 * Lab 5.5 — Parse minimal HTTP GET request
 */
#include <stdio.h>
#include <string.h>

int parse_http_request(const char *buf, char *path_out, size_t path_len)
{
	/* TODO: parse "GET /path HTTP/1.x" from first line */
	(void)buf;
	(void)path_out;
	(void)path_len;
	return -1;
}

int main(void)
{
	const char *req =
		"GET /index.html HTTP/1.1\r\n"
		"Host: localhost\r\n"
		"\r\n";
	char path[256];

	if (parse_http_request(req, path, sizeof(path)) == 0)
		printf("path=%s\n", path);
	else
		puts("parse failed");

	return 0;
}
