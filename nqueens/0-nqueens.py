#!/usr/bin/python3
import sys


def print_solution(solution):
    """Prints the solution in the required format."""
    print([[row, col] for row, col in enumerate(solution)])


def is_safe(solution, row, col):
    """Checks if placing a queen at (row, col) is safe."""
    for r, c in enumerate(solution[:row]):
        # Checks column and diagonal conflicts
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve_nqueens(N, row, solution, solutions):
    """Uses backtracking to find all solutions."""
    if row == N:
        solutions.append(solution[:])
        print_solution(solution)
        return

    for col in range(N):
        if is_safe(solution, row, col):
            solution[row] = col
            solve_nqueens(N, row + 1, solution, solutions)
            solution[row] = -1  # Backtrack


def nqueens():
    """Main function to solve the N Queens problem."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solution = [-1] * N  # Initialize the solution array
    solutions = []
    solve_nqueens(N, 0, solution, solutions)


if __name__ == "__main__":
    nqueens()