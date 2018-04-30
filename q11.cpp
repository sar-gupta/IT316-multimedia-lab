// Sudoku

#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9] = {{3, 0, 0, 0, 0, 0, 0, 5, 4},
                  {2, 0, 4, 6, 0, 5, 0, 0, 0},
                  {0, 0, 1, 0, 0, 7, 0, 0, 3},
                  {0, 1, 0, 0, 0, 4, 0, 0, 0},
                  {8, 0, 6, 3, 0, 1, 4, 0, 5},
                  {0, 0, 0, 2, 0, 0, 0, 6, 0},
                  {9, 0, 0, 7, 0, 0, 1, 0, 0},
                  {0, 0, 0, 8, 0, 3, 5, 0, 7},
                  {4, 7, 0, 0, 0, 0, 0, 0, 2}};

int row=0, col=0;

void printSudoku()
{
  for (int i = 0; i < 9; i++)
  {
    cout << "\n";
    if (i == 0)
    {
      cout << "\n+-----------------------+\n";
    }
    else if (i % 3 == 0)
    {
      cout << "|-------+-------+-------|\n";
    }
    for (int j = 0; j < 9; j++)
    {
      if (j % 3 == 0)
      {
        cout << "| ";
      }
      if(sudoku[i][j] == 0) cout<<". ";
      else cout << sudoku[i][j] << " ";
      if (j == 8)
      {
        cout << "|";
      }
    }
  }
  cout << "\n+-----------------------+\n";
}

bool findEmptyCell()
{
  for (int i = row; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (sudoku[i][j] == 0)
      {
        row = i;
        col = j;
        // cout<<i<<" "<<j<<endl;
        return true;
      }
    }
  }
  return false;
}

bool isValid(int r, int c, int num)
{
  // check for row and column
  for (int i = 0; i < 9; i++)
  {
    if (sudoku[r][i] == num || sudoku[i][c] == num)
    {
      return false;
    }
  }
  //check for 3x3 box
  int startRow = (r / 3) * 3;
  int startCol = (c / 3) * 3;
  for (int i = startRow; i < startRow + 3; i++)
  {
    for (int j = startCol; j < startCol + 3; j++)
    {
      if (sudoku[i][j] == num)
      {
        return false;
      }
    }
  }
  return true;
}

bool solveSudoku()
{
  // cout<<row<<endl;
  int currRow, currCol;
  if (!findEmptyCell())
  {
    return true;
  }
  for (int num = 1; num <= 9; num++)
  {
    if (isValid(row, col, num))
    {
      // printSudoku();
      sudoku[row][col] = num;
      currRow = row;
      currCol = col;
      if (solveSudoku())
      {
        return true;
      }
      // backtracking
      row = currRow;
      col = currCol;
      sudoku[row][col] = 0;
    }
  }
  return false;
}

int main()
{
  cout << "You can change values of SUDOKU by changing the matrix.\n";
  printSudoku();
  // solveSudoku();
  if (solveSudoku())
  {
    cout<<"\nSOLVED";
    printSudoku();
  }
  else
  {
    cout << "No possible solution!\n";
  }
}