#!/usr/bin/python3
""" minOperations """


def minOperations(n):
    """
    Calculate the minimum number of operations required to reach exactly 'n'
    'H' characters starting with a single 'H'.

    Args:
        n (int): The target number of 'H' characters to reach.

    Returns:
        int: The minimum number of operations required. If `n` is less than or
        equal to 1 or if `n` is not an integer, return 0.

    The function calculates the minimum operations by breaking `n` down into
    prime factors. For each prime factor `p`, `p` operations are needed (copy
    and paste operations). The process continues until `n` is reduced to 1.
    """
    p = 2
    num = 0

    if type(n) is not int or n <= 1:
        return 0

    while n != 1:
        if n % p == 0:
            n = n / p
            num = num + p
        else:
            p = p + 1

    return int(num)
