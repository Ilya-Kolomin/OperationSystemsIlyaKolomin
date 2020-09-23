#include <stdio.h>
#include <stdlib.h>

struct process {
	char name[256];
	int arrival, burst;
};

struct process_data {
	int ET, TAT, WT, RT;
};

int main () {
	int n;
	printf("Input the number of processes\n");
	scanf("%d", &n);
	struct process* processes = (struct process*)malloc(n * sizeof(struct process));
	struct process_data* processes_data = (struct process_data*)malloc(n * sizeof(struct process_data));
	printf("List all processes in format \"{name} {arrival time} {burst time}\" sorted by arrival time\n");
	for (int i = 0; i < n; ++i) {
		scanf("%s %d %d", (processes[i].name), &(processes[i].arrival), &(processes[i].burst));
	}
	int last_process = 0, number_of_waiting_processes = 0;
	int executing_process = -1;
	int time;
	int* wait_queue = (int*)calloc(n, sizeof(int));
	for (time = 0; 1; ++time) {
		if (executing_process != -1) {
			if (processes_data[executing_process].RT + processes[executing_process].burst == time) {
				processes_data[executing_process].TAT = time - processes[executing_process].arrival;
				processes_data[executing_process].ET = time;
				processes_data[executing_process].WT = time - processes[executing_process].arrival - processes[executing_process].burst;
				executing_process = -1;
			}
		}
		while(last_process < n && processes[last_process].arrival <= time) {
			wait_queue[number_of_waiting_processes++] = last_process++;
			for (int i = number_of_waiting_processes - 1; i > 0; --i) {
				if (processes[wait_queue[i]].burst > processes[wait_queue[i - 1]].burst) {
					int temp = wait_queue[i];
					wait_queue[i] = wait_queue[i - 1];
					wait_queue[i - 1] = temp;
				} else {
					break;
				}
			}
		}
		if (executing_process == -1 && number_of_waiting_processes > 0) {
			executing_process = wait_queue[--number_of_waiting_processes];
			processes_data[executing_process].RT = time;
		}
		if (executing_process == -1 && last_process == n && number_of_waiting_processes == 0) {
			break;
		}
	}
	double avTAT = 0, avWT = 0;
	for (int i = 0; i < n; ++i) {
		avTAT += processes_data[i].TAT;
		avWT += processes_data[i].WT;
	}
	avTAT /= n;
	avWT /= n;
	printf("Completion time: %d, avarage TAT: %lf, avarage WT: %lf\n", time, avTAT, avWT);
	for (int i = 0; i < n; ++i) {
		printf("%s: ET: %d, TAT: %d, WT: %d\n", processes[i].name, processes_data[i].ET, processes_data[i].TAT, processes_data[i].WT);
	}
}