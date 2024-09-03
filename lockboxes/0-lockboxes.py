#!/usr/bin/python3

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
    opened = [False] * n  # A boolean list that will track which boxes have been opened.
    opened[0] = True  # The first box is unlocked, therefor the box at index 0 is equal to True.
    stack = [0]  # Initializes the stack with the first box.

    # To explore all of the keys found in the boxes.
    while stack:
        current_box = stack.pop()  # This will assign the last opened box from the stack to current_box.
        for key in boxes[current_box]:  # Will check all of the keys in the current box.
            # Check if the key corresponds to a valid unopened box.
            if 0 <= key < n and not opened[key]:
                opened[key] = True  # Here we mark the box as opened.
                stack.append(key)  # Here we add the box to the stack.

    # Return True if all of the boxes have been opened, otherwise False.
    return all(opened)
