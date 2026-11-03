# Size of chessboard
N = 8

# Create 8 x 8 chessboard
board = [[0 for j in range(N)] for i in range(N)]


def isSafe(row, col):   # O(n)

    # Check column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper-left diagonal
    i = row - 1
    j = col - 1

    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False

        i -= 1
        j -= 1

    # Check upper-right diagonal
    i = row - 1
    j = col + 1

    while i >= 0 and j < N:
        if board[i][j] == 1:
            return False

        i -= 1
        j += 1

    # Position is safe
    return True


def SolveQueens(row):

    # Base case
    if row == N:
        return True

    # Try every column
    for col in range(N):

        # Check whether position is safe
        if isSafe(row, col):

            # Place queen
            board[row][col] = 1

            # Solve next row recursively
            if SolveQueens(row + 1):
                return True

            # Backtracking
            board[row][col] = 0

    return False


# Main program

# First queen placed at row 0, column 0
board[0][0] = 1

# Start solving from row 1
if SolveQueens(1):

    print("Final 8-Queens Matrix:\n")

    # Display chessboard
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=" ")
        print()

else:
    print("No solution exists.")