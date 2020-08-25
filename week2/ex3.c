#include <stdio.h>

int main (int argc, char* argv[]) {
    int n;
    sscanf(argv[1], "%d", &n);
    for(int i = 0; i < n; ++i) {
        int num_spaces = (2 * n - 1 - (1 + 2 * i)) / 2;
        int num_stars = 1 + 2 * i;
        for(int j = 0; j < num_spaces; ++j)
            printf(" ");
        for(int j = 0; j < num_stars; ++j)
            printf("*");
        printf("\n");
    }
    return 0;
}
