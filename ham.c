#include <stdio.h>

int main()
{

    int a[10];

    printf("\nEnter 4-bit code one by one\n");
    scanf("%d", &a[0]);
    scanf("%d", &a[1]);
    scanf("%d", &a[2]);
    scanf("%d", &a[4]);

    a[6] = a[4] ^ a[2] ^ a[0];
    a[5] = a[1] ^ a[4] ^ a[0];
    a[3] = a[1] ^ a[2] ^ a[0];

    printf("\nEncoded data: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d", a[i]);
    }
    int rec[10];
    printf("\nEnter the data received one by one: \n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &rec[i]);
    }

    int c3 = rec[3] ^ rec[2] ^ rec[1] ^ rec[0];
    int c5 = rec[5] ^ rec[4] ^ rec[1] ^ rec[0];
    int c6 = rec[6] ^ rec[4] ^ rec[2] ^ rec[0];

    if (c3 == 1 || c5 == 1 || c6 == 1)
    {
        int c = 4 * c3 + 2 * c5 + c6;
        printf("\nERROR FOUND!\nERROR Bit -> %d", 8 - c);

        printf("\nCorrected data: ");
        if (rec[7 - c] == 0)
        {
            rec[7 - c] == 1;
        }
        else
        {
            rec[7 - c] = 0;
        }

        for (int i = 0; i < 7; i++)
        {
            printf("%d", rec[i]);
        }
    }

    else
    {

        printf("No error FOUND!");
    }

    return 0;
}