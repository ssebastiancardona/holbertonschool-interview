#include "sort.h"
/**
 * current_digit_sort - ordenar por dígito actual
 * @array: matriz a ordenar
 * @size: tamaño de la matriz
 * @tmp: matriz temporal
 * @exp: dígito del exponente real
 * Retorno: clasificación de matriz
 */
int current_digit_sort(int *array, ssize_t size, int *tmp, long exp)
{
	ssize_t i;
	int au[10] = {0};

	for (i = 0; i < size; i++)
		au[(array[i] / exp) % 10]++, tmp[i] = 0;
	for (i = 1; i < 10; i++)
		au[i] += au[i - 1];
	for (i = size - 1; i >= 0; i--)
		tmp[--au[(array[i] / exp) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	return (0);
}
/**
 * radix_sort - ordena por RADIX
 * @array: matriz a ordenar
 * @size: tamaño de la matriz
 * Retorno: nada
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long expo = 1;
	int *tm, max = INT_MIN;

	if (!array || size < 2)
		return;

	tm = malloc(sizeof(int *) * size);
	if (!tm)
		return;

	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;

	while (max / expo > 0)
	{
		current_digit_sort(array, size, tm, expo);
		print_array(array, size);
		expo *= 10;
	}
	free(tm);
}
