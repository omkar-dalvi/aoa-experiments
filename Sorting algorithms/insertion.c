#include <stdio.h>
#include <conio.h>
#define MAX 50

void insertion(int x[MAX], int n)
{
  int i, j, key;
  for (i = 1; i < n; i++)
  {
    key = x[i];
    j = i - 1;
    while (j >= 0 && key < x[j])
    {
      x[j + 1] = x[j];
      j--;
    }
    x[j + 1] = key;
  }
}
void main()
{
  int n, x[MAX], i;
  clrscr();
  printf("\n Enter the no. of elements:");
  scanf("%d", &n);
  printf("\n Enter the elements:");
  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);
  insertion(x, n);
  printf("\n The sorted array is as follows:");
  for (i = 0; i < n; i++)
    printf("%d ", x[i]);
  getch();
}
