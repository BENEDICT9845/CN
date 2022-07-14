#include <stdio.h>

struct
{
    int dist[20];
    int from[20];
} a[20];

int main()
{

    int n;
    int cost[20][20];
    printf("\nEnter the number of nodes/routers: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            a[i].dist[j] = cost[i][j];
            a[i].from[j] = j;
        }
    }
    int count;
    do
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (a[i].dist[j] > cost[i][k] + a[k].dist[j])
                    {
                        a[i].dist[j] = a[i].dist[k] + a[k].dist[j];
                        a[i].from[j] = k;
                        count++;
                    }
                }
            }
        }

    } while (count != 0);

    for (int i = 0; i < n; i++)
    {
        printf("\nRouter/Node %d", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("\nNode-->%d Via-->%d Dist-->%d", j + 1, a[i].from[j] + 1, a[i].dist[j]);
        }
    }

    return 0;
}
