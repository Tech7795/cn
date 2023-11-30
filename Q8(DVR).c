#include <stdio.h>
struct node
{
    unsigned dist[50];
    unsigned from[50];
} rt[10];
int main()
{
    int graph[50][50], n,count;
    printf("enter no.of vertices: ");
    scanf("%d", &n);
    printf("enter cost matrix (99 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            graph[i][i] = 0;
            rt[i].dist[j] = graph[i][j];
            rt[i].from[j] = j;
        }
    }
    do
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (rt[i].dist[j] > graph[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);
    for(int i=0;i<n;i++){
        printf("for router %c\n",i+65);
        printf("Node | via | distance\n");
        for(int j=0;j<n;j++){
            printf("%5c|%5c|%5d\n",j+65,rt[i].from[j]+65,rt[i].dist[j]);
        }
        printf("\n\n");
    }

return 0;
}

// output
// enter no.of vertices: 4
// enter cost matrix (99 for no edge):
// 0 8 99 5
// 8 0 2 99
// 99 2 0 3
// 5 99 3 0
// for router A
// Node | via | distance
//     A|    A|    0
//     B|    B|    8
//     C|    D|    8
//     D|    D|    5


// for router B
// Node | via | distance
//     A|    A|    8
//     B|    B|    0
//     C|    C|    2
//     D|    C|    5


// for router C
// Node | via | distance
//     A|    D|    8
//     B|    B|    2
//     C|    C|    0
//     D|    D|    3


// for router D
// Node | via | distance
//     A|    A|    5
//     B|    C|    5
//     C|    C|    3
//     D|    D|    0
