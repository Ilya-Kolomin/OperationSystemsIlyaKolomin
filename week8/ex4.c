#include <sys/resource.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	for (int i = 0; i < 10; ++i) {
		void* a = malloc(10*1024*1024);
		memset(a, 0, 10*1024*1024);
		struct rusage ret;
		getrusage(RUSAGE_SELF, &ret);
		printf("%li\n", ret.ru_maxrss);
		sleep(1);
	}
}