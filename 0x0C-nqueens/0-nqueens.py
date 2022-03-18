#!/usr/bin/python3
""" commet to """
from sys import argv, exit

if __name__ == "__main__":

    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    queens = argv[1]

    try:
        queens = int(queens)
    except ValueError:
        print("N must be a number")
        exit(1)

    if queens < 4:
        print("N must be at least 4")
        exit(1)

    sol = []

    def nqueens(row, queens, sol):
        """ commet to """
        if (row == queens):
            print(sol)
        else:
            for col in range(queens):
                pos = [row, col]
                if validposition(sol, pos):
                    sol.append(pos)
                    nqueens(row + 1, queens, sol)
                    sol.remove(pos)

    def validposition(solution, position):
        """ commet to """
        for n in solution:
            if n[1] == position[1] or \
                (n[0] - n[1]) == (position[0] - position[1]) or \
                    (n[0] + n[1]) == (position[0] + position[1]):
                return False
        return True

    nqueens(0, queens, sol)
