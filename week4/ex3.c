#include <stdlib.h>
#include <stdio.h>

int main() {
	char buf[256];
	while(scanf("%s", buf)) {
		system(buf);
	}
	return;
}