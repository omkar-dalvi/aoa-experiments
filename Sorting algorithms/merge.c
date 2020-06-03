#include <stdio.h>
#include <conio.h>
#define MAX 50
void merge(int x[MAX], int lb1, int ub1, int ub2)
{
  int i, j, k = 0, temp[MAX];
  i = lb1;
  j = ub1 + 1;
  while (i <= ub1 && j <= ub2)
  {
    if (x[i] < x[j])
      temp[k++] = x[i++];
    else
      temp[k++] = x[j++];
  }
  while (i <= ub1)
    temp[k++] = x[i++];
  while (j <= ub2)
    temp[k++] = x[j++];
  for (i = lb1, j = 0; i <= ub2; i++, j++)
    x[i] = temp[j];
}
void mergesort(int x[MAX], int lb, int ub)
{
  if (lb < ub)
  {
    int mid;
    mid = (lb + ub) / 2;
    mergesort(x, lb, mid);
    mergesort(x, mid + 1, ub);
    merge(x, lb, mid, ub);
  }
}
void main()
{
  int n, x[MAX], i, j;
  clrscr();
  printf("\n Enter the no. of elements");
  scanf("%d", &n);
  printf("\n Enter the elements:");
  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);
  mergesort(x, 0, n - 1);
  printf("\n The sorted array is as follows:");
  for (i = 0; i < n; i++)
    printf("%d ", x[i]);
  getch();
}
