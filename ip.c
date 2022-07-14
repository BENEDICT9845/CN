#include <stdio.h>
int main()
{

label:
    printf("\nEnter ip: ");
    int a[6];
    char dot;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
        if (i == 3)
        {
            break;
        }
        scanf("%c", &dot);
    }

    for (int i = 0; i < 4; i++)
    {
        if (a[i] < 0 || a[i] > 255)
        {
            printf("\nInvalid! Enter Again..");
            goto label;
        }
    }

    if (a[0] >= 0 && a[0] < 128)
    {
        printf("\nClass A");
        printf("\nNetwork ID: %d", a[0]);
        printf("\nHost ID: %d.%d.%d", a[1], a[2], a[3]);
    }
    else if (a[0] >= 128 && a[0] < 192)
    {
        printf("\nClass B");
        printf("\nNetwork ID: %d.%d", a[0], a[1]);
        printf("\nHost ID: %d.%d", a[2], a[3]);
    }
    else if (a[0] >= 192 && a[0] < 224)
    {
        printf("\nClass C");
        printf("\nNetwork ID: %d.%d.%d", a[0], a[1], a[2]);
        printf("\nHost ID: %d", a[3]);
    }
    else if (a[0] >= 224 && a[0] < 239)
    {
        printf("\nClass D");
        printf("\nID: %d.%d.%d.%d", a[0], a[1], a[2], a[3]);
        // printf("\nHost ID: %d",a[3]);
    }
    else if (a[0] >= 240 && a[0] < 255)
    {
        printf("\nClass C");
        printf("\nNetwork ID: %d.%d.%d.%d", a[0], a[1], a[2], a[3]);
        // printf("\nHost ID: %d",a[3]);
    }
    else
    {
        printf("Invalid");
        goto label;
    }

    return 0;
}