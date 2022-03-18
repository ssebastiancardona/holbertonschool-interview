#!/usr/bin/python3
""" module docs """
from sys import argv, exit

if __name__ == "__main__":

    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    kns = argv[1]

    try:
        kns = int(kns)
    except ValueError:
        print("N must be a number")
        exit(1)

    if kns < 4:
        print("N must be at least 4")
        exit(1)

    sol = []

    def nqueens(row, queens, sol):
        """ method docs """
        if (row == queens):
            print(sol)
        else:
            for col in range(queens):
                p = [row, col]
                if validposition(sol, p):
                    sol.append(p)
                    nqueens(row + 1, queens, sol)
                    sol.remove(p)

    def validposition(sol, pos):
        """ method docs """
        for n in sol:
            if n[1] == pos[1] or \
                (n[0] - n[1]) == (pos[0] - pos[1]) or \
                    (n[0] + n[1]) == (pos[0] + pos[1]):
                return False
        return True

    nqueens(0, kns, sol)