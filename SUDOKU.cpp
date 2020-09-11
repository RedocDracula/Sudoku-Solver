#include <bits/stdc++.h>
using namespace std;
int Sudoku[9][9] ;
/* SAMPLE INPUT
1 0 0 0 0 7 0 9 0
0 3 0 0 2 0 0 0 8
0 0 9 6 0 0 5 0 0
0 0 5 3 0 0 9 0 0
0 1 0 0 8 0 0 0 2
6 0 0 0 0 4 0 0 0
3 0 0 0 0 0 0 1 0
0 4 0 0 0 0 0 0 7
0 0 7 0 0 0 3 0 0
and SAMPLE OUTPUT
1,6,2,8,5,7,4,9,3,
5,3,4,1,2,9,6,7,8,
7,8,9,6,4,3,5,2,1,
4,7,5,3,1,2,9,8,6,
9,1,3,5,8,6,7,4,2,
6,2,8,7,9,4,1,3,5,
3,5,6,4,7,8,2,1,9,
2,4,1,9,3,5,8,6,7,
8,9,7,2,6,1,3,5,4,
*/
void fillpuzzle()
{
   cout<<" Enter the puzzle rowwise with 0 for empty slots "<<endl;
   for(int i=0;i<9;i++)
   {
     for(int j=0;j<9;j++)
     cin>>Sudoku[i][j];
   }
}

bool CheckFill()
{
   for(int i=0;i<9;i++)
   {
     for(int j=0;j<9;j++)
     {
       if(Sudoku[i][j]==0)
       return false;
     }
   }
   return true;
}
pair <int,int> emptyspace()
{
  for(int i=0;i<9;i++)
  {
     for(int j=0;j<9;j++)
     {
       if(Sudoku[i][j]==0)
       return make_pair(i,j);
     }
  }
}
bool boxcheck(int a,int b,int n)
{
  int c = a - a%3;
  int d = b- b%3;
  for(int row=0;row<3;row++)
  {
    for(int col=0;col<3;col++)
    {
      if(Sudoku[row+c][col+d]==n)
      {
        return false;
      }
    }
  }
  return true;
}

bool checksafe(int a,int b,int n)
{
    for(int i=0;i<9;i++)// row checker
    {
      if(Sudoku[a][i]==n)
      return false;
    }

    for(int i=0;i<9;i++)// coloumn checker
    {
      if(Sudoku[i][b]==n)
      return false;
    }

   if(!boxcheck(a,b,n))
   {
     return false;
   }
   return true;

}

bool SudokuSolver()
{

    if(CheckFill())
    return true;

    for(int i=1;i<10;i++)
    {
        pair <int,int> p = emptyspace();
        if(checksafe(p.first,p.second,i))
        {
            Sudoku[p.first][p.second]=i;
            if(SudokuSolver())
            {
              return true;
            }
              Sudoku[p.first][p.second]=0;
        }
    }

    return false;
}
int main()
{
     fillpuzzle();
     bool result = SudokuSolver();
     if(result)
     {
       cout<<" Solution to the puzzle : "<<endl;
       for(int i=0;i<9;i++)
       {
         for(int j=0;j<9;j++)
         cout<<Sudoku[i][j]<<",";
         cout<<endl;
       }
     }
     else
     cout<<" The puzzle has no solutions ! , sorry :("<<endl;


  return 0;
}
