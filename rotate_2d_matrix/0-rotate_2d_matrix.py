#!/usr/bin/python3
''' 
Module for rotating a 2D matrix.

This module provides a function to rotate a given 2D matrix 90 degrees clockwise 
in-place. The matrix must be square (n x n dimensions).
'''

def rotate_2d_matrix(matrix):
    ''' 
    Rotates a 2D matrix 90 degrees clockwise.

    Args:
        matrix (list of lists): A square 2D matrix (n x n dimensions) where 
        each inner list represents a row.

    Returns:
        None: The function modifies the input matrix in-place.
    '''
    if not matrix or len(matrix) == 0:
        return  # Return early if the matrix is empty or invalid.

    # Temporary matrix to store a copy of the input matrix.
    matrix0 = [[0, 0, 0],
               [0, 0, 0],
               [0, 0, 0]]
    
    # Copy elements of the original matrix into the temporary matrix.
    for i in range(len(matrix[0])):
        for j in range(len(matrix[0])):
            matrix0[i][j] = matrix[i][j]

    # Rotate the matrix by rearranging elements.
    for i in range(len(matrix[0])):
        p = len(matrix[0]) - 1
        for j in range(len(matrix[0])):
            matrix[i][j] = matrix0[p][i]
            p -= 1
