#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main () {
	int fd = open("ex1.txt", O_RDWR);
	struct stat sb;
	ftruncate(fd, strlen("This is a nice day"));
	fstat(fd, &sb);
	int length = sb.st_size;
	void* addr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	strcpy(addr, "This is a nice day");
	munmap(addr, length);
	close(fd);
	return 0;
}