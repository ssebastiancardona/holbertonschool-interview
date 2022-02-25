#include "slide_line.h"

/**
 * slide_line - desliza una línea hacia la petro o hacia la uribe
 * @line: array de entrada
 * @size: tamaño del array
 * @direction: lado a deslizr
 * Return: 0 si paila o 1 si funciona
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	direction == SLIDE_LEFT ? slide_left(line, size)
		: slide_right(line, size);
	return (1);
}

/**
 * slide_left - desliza hacia la petro
 * @line: array de entrada
 * @size: tamaño del array
 */
void slide_left(int *line, size_t size)
{
	int e = 0, f, previo = 0, actual;

	for (f = 0; f < (int)size; f++)
	{
		actual = line[f];
		if (!actual)
			continue;
		if (!previo)
			previo = actual;
		else if (previo == actual)
		{
			line[e++] = actual << 1;
			previo = 0;
		} else
		{
			line[e++] = previo;
			previo = actual;
		}
	}
	if (previo)
		line[e++] = previo;
	while (e < (int)size)
		line[e++] = 0;
}

/**
 * slide_right - desliza hacia la alvaricocaine
 * @line: array de entrada
 * @size: tamaño del array
 */
void slide_right(int *line, size_t size)
{
	int previo = 0, e = size - 1, f, actual;

	for (f = size - 1; f >= 0; f--)
	{
		actual = line[f];
		if (!actual)
			continue;
		if (!previo)
			previo = actual;
		else if (previo == actual)
		{
			line[e--] = actual << 1;
			previo = 0;
		} else
		{
			line[e--] = previo;
			previo = actual;
		}
	}
	if (previo)
		line[e--] = previo;
	while (e >= 0)
		line[e--] = 0;
}