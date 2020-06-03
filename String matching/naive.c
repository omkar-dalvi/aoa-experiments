#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 10
int counter;
void naive_string_matcher(char t[MAX], char p[MAX])
{
  int n, m, s, j;
  n = strlen(t);
  m = strlen(p);
  counter = 0;
  for (s = 0; s <= n - m; s++)
  {
    j = 0;
    while (j < m && tolower(t[s + j]) == tolower(p[j]))
    {
      counter++;
      j += 1;
      if (j >= m)
        printf("\n Pattern found at position %d", s);
    }
  }
  if (j == 0 && counter == 0)
    printf("\n Pattern not found");
}
void main()
{
  char t[MAX], p[MAX];
  clrscr();
  printf("\n Enter the text string:");

  gets(t);
  printf("\n Enter the pattern string:");
  gets(p);
  naive_string_matcher(t, p);

  getch();
}
