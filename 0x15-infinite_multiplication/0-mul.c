#include "holberton.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_num - imprime una matriz de enteros como un número
 * @nums3: matriz de enteros
 * @size: tamaño de la matriz de enteros
 */
void print_num(int *nums3, int size)
{
	int n = 0;

	if (!nums3 && !size)
	{
		printf("0\n");
		exit(0);
	}
	while (nums3[i] == 0)
		n++;
	for (; n < size; n++)
	{
		printf("%d", nums3[i]);
	}
	printf("\n");
}

/**
 * multiplicar - multiplica dos números grandes
 * @nums1: representación de cadena de int grande
 * @nums2: representación de cadena de int grande
 * Retorno: 1 en caso de éxito, 0 en caso de error
 */
int multiply(char *nums1, char *nums2)
{
	int n, j;
	int len1, len2, sum, n1, n2 = 0;
	int *nums3;

	len1 = strlen(nums1);
	len2 = strlen(nums2);

	nums3 = calloc(len1 + len2, sizeof(len1 + len2));
	if (!nums3)
		return (0);

	for (n = len1 - 1; n >= 0; n--)
	{
		n1 = nums1[n] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = nums2[j] - '0';
			sum = (n1 * n2) + nums3[i + j + 1];
			nums3[n + j] += sum / 10;
			nums3[n + j + 1] = sum % 10;
		}
	}
	print_num(nums3, len1 + len2);
	free(nums3);
	return (1);
}

/**
 * principal - Punto de entrada: multiplica dos números positivos
 * @argc: número de argumentos pasados
 * @argv: argumentos pasados ​​(enteros)
 * Retorno: 0 en caso de éxito, 1 en caso de error
 */
int main(int argc, char **argv)
{
	int n, j = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (n = 1; argv[n]; n++)
		for (j = 0; argv[n][j]; j++)
			if (argv[n][j] < '0' || argv[n][j] > '9')
			{
				printf("Error\n");
				exit(98);

			}

	if (*argv[1] == '0' || *argv[2] == '0')
		print_num(NULL, 0);
	if (!multiply(argv[1], argv[2]))
		return (1);
	return (0);
}