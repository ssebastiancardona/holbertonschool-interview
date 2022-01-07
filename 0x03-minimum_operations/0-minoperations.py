#!/usr/bin/python3

""" Min Op"""


def minOperations(n):
    if not isinstance(n, int) or n <= 1:
        return 0
    inicio = 1  # characters in the text file start always in 1
    contador = 0
    while (inicio < n):
        rest = n - inicio

        if (rest % inicio == 0):
            clipBoard = inicio
            inicio += clipBoard
            contador += 2
        else:
            inicio += clipBoard
            contador = contador + 1

    return (contador)


def minimumSpanning(n, inicio, clipBoard, action, opt):
    """
   on
    """

    if inicio == n:
        return opt
    elif inicio > n:
        return 0

    if action == "CopyPaste":
        clipBoard = inicio
        inicio += clipBoard
        opt += 2
    elif action == "Paste":
        inicio += clipBoard
        opt += 1

    copiar = minimumSpanning(n, inicio, clipBoard, "CopyPaste", opt)
    pegar = minimumSpanning(n, inicio, clipBoard, "Paste", opt)

    if (copiar != 0 and pegar != 0 and copiar <= pegar) or (
         copiar != 0 and pegar == 0):
        return copiar
    elif (copiar != 0 and pegar != 0 and pegar <= copiar) or (
         copiar == 0 and pegar != 0):
        return pegar
    else:
        return 0
