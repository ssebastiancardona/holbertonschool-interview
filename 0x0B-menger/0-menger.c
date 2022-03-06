#include "menger.h"

/**
 * menger - draws a 2D menger sponge
 * @level: number of levels to draw
 * Return: nothing
 */
void menger(int level)
{
	int colum, fila, tam;

	if (level < 0)
		return;
	tam = pow(3, level);
	for (colum = 0; colum < tam; colum++)
	{
		for (fila = 0; fila < tam; fila++)
			printf("%c", hash_space(colum, fila));
		putchar(10);
	}
}

/**
 * hash_space - gets a character
 * @colum: column
 * @fila: row
 * Return: '#' or ' '
 */
char hash_space(int colum, int fila)
{
	while (colum && fila)
	{
		if (colum % 3 == 1 && fila % 3 == 1)
			return (' ');
		colum /= 3, fila /= 3;
	}
	return ('#');
}