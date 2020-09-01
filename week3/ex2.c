#include <stdio.h>

void bubble_sort(int array[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main () {
	int a[] = {5, 4, 3, 2, 1};
	bubble_sort(a, 5);
	for (int i = 0; i < 5; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}