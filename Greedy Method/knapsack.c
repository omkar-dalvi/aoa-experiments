#include <stdio.h>
#include <conio.h>
#define MAX 50
void sort(float profit[MAX], float weight[MAX], float ratio[MAX], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - 1 - i; j++)
    {
      if (ratio[j] > ratio[j + 1])
      {
        temp = ratio[j];
        ratio[j] = ratio[j + 1];
        ratio[j + 1] = temp;

        temp = weight[j];
        weight[j] = weight[j + 1];
        weight[j + 1] = temp;

        temp = profit[j];
        profit[j] = profit[j + 1];
        profit[j + 1] = temp;
      }
    }
}
void main()
{
  float p = 0.0, m, profit[MAX], weight[MAX], ratio[MAX], x, ans[MAX];
  int n, i;
  clrscr();
  printf("\n Enter the no. of items:");
  scanf("%d", &n);
  printf("\n Enter the weight of each item:");
  for (i = 0; i < n; i++)
    scanf("%f", &weight[i]);
  printf("\n Enter the corresponding profit of each item:");
  for (i = 0; i < n; i++)
    scanf("%f", &profit[i]);
  printf("\n Enter the knapsack capacity:");
  scanf("%f", &m);
  x = m;
  for (i = 0; i < n; i++)
    ratio[i] = profit[i] / weight[i];
  sort(profit, weight, ratio, n);
  for (i = 0; i < n; i++)
  {
    if (weight[i] > x)
      break;
    else
    {
      p += profit[i];
      x -= weight[i];
      ans[i] = 1;
    }
  }
  if (i < n && x != 0)
  {
    ans[i] = x / weight[i];
    p += profit[i] * ans[i];
    i++;
  }
  while (i < n)
  {
    ans[i] = 0;
    i++;
  }
  printf("\n Total profit:%f", p);
  printf("\n Weight \t Fraction of weight");
  for (i = 0; i < n; i++)
    printf("\n %d\t\t %f", (int)weight[i], ans[i]);

  getch();
}
