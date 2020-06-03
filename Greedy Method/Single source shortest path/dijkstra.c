#include <stdio.h>
#include <conio.h>
#define MAX 50
#define INF 32767
void main()
{
  int j, current, t, nv, i, s, cost[MAX][MAX], distance[MAX], visited[MAX], path[MAX], min, n;
  clrscr();
  printf("\n Enter the no. of vertices:");
  scanf("%d", &n);
  printf("\n Enter the cost matrix:\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", &cost[i][j]);
  printf("\n Enter the source vertex:");
  scanf("%d", &s);

  //Intialization
  for (i = 1; i <= n; i++)
  {
    distance[i] = INF;
    visited[i] = 0;
    path[i] = s;
  }
  //Distance of source vertex is 0
  t = 0;
  distance[s] = 0;
  //No. of nodes visited
  nv = 1;
  current = s;
  //Calculate till all the vertices are visited
  while (n != nv)
  {
    //Calculating the minimum distance of node adjacent to current
    for (i = 1; i <= n; i++)
    {
      if (cost[current][i] != 0)
        if (visited[i] != 1)
          if (distance[i] > cost[current][i] + t)
          {
            distance[i] = cost[current][i] + t;
            path[i] = current;
          }
    }
    //Calculating the minimum of all the adjacent vertices
    min = INF;
    for (i = 1; i <= n; i++)
    {
      if (visited[i] != 1)
        if (distance[i] < min)
        {
          min = distance[i];
          current = i;
        }
    }
    visited[current] = 1;
    nv += 1;
    t = distance[current];
  }
  for (i = 1; i <= n; i++)
    printf("%d", distance[i]);
  printf("\n Shorestest distance from source %d to all vertices are as follows:\n", s);
  for (i = 1; i <= n; i++)
  {
    if (i != s)
    {
      printf("\nPath:");
      j = i;
      printf("%d", i);
      do
      {
        j = path[j];
        printf("<-%d", j);

      }

      while (j != s);
    }
  }
  getch();
}
