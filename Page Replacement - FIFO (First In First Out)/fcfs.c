#include <stdio.h>

int main()
{
    int pages[50];
    int frameArray[50];
    int frameSize, numberOfPage, s, m;
    int pageFault = 0;

    printf("Enter the frame size: ");
    scanf("%d", &frameSize);

    printf("Enter the number of pages: ");
    scanf("%d", &numberOfPage);

    printf("Enter the pages: ");
    for (int i = 0; i < numberOfPage; i++)
    {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < frameSize; i++)
    {
        frameArray[i] = -1;
    }

    for (int i = 0; i < numberOfPage; i++)
    {
        // variable to track wether the current page was found or not
        s = 0;

        // Checking if the current page is present in our frame.
        for (int j = 0; j < frameSize; j++)
        {
            if (pages[i] == frameArray[j])
            {
                s++;
                pageFault--;
            }
        }

        // If not present then we need to increase our page fault;
        pageFault++;

        // This condition will fill the first frame when the frame is empty
        if (pageFault <= frameSize && s == 0)
        {
            frameArray[i] = pages[i];
        }
        // Checking which one is older, and where to add  our new frame which is not present in the frame.
        else if (s == 0)
        {
            frameArray[(pageFault - 1) % frameSize] = pages[i];
        }

        printf("\n");
        printf("Current page: %d", pages[i]);

        // Displaying frames array
        printf("\n\n::Frame Array::\n");

        for (int j = 0; j < frameSize; j++)
        {
            if (frameArray[j] == -1)
            {
                printf("| - | \t\t");
            }
            else
            {
                printf("| %d |\t\t", frameArray[j]);
            }
        }
    }
    printf("\n");

    printf("\nTotal (MISS): %d", pageFault);
    printf("\nTotal (HIT):  %d\n", numberOfPage - pageFault);
}