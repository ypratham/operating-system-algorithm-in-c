#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    n = 5;                                                                     // Number of processes
    m = 3;                                                                     // Number of resources
    int alloc[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; // Resources allocated to processes
    int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {4, 2, 2}, {5, 3, 3}};   // Maximum resources required for processes
    int avail[3] = {10, 5, 7};                                                 // Available resources
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j]; // Resources still needed for processes
        }
    }
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1; // Not enough resources available
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y]; // Resources allocated to process are freed up
                    }
                    f[i] = 1; // Process has finished
                }
            }
        }
    }
    printf("Safe Sequence is: ");
    for (i = 0; i < n - 1; i++)
    {
        printf("%d -> ", ans[i]); // Prints safe sequence of processes
    }
    printf("%d\n", ans[n - 1]);
    return 0;
}
