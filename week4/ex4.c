#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main () {
	char s[256];
	while(1) {
		gets(s);
		char* args[20];
		int last_argument = 0, last_char = 0;
		args[0] = (char*)malloc(256*sizeof(char));
		for (int i = 0;; ++i) {
			if (s[i] == 0 || s[i] == '\n' || s[i] == 0) {
				if (s[i] == 0) {
					break;
				}
				last_argument++;
				args[last_argument] = (char*)malloc(256*sizeof(char));
				last_char = 0;
				continue;
			}
			args[last_argument][last_char++] = s[i];
		}
		args[last_argument + 1] = NULL;
		if (args[last_argument][0] == '&') {
			args[last_argument] = NULL;
			if (fork() == 0) {
				execve(args[0], args, NULL);
			}
		}
		else {
			system(s);
		}
	}
}