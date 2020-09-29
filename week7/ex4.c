#include <stdio.h>
#include <stdlib.h>

void* my_realloc(void* ptr, size_t size) {
	if (ptr == NULL) {
		return malloc(size);
	}
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	void* new_ptr = malloc(size);
	// printf("Everything ok2\n");
	int old_size = malloc_usable_size(ptr);
	size = old_size < size ? old_size : size;
	// printf("%d\n", malloc_usable_size(ptr));
	for (int i = 0; i < size; ++i) {
		// printf("%d\n", i);
		((char*)new_ptr)[i] = (((char*)ptr)[i]);
	}
	// printf("Everything ok3\n");
	free(ptr);
	return new_ptr;

}

int main () {
	int* a = (int*)calloc(7, sizeof(int));
	// printf("%d\n", malloc_usable_size(a));
	for(int i = 0; i < 7; ++i) {
		a[i] = i;
	}
	// printf("Everything ok1\n");
	a = (int*)my_realloc(a, 9 * sizeof(int));
	// printf("Everything ok4\n");
	a[7] = 1;
	a[8] = 2;
	// printf("Everything ok5\n");
	for (int i = 0; i < 9; ++i) {
		printf("%d ", a[i]);
	}
	free(a);
	return 0;
}