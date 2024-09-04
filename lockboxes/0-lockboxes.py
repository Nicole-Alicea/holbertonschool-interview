#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.
    Prototype: def canUnlockAll(boxes)
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.

    Args:
        boxes (list of lists): A list where each element is a list of keys
                                contained in a box. The box at index x has
                                keys to other boxes.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)  # Gives us the total number of boxes.
    opened = [False] * n  # Bool list that tracks which boxes have been opened
    opened[0] = True  # True because this is the first box that is unlocked
    stack = [0]  # Initializes the stack with the first box.

    # To explore all of the keys found in the boxes.
    while stack:
        current_box = stack.pop()  # Assigns the last opened box from stack
        for key in boxes[current_box]:  # Checks all of the keys in the box.
            # Check if the key corresponds to a valid unopened box.
            if 0 <= key < n and not opened[key]:
                opened[key] = True  # Here we mark the box as opened.
                stack.append(key)  # Here we add the box to the stack.

    # Return True if all of the boxes have been opened, otherwise False.
    return all(opened)
