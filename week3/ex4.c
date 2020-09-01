#include <stdio.h>

void swap_by_index(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int l, int r) {
	int pivot = arr[(l + r) / 2];
	int i = l - 1;
	int j = r + 1;
	while (1) {
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i >= j)
			return j;
		swap_by_index(arr, i, j);
	}
}

void quick_sort(int arr[], int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);
		quick_sort(arr, l, p);
		quick_sort(arr, p + 1, r);
	}
}

int main() {
	int arr[] = {143, 1234, 125, 4, 5234, 5, 2435, 27655, 285};
	quick_sort(arr, 0, 8);
	for (int i = 0; i < 8; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}