/*
 * Lab 5.6 — inotify directory watch starter
 * Usage: ./inotify_demo /path/to/dir
 */
#include <stdio.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

static const char *event_name(uint32_t mask)
{
	if (mask & IN_CREATE)
		return "CREATE";
	if (mask & IN_MODIFY)
		return "MODIFY";
	if (mask & IN_DELETE)
		return "DELETE";
	return "OTHER";
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s dir\n", argv[0]);
		return 1;
	}

	int fd = inotify_init();

	if (fd < 0) {
		perror("inotify_init");
		return 1;
	}

	int wd = inotify_add_watch(fd, argv[1],
				   IN_CREATE | IN_MODIFY | IN_DELETE);

	if (wd < 0) {
		perror("inotify_add_watch");
		return 1;
	}

	printf("Watching %s (Ctrl+C to stop)\n", argv[1]);

	/* TODO: loop read events; optional select/poll integration */
	char buf[BUF_LEN];

	for (;;) {
		ssize_t len = read(fd, buf, sizeof(buf));

		if (len <= 0)
			break;

		for (char *p = buf; p < buf + len;) {
			struct inotify_event *ev = (struct inotify_event *)p;

			if (ev->len)
				printf("[%s] %s\n", event_name(ev->mask), ev->name);

			p += EVENT_SIZE + ev->len;
		}
	}

	close(fd);
	return 0;
}
