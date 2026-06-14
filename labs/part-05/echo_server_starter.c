/*
 * Lab 5.5 — TCP echo server
 * Compile: gcc -Wall -Wextra -std=c11 -o echo_server echo_server_starter.c
 * Usage: ./echo_server 9000
 */
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s port\n", argv[0]);
		return 1;
	}

	int port = atoi(argv[1]);
	int srv = socket(AF_INET, SOCK_STREAM, 0);

	if (srv < 0) {
		perror("socket");
		return 1;
	}

	int opt = 1;

	setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	struct sockaddr_in addr = { 0 };

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons((uint16_t)port);

	if (bind(srv, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("bind");
		return 1;
	}

	if (listen(srv, 8) < 0) {
		perror("listen");
		return 1;
	}

	printf("listening on %d\n", port);

	/* TODO: accept loop, read/write echo, close client */
	for (;;) {
		int cli = accept(srv, NULL, NULL);

		if (cli < 0) {
			perror("accept");
			continue;
		}

		char buf[256];
		ssize_t n;

		while ((n = read(cli, buf, sizeof(buf))) > 0)
			write(cli, buf, (size_t)n);

		close(cli);
	}

	close(srv);
	return 0;
}
