#!/usr/bin/python3
import sys


def is_safe(board, row, col, n):
    """Checks if a queen can be placed on board[row][col]."""
    # Check for queens in the same column
    for i in range(row):
        if board[i][col]:
            return False

    # Check for queens on the upper-left diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False

    # Check for queens on the upper-right diagonal
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j]:
            return False

    return True

def solve_nqueens(board, row, n, solutions):
    """Recursive function to solve the N Queens problem."""
    if row == n:
        solution = []
        for i in range(n):
            for j in range(n):
                if board[i][j]:
                    solution.append([i, j])
        solutions.append(solution)
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1
            solve_nqueens(board, row + 1, n, solutions)
            board[row][col] = 0  # Backtrack

def print_solutions(solutions):
    """Print all solutions in the required format."""
    for solution in solutions:
        print(solution)

def nqueens(n):
    """Main function to solve and print the N Queens problem."""
    board = [[0 for _ in range(n)] for _ in range(n)]
    solutions = []
    solve_nqueens(board, 0, n, solutions)
    print_solutions(solutions)

def main():
    """Handle input and validate arguments."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    nqueens(n)

if __name__ == "__main__":
    main()
