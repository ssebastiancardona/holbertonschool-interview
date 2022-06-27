#!/usr/bin/python3
'''0. Change comes from within'''


def makeChange(coins, total):
    '''Función que hace cambio para un total dado'''
    if total < 1:
        return 0
    cambio = 0
    coins.sort(reverse=True)
    for coin in coins:
        temp_cambio = int(total / coin)
        total -= (temp_cambio * coin)
        cambio += temp_cambio
        if total == 0:
            return cambio
    if total != 0:
        return -1
