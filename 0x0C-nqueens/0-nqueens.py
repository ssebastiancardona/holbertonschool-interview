#!/usr/bin/python3
""" commet to """
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

    solution = []

    def nqueens(row, queens, solution):
        """ commet to """
        if (row == queens):
            print(solution)
        else:
            for col in range(queens):
                pos = [row, col]
                if validposition(solution, pos):
                    solution.append(pos)
                    nqueens(row + 1, queens, solution)
                    solution.remove(pos)

    def validposition(solution, position):
        """ commet to """
        for n in solution:
            if n[1] == position[1] or \
                (n[0] - n[1]) == (position[0] - position[1]) or \
                    (n[0] + n[1]) == (position[0] + position[1]):
                return False
        return True

    nqueens(0, kns, solution)