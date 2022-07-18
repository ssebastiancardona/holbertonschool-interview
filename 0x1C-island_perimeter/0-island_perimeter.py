#!/usr/bin/python3
"""
modulo del perimetro
"""


def island_perimeter(grid):
    """ retorna el perimetro de una isla
    """
    cta, maxP = (0, 0)
    len_grid, len_col = (len(grid), len(grid[0]))

    for col in range(len_grid):
        cta += sum(grid[col])
        for row in range(len_col):
            if grid[col][row]:
                if row > 0 and grid[col][row - 1] == 1:
                    maxP += 1

                if col > 0 and grid[col - 1][row] == 1:
                    maxP += 1
    return cta * 4 - maxP * 2
