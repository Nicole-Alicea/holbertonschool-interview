#!/usr/bin/python3
"""
N-Queens Solver

This script solves the N-Queens problem, which is the challenge of placing N queens 
on an N×N chessboard such that no two queens attack each other.

Usage:
    - N must be an integer greater than or equal to 4.
    - The program prints all possible solutions, one per line, in the format:
      [[row1, col1], [row2, col2], ..., [rowN, colN]]

Functions:
    print_solution(solution): Prints a solution in the required format.
    is_safe(solution, row, col): Checks if placing a queen at (row, col) is safe.
    solve_nqueens(N, row, solution, solutions): Uses backtracking to solve the problem.
    nqueens(): Main function to handle input and solve the problem.
"""

import sys


def print_solution(solution):
    """
    Print the solution in the required format.

    Args:
        solution (list): A list where the index represents the row and the value 
                         represents the column of the queen in that row.
    
    Example:
        If solution = [1, 3, 0, 2], it prints:
        [[0, 1], [1, 3], [2, 0], [3, 2]]
    """
    print([[row, col] for row, col in enumerate(solution)])


def is_safe(solution, row, col):
    """
    Check if placing a queen at (row, col) is safe.

    Args:
        solution (list): Current solution array where index represents the row, 
                         and value represents the column of the queen in that row.
        row (int): The row to place the queen.
        col (int): The column to place the queen.

    Returns:
        bool: True if placing the queen is safe, False otherwise.
    """
    for r, c in enumerate(solution[:row]):
        # Check for conflicts in the same column or on diagonals
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve_nqueens(N, row, solution, solutions):
    """
    Use backtracking to find all solutions for the N-Queens problem.

    Args:
        N (int): The size of the chessboard and the number of queens.
        row (int): The current row to place a queen.
        solution (list): Current state of the solution array.
        solutions (list): List to store all valid solutions.
    """
    if row == N:
        # Found a complete solution; add it to the list and print it
        solutions.append(solution[:])
        print_solution(solution)
        return

    for col in range(N):
        if is_safe(solution, row, col):
            # Place the queen at (row, col)
            solution[row] = col
            # Recur to place the next queen
            solve_nqueens(N, row + 1, solution, solutions)
            # Backtrack: remove the queen
            solution[row] = -1


def nqueens():
    """
    Main function to handle input and solve the N-Queens problem.

    - Validates the input.
    - Initializes the solution array.
    - Calls the backtracking solver.
    
    Exits with:
        1: If the number of arguments is incorrect.
        1: If N is not an integer.
        1: If N is less than 4.
    """
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

    # Initialize the solution array and list to store solutions
    solution = [-1] * N
    solutions = []

    # Solve the N-Queens problem
    solve_nqueens(N, 0, solution, solutions)


# Entry point of the program
if __name__ == "__main__":
    nqueens()
