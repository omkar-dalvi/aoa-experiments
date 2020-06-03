#include <stdio.h>
#include <conio.h>
#define MAX 50
int board[MAX];
void print_board(int nq)
{
  int i, j, cp;

  for (i = 1; i <= nq; i++)
  {
    cp = board[i];
    for (j = 0; j <= nq; j++)
    {
      if (j == cp)
        printf(" Q ");
      else
        printf(" - ");
    }
    printf("\n");
  }
}
int place(int row, int column)
{
  int i;
  for (i = 1; i <= row - 1; i++)
  {
    if (board[i] == column)
      return 0;
    else if (abs(board[i] - column) == abs(i - row))
      return 0;
  }
  return 1;
}
void NQueen(int row, int nq)
{
  int i, column;
  for (column = 1; column <= nq; column++)
  {
    if (place(row, column))
    {
      board[row] = column;
      if (row == nq)
      {
        print_board(nq);
        printf("\n");
      }
      else
        NQueen(row + 1, nq);
    }
  }
}
void main()
{
  int nq;
  clrscr();
  printf("\n Enter the no. of queens:");
  scanf("%d", &nq);
  NQueen(1, nq);
  getch();
}
