#!/usr/bin/python3
"""
Rainwater Trapping Algorithm

This script contains a function `rain` that calculates the amount of trapped 
rainwater between walls of different heights, represented as an array. 

The algorithm iterates through the walls array to determine the water that can 
be trapped above each wall using the heights of the tallest walls to the left 
and right of the current wall.
"""


def rain(walls):
    """
    Calculate the amount of water that can be trapped between walls.

    Args:
        walls (list of int): A list of non-negative integers representing 
        the height of walls.

    Returns:
        int: The total amount of trapped water.

    Algorithm:
        - For each wall (excluding the first and last walls):
            1. Determine the tallest wall to the left of the current wall.
            2. Determine the tallest wall to the right of the current wall.
            3. Calculate the water trapped at the current wall as:
               water_at_wall = min(left_max, right_max) - height_of_wall
        - Accumulate the water trapped at all walls.
    """
    n = len(walls)
    if n <= 0:
        return 0
    water = 0

    for i in range(1, n - 1):
        # Find the tallest wall to the left of the current wall
        p1 = walls[i]
        for j in range(i):
            p1 = max(p1, walls[j])
        
        # Find the tallest wall to the right of the current wall
        p2 = walls[i]
        for j in range(i + 1, n):
            p2 = max(p2, walls[j])
        
        # Calculate trapped water at the current wall
        x = min(p1, p2)
        water += x - walls[i]
    
    return water
