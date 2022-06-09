#include "sort.h"

/**
 * merge - ordenar por fusión
 * @array: Array a ordenar
 * @size: Tamaño de la matriz
 * @m: índice medio
 * @temp: matriz temporal
 * Retorno: Nada.
 */
void merge(int *array, int size, int m, int *temp)
{
	int e, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, m);
	printf("[right]: ");
	print_array(array + m, size - m);
	for (e = 0, j = m, k = 0; k < size; k++)
	{

		if (j == size)
		{
			temp[k] = array[e];
			e++;
		}
		else if (e == m)
		{
			temp[k] = array[j];
			j++;
		}
		else if (array[j] < array[e])
		{
			temp[k] = array[j];
			j++;
		}
		else
		{
			temp[k] = array[e];
			e++;
		}
	}
	for (e = 0; e < size; e++)
	{
		array[e] = temp[e];
	}
	printf("[Done]: ");
	print_array(temp, size);
}


/**
 * merge_main - ordenar por fusión
 * @array: Array a ordenar
 * @size: Tamaño de la matriz
 * @temp: matriz temporal
 * Retorno: Nada.
 */
void merge_main(int *array, size_t size, int *temp)
{
	int me;

	if (size < 2)
		return;
	me = size / 2;
	merge_main(array, me, temp);
	merge_main(array + me,  size - me, temp);
	merge(array, size, me, temp);
}


/**
 * merge_sort - ordenar por fusión
 * @array: Array a ordenar
 * @size: Tamaño de la matriz
 * Retorno: Nada.
 */
void merge_sort(int *array, size_t size)
{
	int *tem = NULL;

	if (!array || size < 2)
		return;
	tem = malloc(sizeof(int) * size);
	if (!tem)
		return;
	merge_main(array, size, tem);
	free(tem);
}
