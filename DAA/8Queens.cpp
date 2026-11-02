#include<iostream>
using namespace std;

// Size of the chessboard
const int N = 8;

// Create an 8 x 8 chessboard
int board[N][N] = {0};

bool isSafe(int row, int col){   //O(n)
    // Check column
    for(int i = 0; i < row; i++){
        if(board[i][col] == 1){
            return false;
        }
    }

    // Check upper-left diagonal
    int i = row - 1;
    int j = col - 1;

    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--; 
        j--;
    }

    // Check upper-right diagonal
    i = row - 1;
    j = col + 1;
    while(i >= 0 && j < N){
        if(board[i][j] == 1){
            return false;
        }
        i--; 
        j++;
    }

    // No queen is attacking this position
    return true;
}


bool SolveQueens(int row){
    // Base case: If we have reached row N, all N queens have been successfully placed
    if(row == N){
        return true;
    }

    // Try placing a queen in every column of the current row
    for(int col = 0; col < N; col++){   //O(n!)

        // Check whether the current position is safe
        if(isSafe(row, col)){
            // Place the queen
            board[row][col] = 1;

            // Recursively solve for the next row
            if(SolveQueens(row+1)){   
                return true;
            }

            // If solution is not possible, remove the queen (BACKTRACK)
            board[row][col] = 0;
        }
    }

    // No valid position found in this row
    return false;
}

int main(){
    // First queen is already placed at row 0, column 0
    board[0][0] = 1;

    // Start solving from row 1
    if(SolveQueens(1)){
        cout << "Final 8-Queens Matrix: \n\n";

        // Display the final chessboard
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    else{
        // If no solution exists
        cout << "No solution exist.";
    }

    return 0;
}

// Compilation
// g++ 8Queens.cpp -o 8Queens 

// Run
// 8Queens

// TC - O(n! * n)
// n! - recursion
// n - isSafe
