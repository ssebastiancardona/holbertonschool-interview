#include "holberton.h"

/**
 * wildcmp - una función para verificar si una cadena es válida
 * @s1: la primera cadena a comparar
 * @s2: la segunda cadena para comparar y tiene el comodín
 * Devuelve: 1 si es cierto 0 en caso contrario
 */
int wildcmp(char *f1, char *f2)
{


	if (*f1 == '\0' && *f2 == '\0')
		return (1);

	if (*f2 == '*')
	{
		if (*(f2 + 1) == '*')
			return (wildcmp(f1, f2 + 1));
	}

	if (*f2 == '*' && *(f2 + 1) != '\0' && *f1 == '\0')
		return (0);

	if (*f2 == *f1)
		return (wildcmp(f1 + 1, f2 + 1));

	if (*f2 == '*')
		return (wildcmp(f1, f2 + 1) || wildcmp(f1 + 1, f2));

	return (0);
}
