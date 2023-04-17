#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int remaining_time;
};

int main()
{
    int n, i, j, time = 0, total_waiting_time = 0, total_turnaround_time = 0, smallest;
    float average_waiting_time, average_turnaround_time;
    struct Process *processes, temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for the processes
    processes = (struct Process *)malloc(n * sizeof(struct Process));

    // Read in the processes
    for (i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        printf("Enter the arrival time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Sort the processes by arrival time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (processes[i].arrival_time > processes[j].arrival_time)
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Execute the processes
    for (i = 0; i < n; i++)
    {
        smallest = i;
        for (j = i + 1; j < n; j++)
        {
            if (processes[j].remaining_time < processes[smallest].remaining_time && processes[j].arrival_time <= time)
            {
                smallest = j;
            }
        }
        processes[smallest].completion_time = time + processes[smallest].burst_time;
        processes[smallest].turnaround_time = processes[smallest].completion_time - processes[smallest].arrival_time;
        processes[smallest].waiting_time = processes[smallest].turnaround_time - processes[smallest].burst_time;
        total_waiting_time += processes[smallest].waiting_time;
        total_turnaround_time += processes[smallest].turnaround_time;
        time = processes[smallest].completion_time;
        processes[smallest].remaining_time = 99999; // Set to a large number to indicate completion
    }

    // Calculate the average waiting and turnaround times
    average_waiting_time = (float)total_waiting_time / n;
    average_turnaround_time = (float)total_turnaround_time / n;

    // Print out the results
    printf("\nPID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average waiting time is: %d", average_waiting_time);
    printf("Average turn around time is: %d", average_turnaround_time);
}