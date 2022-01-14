#include "sandpiles.h"
#include <stdio.h>

/**
 * impg - imprime una cuadrícula de 3x3
 * @grid: arreglo 3x3 de enteros
 */
static void impg(int grid[3][3])
{
	int i, e;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (e = 0; e < 3; e++)
		{
			if (e)
				printf(" ");
			printf("%d", grid[i][e]);
		}
		printf("\n");
	}
}
/**
 * fixt - Maneja cuando una grilla es inestable
 * @grid: arreglo 3x3 de enteros
 * @i: índice, filas
 * @j: índice, columnas
 * Devuelve: 1 si la red aún es inestable, 0 si es estable
 */
int fixt(int grid[3][3], int i, int j)
{
	int ines_table = 0;

	grid[i][j] -= 4;
	if (i + 1 >= 0 && i + 1 <= 2)
	{
		grid[i + 1][j]++;
		if (grid[i + 1][j] > 3)
			ines_table++;
	}
	if (j + 1 >= 0 && j + 1 <= 2)
	{
		grid[i][j + 1]++;
		if (grid[i][j + 1] > 3)
			ines_table++;
	}
	if (i - 1 >= 0 && j - 1 <= 2)
	{
		grid[i - 1][j]++;
		if (grid[i - 1][j] > 3)
			ines_table++;
	}
	if (j - 1 >= 0 && j - 1 <= 2)
	{
		grid[i][j - 1]++;
		if (grid[i][j - 1] > 3)
			ines_table++;
	}
	return (ines_table);
}
/**
 * ciclog: hace un bucle en la cuadrícula siempre que la cuadrícula sea inestable
 * @grid: matriz 3x3 de enteros, cuadrícula para verificar
 */
void ciclog(int grid[3][3])
{
	int i, j, ines = 1, t = 0;
	int copiagrilla[3][3];

	while (ines)
	{

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				copiagrilla[i][j] = grid[i][j];
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (copiagrilla[i][j] > 3)
				{
					t = fixt(grid, i, j);
				}
			}
		}
		if (!t || (!t && i == 0))
			ines = 0;
		else
			impg(grid);
	}
}

/**
 * sandpiles_sum - calcula la suma de dos pilas de arena
 * Al final de la función, grid1 debe ser estable.
 * @grid1: matriz doble estable
 * @grid2: matriz doble estable
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, t, o = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			t = grid1[i][j];
			grid1[i][j] = t + grid2[i][j];
			if (grid1[i][j] > 3)
			{
				o = 1;
			}
		}
	}
	if (o)
	{
		impg(grid1);
		ciclog(grid1);
	}
	else
		ciclog(grid1);
}