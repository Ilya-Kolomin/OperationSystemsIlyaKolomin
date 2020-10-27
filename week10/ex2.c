#include <stdio.h>

int main () {
	char* s = "Hello";
	char buf[51];
	setvbuf(stdout, buf, _IOLBF, 50);
	for (int i = 0; i < 5; ++i) {
		printf("%c", s[i]);
		sleep(1);
	}
	return 0;
}