#include "palindrome.h"
/**
 * is_palindrome - comprueba si o no
 * un entero sin signo dado es un palíndromo.
 * @n: es el número a comprobar.
 * Devuelve: 1 si n es un palíndromo y 0 en caso contrario
 */
int is_palindrome(unsigned long n)
{
	unsigned long auxiliar = 0, n0 = n;

	while (n0)
	{
		auxiliar = (auxiliar * 10) + (n0 % 10);
		n0 /= 10;
	}
	return (n == auxiliar ? 1 : 0);
}
