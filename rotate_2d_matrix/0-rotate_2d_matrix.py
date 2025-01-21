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

    # Get the size of the matrix.
    n = len(matrix)

    # Rotate the matrix in-place using layer-by-layer rotation.
    for layer in range(n // 2):
        first = layer
        last = n - 1 - layer
        for i in range(first, last):
            # Offset from the layer's first element.
            offset = i - first

            # Save the top element.
            top = matrix[first][i]

            # Move left to top.
            matrix[first][i] = matrix[last - offset][first]

            # Move bottom to left.
            matrix[last - offset][first] = matrix[last][last - offset]

            # Move right to bottom.
            matrix[last][last - offset] = matrix[i][last]

            # Assign top to right.
            matrix[i][last] = top