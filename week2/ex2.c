#include <string.h>
#include <stdio.h>

int main () {
    char s[256];
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n / 2; ++i) {
        char t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
    puts(s);
    return 0;
}
