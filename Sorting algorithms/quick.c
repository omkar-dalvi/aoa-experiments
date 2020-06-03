#include <stdio.h>
#include <conio.h>
#define MAX 50
int partition(int x[MAX], int lb, int ub)
{
  int a, up, down, temp;
  a = x[lb];
  down = lb;
  up = ub;
  while (down < up)
  {
    while (x[down] <= a && down < ub)
      down++;
    while (x[up] > a)
      up--;
    if (down < up)
    {
      temp = x[down];
      x[down] = x[up];
      x[up] = temp;
    }
  }
  x[lb] = x[up];
  x[up] = a;
  return up;
}
void quicksort(int x[MAX], int lb, int ub)
{
  if (lb < ub)
  {
    int j;
    j = partition(x, lb, ub);
    quicksort(x, lb, j - 1);
    quicksort(x, j + 1, ub);
  }
}
void main()
{
  int n, x[MAX], i;
  printf("\n Enter the no. of elements:");
  scanf("%d", &n);
  printf("\n Enter the elements:");
  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);
  quicksort(x, 0, n - 1);
  printf("\n The sorted array is as follows:");
  for (i = 0; i < n; i++)
    printf("%d ", x[i]);
  getch();
}
