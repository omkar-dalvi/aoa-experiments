#include <stdio.h>
#include <conio.h>
#define MAX 50

int binary(int x[MAX], int key, int low, int high)
{
  int mid;
  mid = (low + high) / 2;
  if (low > high)
    return -1;
  else if (key < x[mid])
    return (binary(x, key, low, mid - 1));
  else if (key > x[mid])
    return (binary(x, key, mid + 1, high));
  else
    return mid;
}

void main()
{
  int n, x[MAX], i, j, elem, pos;
  clrscr();
  printf("\n Enter the no. of elements:");
  scanf("%d", &n);
  printf("\n Enter the elements in the sorted order:");
  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);
  printf("\n Enter the element to be found:");
  scanf("%d", &elem);
  pos = binary(x, elem, 0, n - 1);
  if (pos == -1)
    printf("%d not found", elem);
  else
    printf("%d found at position %d", elem, pos);

  getch();
}
