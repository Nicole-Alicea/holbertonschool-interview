#!/usr/bin/python3
"""
UTF-8 Validation Module

This module provides a single function `validUTF8`, which checks whether a
given list of integers represents a valid sequence of UTF-8 encoded
characters.

Each integer in the list represents a byte in the data stream, and only the 8
least significant bits of each integer are considered in the validation
process.
"""


def validUTF8(data):
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    # Masks for checking byte patterns
    mask1 = 1 << 7  # 10000000
    mask2 = 1 << 6  # 01000000

    for byte in data:
        # Check if this is the start of a new character
        if num_bytes == 0:
            # Determine the number of bytes for this character
            mask = 1 << 7
            while mask & byte:
                num_bytes += 1
                mask >>= 1

            # 1-byte character
            if num_bytes == 0:
                continue

            # UTF-8 allows characters up to 4 bytes long
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            # Continuation bytes must start with '10'
            if not (byte & mask1 and not (byte & mask2)):
                return False

        # Decrement the byte count for the current character
        num_bytes -= 1

    # If we finished exactly at the end of a character, the data is valid
    return num_bytes == 0
