#include <stdio.h>

int main()
{
    int n, m; // n = number of processes, m = number of resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], available[m], work[m], finish[n];
    int i, j, k, count = 0, isSafe_seq[n];

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // calculate need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter the available resources:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    // initialize work and finish arrays
    for (i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    printf("\n::NEED MATRIX::\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d \t\t", need[i][j]);
        }
        printf("\n");
    }

    // main algorithm loop
    while (count < n)
    {
        int found = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int isSafe = 1;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        isSafe = 0;
                        break;
                    }
                }
                if (isSafe)
                {
                    isSafe_seq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                    for (k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                }
            }
        }
        if (!found)
        {
            printf("System is not in safe state\n");
            return 0;
        }
        printf("\n");
    }

    // print isSafe sequence
    printf("System is in safe state.\nSafe sequence is: ");
    for (i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf(" %d", isSafe_seq[i]);
        }
        else
        {
            printf("%d -> ", isSafe_seq[i]);
        }
    }
    printf("\n");

    return 0;
}

/*

Allocation matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2


Maximum need matrix
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3

10 5 7
*/
