/*
 * Lab 6.3 — FCFS scheduler starter
 * Input: pairs of arrival burst on stdin
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int arrival;
	int burst;
	int waiting;
	int turnaround;
} Proc;

int main(void)
{
	Proc procs[64];
	int n = 0;

	while (n < 64 && scanf("%d %d", &procs[n].arrival, &procs[n].burst) == 2) {
		procs[n].id = n + 1;
		n++;
	}

	/* TODO: FCFS scheduling — compute waiting and turnaround */
	int time = 0;

	for (int i = 0; i < n; i++) {
		if (time < procs[i].arrival)
			time = procs[i].arrival;
		procs[i].waiting = time - procs[i].arrival;
		time += procs[i].burst;
		procs[i].turnaround = time - procs[i].arrival;
		printf("P%d done at t=%d\n", procs[i].id, time);
	}

	return 0;
}
