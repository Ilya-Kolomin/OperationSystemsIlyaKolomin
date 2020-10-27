#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main () {
	int fd1 = open("ex1.txt", O_RDWR), fd2 = open("ex1.memcpy.txt", O_RDWR);
	struct stat sb;
	fstat(fd1, &sb);
	int length = sb.st_size;
	ftruncate(fd2, length);
	void* addr1 = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
	void* addr2 = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
	memcpy(addr2, addr1, length);
	munmap(addr1, length);
	munmap(addr2, length);
	close(fd1);
	close(fd2);
	return 0;
}