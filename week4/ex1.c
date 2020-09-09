#include <stdio.h>
#include <sys/types.h>

int main() {
	int n = 7;
	printf("Hello from parent %d\n", getpid() - n);
	fork();
	printf("Hello from child %d\n", getpid() - n);
	return 0;
}