#include <stdio.h>

void main()
{
    int n, bt[20], wt[20], tat[20], i, j, smallest;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process: \n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; // waiting time for first process is 0

    // calculate waiting time
    for (i = 1; i < n; i++)
    {
        smallest = i;
        for (j = 0; j < i; j++)
        {
            if (bt[j] < bt[smallest])
            {
                smallest = j;
            }
        }
        wt[i] = wt[smallest] + bt[smallest];
    }

    // calculate turnaround time
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }

    // calculate average waiting time and turnaround time
    avg_wt = 0;
    avg_tat = 0;
    for (i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}
