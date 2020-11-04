#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main () {
	int fd = open("/dev/random", O_RDONLY);
	char ans[20];
	read(fd, ans, 20);
	int fd2 = open("ex1.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXG);
	write(fd2, ans, 20);
	close(fd);
	close(fd2);
	return 0;
}