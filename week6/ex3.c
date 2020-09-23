#include <stdio.h>
#include <stdlib.h>

struct process {
	char name[256];
	int arrival, burst, remained_time;
};

struct process_data {
	int ET, TAT, WT;
};

int main () {
	int n, q;
	printf("Input the number of processes and quantum\n");
	scanf("%d%d", &n, &q);
	struct process* processes = (struct process*)malloc(n * sizeof(struct process));
	struct process_data* processes_data = (struct process_data*)malloc(n * sizeof(struct process_data));
	printf("List all processes in format \"{name} {arrival time} {burst time}\" sorted by arrival time\n");
	for (int i = 0; i < n; ++i) {
		scanf("%s %d %d", (processes[i].name), &(processes[i].arrival), &(processes[i].burst));
		processes[i].remained_time = processes[i].burst;
	}
	int last_process = 0, exited_processes = 0;
	int executing_process = 0, executing_processes = 0;
	int time_spent_on_current = 0;
	int time;
	for (time = 0; 1; ++time) {
		// printf("%d\n", time);
		if (executing_processes > 0) {
			processes[executing_process].remained_time--;
			time_spent_on_current++;
			if (processes[executing_process].remained_time == 0) {
				processes_data[executing_process].TAT = time - processes[executing_process].arrival;
				processes_data[executing_process].ET = time;
				processes_data[executing_process].WT = time - processes[executing_process].arrival - processes[executing_process].burst;
				exited_processes++;
				executing_processes--;
			}
		}
		while (last_process < n && processes[last_process].arrival <= time) {
			last_process++;
			executing_processes++;
		}
		if (executing_processes > 0) {
			if (time_spent_on_current == q || processes[executing_process].remained_time == 0) {
				time_spent_on_current = 0;
				executing_process = (executing_process + 1) % last_process;
				while (processes[executing_process].remained_time == 0) {
					executing_process = (executing_process + 1) % last_process;
				}
			}
		}
		if (exited_processes == n) {
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