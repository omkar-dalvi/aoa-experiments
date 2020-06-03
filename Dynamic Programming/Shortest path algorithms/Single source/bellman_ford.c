#include <stdio.h>
#include <conio.h>
#define MAX 50
#define INF 32000

int min(int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}
void main()
{
  int k, s, j, n, cost[MAX][MAX], distance[MAX], i, parent[MAX];
  clrscr();
  printf("\n Enter the no. of vertices:");
  scanf("%d", &n);
  printf("\n Enter the cost matrix:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0 && i != j)
        cost[i][j] = INF;
    }
  for (i = 0; i < n; i++)
  {
    distance[i] = INF;
  }
  printf("\n Enter the source vertex");
  scanf("%d", &s);
  distance[s] = 0;
  for (i = 0; i < n; i++)
    parent[i] = s;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++)
      {
        distance[k] = min(distance[k], distance[j] + cost[j][k]);
      }
  }
  printf("\n Cost from %d to all vertices are as follows:");
  printf("\n Vertex \t Cost");
  for (i = 0; i < n; i++)
  {
    printf("%d \t %d", i + 1, distance[i]);
  }

  getch();
}
