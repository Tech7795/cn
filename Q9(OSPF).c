// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX];
  int visited[MAX], count, mindistance=INFINITY, nextnode, i, j,lastvisit[MAX];

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
    lastvisit[i]=start;
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
          lastvisit[i]=nextnode;
        }
    count++;
    mindistance = INFINITY;
  }

 for(i=0;i<n;i++){
        printf("%d ==> %d : path taken: %d",start,i,i);
        int w= i;
        while(w != start){
            printf("<-- %d",lastvisit[w]);
            w = lastvisit[w];
        }
        printf("\nshortest path cost : %d\n",distance[i]);
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
// 0 ==> 0 : path taken: 0
// shortest path cost : 0
// 0 ==> 1 : path taken: 1<-- 0
// shortest path cost : 4
// 0 ==> 2 : path taken: 2<-- 1<-- 0
// shortest path cost : 12
// 0 ==> 3 : path taken: 3<-- 2<-- 1<-- 0
// shortest path cost : 19
// 0 ==> 4 : path taken: 4<-- 5<-- 6<-- 7<-- 0
// shortest path cost : 21
// 0 ==> 5 : path taken: 5<-- 6<-- 7<-- 0
// shortest path cost : 11
// 0 ==> 6 : path taken: 6<-- 7<-- 0
// shortest path cost : 9
// 0 ==> 7 : path taken: 7<-- 0
// shortest path cost : 8
// 0 ==> 8 : path taken: 8<-- 2<-- 1<-- 0
// shortest path cost : 14
