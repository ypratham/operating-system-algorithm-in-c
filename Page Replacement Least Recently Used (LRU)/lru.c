#include <stdio.h>
#include <limits.h>

int checkHit(int incomingPage, int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
    {
        if (incomingPage == queue[i])
        {
            return 1;
        }
    }
    return 0;
}

void printFrame(int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
    {
        printf("%d\t\t\t", queue[i]);
    }
}

int main()
{

    int pages[50];
    int frameSize, numberOfPages;

    printf("Enter the frame size: ");
    scanf("%d", &frameSize);

    printf("Enter the number of pages: ");
    scanf("%d", &numberOfPages);

    printf("Enter the pages: ");
    for (int i = 0; i < numberOfPages; i++)
    {
        scanf("%d", &pages[i]);
    }

    int pageFault = 0;
    int hit = 0;
    int occupied = 0;
    int queue[10];
    int distance[10];

    for (int i = 0; i < numberOfPages; i++)
    {
        printf("Current page %d:  \t\t", pages[i]);

        // Check if the page is already present in the frame
        if (checkHit(pages[i], queue, occupied))
        {
            hit++;
            printFrame(queue, occupied);
        }

        // First pages when the frame is empty
        else if (occupied < frameSize)
        {
            queue[occupied] = pages[i];
            pageFault++;
            occupied++;

            printFrame(queue, occupied);
        }
        // If the frame is full and a page is to be replaced. Using LRU
        else
        {
            // Setting current min as max value
            int max = -19999;
            int index;

            // Calculating distance of each frame pages and getting the max distance.
            for (int j = 0; j < frameSize; j++)
            {
                distance[j] = 0;

                // iterating backwards anc finding the distance of each page.
                for (int k = i - 1; k >= 0; k--)
                {
                    ++distance[j];
                    if (queue[j] == pages[k])
                    {
                        break;
                    }
                }

                if (distance[j] > max)
                {
                    max = distance[j];
                    index = j;
                }
            }

            queue[index] = pages[i];
            printFrame(queue, occupied);
            pageFault++;
        }
        printf("\n");
    }

    printf("MISS : %d\n", pageFault);
    printf("HIT: %d\n", hit);
}

//