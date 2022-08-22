#!/usr/bin/python3
""" codigo prigame holbetonshcool """


def isWinner(x, nums):
    """resolviendo el problema"""
    if not nums or x < 1:
        return None
    j = max(nums)
    sieve = [True for _ in range(max(j + 1, 2))]
    for i in range(2, int(pow(j, 0.5)) + 1):
        if not sieve[i]:
            continue
        for j in range(i*i, j + 1, i):
            sieve[j] = False

    sieve[0] = sieve[1] = False
    c = 0
    for i in range(len(sieve)):
        if sieve[i]:
            c += 1
        sieve[i] = c

    player1 = 0
    for j in nums:
        player1 += sieve[j] % 2 == 1
    if player1 * 2 == len(nums):
        return None
    if player1 * 2 > len(nums):
        return "Maria"
    return "Ben"