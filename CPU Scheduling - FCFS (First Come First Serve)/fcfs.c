#include <stdio.h>

int main()
{
    int n, i, arrival_time[20], burst_time[20], waiting_time[20], turnaround_time[20];

    float average_waiting_time = 0, average_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the arrival time and burst time for each process
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    waiting_time[0] = 0; // waiting time for first process is 0

    // Calculate waiting time for each process
    for (i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1] - arrival_time[i] + arrival_time[i - 1];
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++)
    {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++)
    {
        average_waiting_time += waiting_time[i];
        average_turnaround_time += turnaround_time[i];
    }

    average_waiting_time /= n;
    average_turnaround_time /= n;

    // Print the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average waiting time: %.2f\n", average_waiting_time);
    printf("Average turnaround time: %.2f\n", average_turnaround_time);

    return 0;
}
