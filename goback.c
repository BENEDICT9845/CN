#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, size;
    printf("\nEnter total frames: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nFRAME - %d", i + 1);
    }
    printf("\nEnter window size: ");
    scanf("%d", &size);
    int x = 1;
    int total = 0;
    while (x <= n)
    {
        int sent = 0;

        for (int i = x; i <= n && i < x + size; i++)
        {
            printf("\nFrame %d SENT!", i);
            total++;
        }
        for (int i = x; i <= n && i < x + size; i++)
        {

            int flag = rand() % 2;

            if (flag)
            {
                printf("\nFrame %d Not Received!", i);
                printf("\nRetransmitting...");
                break;
            }
            else
            {
                printf("\nFrame %d Received!", i);
                sent++;
            }
        }

        x += sent;
    }

    printf("\n\nAll data Successfully sent!\nTotal transmissions - %d", total);

    return 0;
}