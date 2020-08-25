#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    
    printf("int: %lu %d, float: %lu %f, double: %lu %lf\n", sizeof(int), a, sizeof(float), b, sizeof(double), c);
    
    return 0;
}
