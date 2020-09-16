#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* some_func(int* i) {
	pthread_yield();
	printf("Hello from thread %ld which is %dth\n", pthread_self(), *i);
	printf("Exiting from thread number %d\n", *i);
	pthread_exit(NULL);
}

int main() {
	int n;
	scanf("%d", &n);
	pthread_t* thread_id = (pthread_t*)calloc(n, sizeof(pthread_t));
	for (int i = 0; i < n; ++i) {
		int rc = pthread_create(&thread_id[i], NULL, some_func, &i);
		if (rc) {
			printf("Error %d\n", rc);
			continue;
		}
		printf("Created new thread %ld number %d\n", thread_id[i], i);
		pthread_join(thread_id[i], NULL);
	}
	pthread_exit(NULL);
}