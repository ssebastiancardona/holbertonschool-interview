#!/usr/bin/python3
"""
una forma de resolver el problema de pascual
"""


def pascal_triangle(n):
    """retorna una lista de listas pascuales con el trioangulo de pascual"""
    if n <= 0:
        return []

    list_pascuales = []

    for i in range(n):
        list_pascuales.append([])
        list_pascuales[i].append(1)
        for j in range(1, i):
            list_pascuales[i].append(
                list_pascuales[i - 1][j - 1] + list_pascuales[i - 1][j])
        if i != 0:
            list_pascuales[i].append(1)

    return list_pascuales
    