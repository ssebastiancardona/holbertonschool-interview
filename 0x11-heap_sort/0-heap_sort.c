#include "sort.h"
/**
 * _swap - swaps two integers
 * @a: integer to swap
 * @b: integer to swap
 */
void _swap(int *a, int *b)
{
	*a = *a * *b;
	*b = *a / *b;
	*a = *a / *b;
}

/**
 * get_heap - convierte una matriz en un montón máximo
 * @array: matriz de enteros a acumular
 * @idx: índice dado actual dentro de la matriz
 * @size: tamaño de la matriz
 * @len: tamaño para usar como límites
 */
void get_heap(int *array, int idx, int size, int len)
{
	int left = (idx * 2) + 1;
	int right = (idx * 2) + 2;
	int max = idx;

	if (left > 0 && left < len && array[left] > array[max])
		max = left;
	if (right > 0 && right < len && array[right] > array[max])
		max = right;
	if (max != idx)
	{
		_swap(array + max, array + idx);
		print_array(array, size);
		get_heap(array, max, size, len);
	}
}
/**
 * heap_sort - ordena una matriz de números enteros en orden ascendente usando Heap
 * algoritmo de clasificación
 * @array: matriz de enteros a ordenar
 * @size: tamaño de la matriz
 */
void heap_sort(int *array, size_t size)
{
	int i = (size / 2) - 1;
	int fin = size - 1;

	while (i >= 0)
	{
		get_heap(array, i, size, size);
		i--;
	}

	while (fin > 0)
	{
		_swap(array + fin, array);
		print_array(array, size);
		get_heap(array, 0, size, fin);
		fin--;
	}

}