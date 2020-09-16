#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SLEEP 0
#define AWAKE 1

int buffer[8];
int count = 0;
int consumer_state = AWAKE;
int producer_state = AWAKE;

void consumer() {
	unsigned int number_of_output = 0;
	long int sum = 0;
	while(1) {
		while(consumer_state == SLEEP) {
			pthread_yield();
		}
		if (count == 0) {
			consumer_state = SLEEP;
			if (producer_state == SLEEP) {
				producer_state = AWAKE;
			}
			continue;
		}
		sum += buffer[--count];
		if (number_of_output++ == 50000) {
			printf("I am not sleeping, the sum of numbers from buffer: %d\n", sum);
			number_of_output = 0;
		}
	}
}

void producer() {
	while(1) {
		while(producer_state == SLEEP) {
			pthread_yield();
		}
		if (count == 8) {
			producer_state = SLEEP;
			if (consumer_state == SLEEP) {
				consumer_state = AWAKE;
			}
			continue;
		}
		for(int i = 0; i < 10000; ++i) {
			//Skipping some time to "generate" number
			rand() / rand();
		}
		buffer[count++] = rand();
	}
}

int main () {
	int producer_thread, consumer_thread;
	pthread_create(&consumer_thread, NULL, consumer, NULL);
	pthread_create(&producer_thread, NULL, producer, NULL);
	while(1) {
		if (consumer_state == AWAKE || producer_state == AWAKE) {
			pthread_yield();
		}
	}
	printf("They both fall asleep\n");
	pthread_exit(NULL);
}