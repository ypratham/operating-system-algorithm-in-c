#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {

            if (arr[i] > arr[j])
            {
                int tempArrValue = arr[j];
                arr[j] = arr[i];
                arr[i] = tempArrValue;
            }
        }
    }
}

int fcfs(int queue[], int currentHeadPos, int queueSize)
{
    int ans = 0;
    printf("\n::FCFS Algo::\n");
    printf("::Head movements::\n");
    for (int i = 0; i < queueSize; i++)
    {
        ans += abs(currentHeadPos - queue[i]);
        printf(" %d -> %d \n", currentHeadPos, queue[i]);
        currentHeadPos = queue[i];
    }

    return ans;
}

int scan(int currentHeadPos, int gth[], int j, int lth[], int k, int not )
{
    int ans = 0;
    printf("\n::SCAN Algo::\n");
    printf("::Head movements::\n");
    for (int i = 0; i < j; i++)
    {
        printf("%d -> %d \n", currentHeadPos, gth[i]);
        ans += abs(currentHeadPos - gth[i]);
        currentHeadPos = gth[i];
    }
    printf("%d -> %d \n", currentHeadPos, not -1);
    ans += abs(currentHeadPos - (not -1));
    currentHeadPos = not -1;
    for (int i = k - 1; i >= 0; i--)
    {
        printf("%d -> %d \n", currentHeadPos, lth[i]);
        ans += abs(currentHeadPos - lth[i]);
        currentHeadPos = lth[i];
    }
    return ans;
}

int cscan(int currentHeadPos, int gth[], int j, int lth[], int k, int not )
{
    int ans = 0;
    printf("\n::SCAN Algo::\n");
    printf("::Head movements::\n");
    for (int i = 0; i < j; i++)
    {
        printf("%d -> %d \n", currentHeadPos, gth[i]);
        ans += abs(currentHeadPos - gth[i]);
        currentHeadPos = gth[i];
    }

    printf("%d -> %d \n", currentHeadPos, not -1);
    ans += abs(currentHeadPos - (not -1));
    currentHeadPos = not -1;

    printf("%d -> %d \n", currentHeadPos, 0);
    ans += abs(currentHeadPos - 0);
    currentHeadPos = 0;
    for (int i = 0; i < k; i++)
    {
        printf("%d -> %d \n", currentHeadPos, lth[i]);
        ans += abs(currentHeadPos - lth[i]);
        currentHeadPos = lth[i];
    }

    return ans;
}

int main()
{
    int queueSize, currentHeadPos, numberOfTracks;
    int greaterThanHead[50], lessThanHead[50];
    int j = 0, k = 0;
    printf("Enter the current head position: ");
    scanf("%d", &currentHeadPos);

    printf("\nEnter number of tracks: ");
    scanf("%d", &numberOfTracks);

    printf("\nEnter the size of the queue: ");
    scanf("%d", &queueSize);

    int queue[queueSize];
    printf("\nEnter queue elements: \n");
    for (int i = 0; i < queueSize; i++)
    {
        scanf("%d", &queue[i]);
        if (queue[i] > currentHeadPos)
        {
            greaterThanHead[j++] = queue[i];
        }
        else
        {
            lessThanHead[k++] = queue[i];
        }
    }

    sort(greaterThanHead, j);
    sort(lessThanHead, k);

    printf("\nTotal head movement (using FCFS Algorithm): %d\n", fcfs(queue, currentHeadPos, queueSize));
    printf("\nTotal head movement (using SCAN Algorithm): %d\n", scan(currentHeadPos, greaterThanHead, j, lessThanHead, k, numberOfTracks));
    printf("\nTotal head movement (using C-SCAN Algorithm): %d\n", cscan(currentHeadPos, greaterThanHead, j, lessThanHead, k, numberOfTracks));
}

// 82 170 43 140 24 16 190