#include <stdio.h>

int full = 0, empty = 3;
int mutex = 1, x = 0;

int wait(int n) { return --n; }
int signal(int n) { return ++n; }

int Producer()
{
    mutex = wait(mutex);
    empty = wait(empty);
    x++;
    mutex = signal(mutex);
    full = signal(empty);
}

int Consumer()
{
    mutex = wait(mutex);
    full = wait(empty);
    x--;
    mutex = signal(mutex);
    empty = signal(empty);
}

int main()
{
    int ch = -1;
    while (ch != 3)
    {
        printf("\n1. Produce\n2. Consume\n3. Exit: ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            if (empty != 0 && mutex == 1)
            {
                Producer();
            }
            else
            {
                printf("\nThe queue is full");
            }
            break;
        }
        case 2:
        {
            if (full != 0 && mutex == 1)
            {
                Consumer();
            }
            else
            {
                printf("\nThe queue is full");
            }
            break;
        }
        case 3:
        {
            break;
        }
        default:
        {
            printf("\nNot a valid choice!");
            break;
        }
        }
    }
}
