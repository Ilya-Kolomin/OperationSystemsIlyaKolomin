#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main (int argv, char** args) {
	int count = 0;
	for (int i = 1; i < argv; ++i) {
		if (args[i][0] != '-')
			count++;
	}
	int* fds = (int*)calloc(count, sizeof(int));
	int* a = (int*)calloc(count, sizeof(int));
	int last = 0;
	for (int i = 1; i < argv; ++i) {
		if (args[i][0] == '-') {
			a[last] = 1;
		} else {
			if (a[last]) {
				fds[last] = open(args[i], O_RDWR | O_CREAT | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXG);
			} else {
				fds[last] = open(args[i], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXG);
				ftruncate(fds[last], 0);
			}
			last++;
		}
	}
	char buf[20];
	while (1) {
		size_t res = read(STDIN_FILENO, buf, 20);
		// for (int i = 0; i < res; ++i) {
			// printf("%c", buf[i]);
		// }
		write(STDOUT_FILENO, buf, res);
		for (int i = 0; i < count; ++i) {
			write(fds[i], buf, res);
		}
		if (res == 0)
			break;
	}
	return 0;
}