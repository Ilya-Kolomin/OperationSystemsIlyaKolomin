#include <stdio.h>

void type0 (int n) {
    for (int i = 0; i < n; ++i) {
        int num_spaces = (2 * n - 1 - (1 + 2 * i)) / 2;
        int num_stars = 1 + 2 * i;
        for (int j = 0; j < num_spaces; ++j)
            printf(" ");
        for (int j = 0; j < num_stars; ++j)
            printf("*");
        printf("\n");
    }
}

void type1 (int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j)
            printf("*");
        printf("\n");
    }
}

void type2 (int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (i + 1 < n - i ? i + 1 : n - i); ++j)
            printf("*");
        printf("\n");
    }
}

void type3 (int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("*");
        printf("\n");
    }
}

int main (int argc, char* argv[]) {
    int n, type = 0;
    sscanf(argv[1], "%d", &n);
    printf("Enter a type of figure (from 0 to 3):\n");
    scanf("%d", &type);
    switch (type) {
        case 0:
            type0(n);
            break;
        case 1:
            type1(n);
            break;
        case 2:
            type2(n);
            break;
        case 3:
            type3(n);
            break;
    }
    return 0;
}
