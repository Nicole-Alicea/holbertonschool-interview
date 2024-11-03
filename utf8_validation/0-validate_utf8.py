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
    """
    Validates if a list of integers represents a valid UTF-8 encoded character
    sequence.

    UTF-8 encoding allows characters to be represented by 1 to 4 bytes. This
    function verifies that each byte in the data follows the UTF-8 encoding
    rules:

    - A single-byte character (0xxxxxxx) starts with 0 and has no
    continuation bytes.
    - A two-byte character (110xxxxx 10xxxxxx) starts with 110 and is
    followed by one continuation byte.
    - A three-byte character (1110xxxx 10xxxxxx 10xxxxxx) starts with 1110 and
    is followed by two continuation bytes.
    - A four-byte character (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx) starts with
    11110 and is followed by three continuation bytes.

    Parameters:
    ----------
    data : List[int]
        A list of integers where each integer represents a byte of data. Only
        the 8 least significant bits of each integer are used.

    Returns:
    -------
    bool
        True if `data` represents a valid UTF-8 encoding, False otherwise.
    """
    successive_10 = 0  # Counter for expected continuation bytes
    for b in data:
        # Convert integer to 8-bit binary, padded with zeros if necessary
        b = bin(b).replace('0b', '').rjust(8, '0')

        # Check if we're in the middle of validating continuation bytes
        if successive_10 != 0:
            successive_10 -= 1
            # Continuation bytes must start with "10"
            if not b.startswith('10'):
                return False
        elif b[0] == '1':  # Start of a multi-byte character
            successive_10 = len(b.split('0')[0]) - 1
            # A maximum of 4-byte characters are allowed in UTF-8
            if successive_10 < 1 or successive_10 > 3:
                return False
    return successive_10 == 0
