/*
 * Lab 5.5 — TCP echo client
 * Usage: ./echo_client 127.0.0.1 9000 "hello"
 */
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 4) {
		fprintf(stderr, "Usage: %s host port message\n", argv[0]);
		return 1;
	}

	int fd = socket(AF_INET, SOCK_STREAM, 0);

	if (fd < 0) {
		perror("socket");
		return 1;
	}

	struct sockaddr_in addr = { 0 };

	addr.sin_family = AF_INET;
	addr.sin_port = htons((uint16_t)atoi(argv[2]));

	if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
		fprintf(stderr, "invalid address\n");
		return 1;
	}

	if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("connect");
		return 1;
	}

	write(fd, argv[3], strlen(argv[3]));

	char buf[256];
	ssize_t n = read(fd, buf, sizeof(buf) - 1);

	if (n > 0) {
		buf[n] = '\0';
		printf("echo: %s\n", buf);
	}

	close(fd);
	return 0;
}
