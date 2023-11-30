// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX];
  int visited[MAX], count, mindistance=INFINITY, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];
        
// intilization
  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    
// vertex relaxation takes place in these snippet{
    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }
//}
    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
        if (mindistance + cost[nextnode][i] < distance[i] && !visited[i] ) {
          distance[i] = mindistance + cost[nextnode][i];
        }
    count++;
    mindistance = INFINITY;
  }

  // Printing the distance
  printf("vertex | distance from src\n");
    for (i = 0; i <n; i++)
    {
        printf("%d      | %d\n", i, distance[i]);
    }
}
int main() {
  int n=9, u;

  int Graph[MAX][MAX] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
u = 0;
  
Dijkstra(Graph, n, u);
  

return 0;
}
// output
// vertex | distance from src
// 0      | 0
// 1      | 4
// 2      | 12
// 3      | 19
// 4      | 21
// 5      | 11
// 6      | 9
// 7      | 8
// 8      | 14
