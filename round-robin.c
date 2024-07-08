#include <stdio.h>
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;
void roundRobin(Process processes[], int n, int time_slice) {
    int remaining_processes = n;
    int current_time = 0;
    int index = 0;
    while (remaining_processes > 0) {
        if (processes[index].remaining_time > 0) {
            if (processes[index].remaining_time <= time_slice) {
                current_time += processes[index].remaining_time;
                processes[index].remaining_time = 0;
                printf("Process %d completed at time %d\n", processes[index].process_id, current_time);
                remaining_processes--;
            } else {
                current_time += time_slice;
                processes[index].remaining_time -= time_slice;
                printf("Process %d executed for time slice at time %d\n", processes[index].process_id, current_time);
            }
        }
        index = (index + 1) % n;
    }
}

int main() {
    Process processes[] = 
    {
        {1, 0, 10, 10},
        {2, 0, 4, 4},
        {3, 0, 5, 5},
        {4, 0, 3, 3}
    };
    int n = sizeof(processes) / sizeof(Process);
    int time_slice = 4;
    printf("Round Robin Scheduling:\n");
    roundRobin(processes, n, time_slice);
    return 0;
}
