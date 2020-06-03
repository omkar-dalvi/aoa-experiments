//Floyd Warshall
#include <stdio.h>
#include <conio.h>
#define MAX 50
#define INF 32767
int min(int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}
void main()
{
  int n, cost[MAX][MAX], a[MAX][MAX], i, j, k;
  clrscr();
  printf("\n Enter the no. of vertices:");
  scanf("%d", &n);
  printf("\n Enter the cost matrix:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      scanf("%d", &cost[i][j]);
      if (i == j)
        a[i][j] = 0;
      else if (cost[i][j] == 0)
        a[i][j] = INF;
      else
        a[i][j] = cost[i][j];
    }
  for (k = 0; k < n; k++)
  {
    printf("A(%d) is as follows:\n", k + 1);
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }
  printf("\n The shortest path matrix is as follows\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }

  getch();
}
