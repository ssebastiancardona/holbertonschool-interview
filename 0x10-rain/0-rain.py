#!/usr/bin/python3
"""
lines of code

"""


def rain(walls):
    """
    lines of code
    """
    e = len(walls)
    tot = 0

    for i in range(1, e - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, e):
            right = max(right, walls[j])
        tot = tot + (min(left, right) - walls[i])
    return tot
