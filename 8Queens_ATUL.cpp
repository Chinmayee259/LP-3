#include <iostream>
using namespace std;

#define N 8

int board[N][N] = {0};

// Check whether placing queen is safe
bool isSafe(int row, int col)
{
    // Check same column
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    int i = row - 1;
    int j = col - 1;

    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
            return false;

        i--;
        j--;
    }

    // Check upper-right diagonal
    i = row - 1;
    j = col + 1;

    while(i >= 0 && j < N)
    {
        if(board[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;
}

// Solve using Backtracking
bool solveNQueens(int row)
{
    // All 8 queens placed
    if(row == N)
        return true;

    // Try every column
    for(int col = 0; col < N; col++)
    {
        if(isSafe(row, col))
        {
            board[row][col] = 1;

            if(solveNQueens(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    if(solveNQueens(0))
    {
        cout << "Solution for 8 Queens:\n\n";

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists";
    }

    return 0;
}