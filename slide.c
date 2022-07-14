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
    while (x <= n)
    {
        for (int i = x; i <= n && i < x + size; i++)
        {
            printf("\nFrame %d SENT!", i);
        }
        int nak = x + rand() + size;

        if (nak == x)
        {
            printf("\nAll data from this block recived successfully");
            for (int i = x; i <= n && i < x + size; i++)
            {
                printf("\nFrame %d ACK Received!", i);
            }
            x += size;
            continue;
        }
        else
        {
            if (nak > n)
            {
                nak = n;
            }
            printf("\nNAK = %d", nak);
            printf("\nRetransmitting...");
            printf("Frame %d RESENT!", nak);
            printf("\n ACK Received! Frame %d", nak);
            x += size;
        }
    }

    printf("\n\nAll data Successfully sent!\n");

    return 0;
}
