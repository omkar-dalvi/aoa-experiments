#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 50
int counter = 0;
void lcsp(char b[MAX][MAX], char s1[MAX], int i, int j)
{
  if (i == 0 || j == 0)
    return;
  if (b[i][j] == 'd')
  {
    lcsp(b, s1, i - 1, j - 1);
    printf("%c ", s1[i - 1]);
    counter++;
  }
  else if (b[i][j] == 'u')
    lcsp(b, s1, i - 1, j);
  else
    lcsp(b, s1, i, j - 1);
}
void main()
{
  int c[MAX][MAX], i, j, m, n;
  char b[MAX][MAX], s1[MAX], s2[MAX];
  clrscr();
  printf("\n Enter the first string:");
  gets(s1);
  printf("\n Enter the second string:");
  gets(s2);
  m = strlen(s1);
  n = strlen(s2);
  for (i = 0; i <= m; i++)
    ;
  c[i][0] = 0;
  for (i = 0; i <= n; i++)
    c[0][i] = 0;
  for (i = 0; i <= m; i++)
    for (j = 0; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 'd';
      }
      else if (c[i - 1][j] >= c[i][j - 1])
      {
        c[i][j] = c[i - 1][j];
        b[i][j] = 'u';
      }
      else
      {
        c[i][j] = c[i][j - 1];
        b[i][j] = 'r';
      }
    }
  printf("\n LCS matrix is as follows:\n");
  for (i = 0; i <= m; i++)
  {
    for (j = 0; j <= n; j++)
      printf("%d ", c[i][j]);
    printf("\n");
  }
  printf("\n LCS is as follows:");
  lcsp(b, s1, m, n);
  printf("\n The length of LCS is %d", counter);

  getch();
}
