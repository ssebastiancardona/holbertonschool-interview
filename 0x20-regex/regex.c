#include "regex.h"

/**
 * regex_match: compara dos cadenas si una tiene una ligera expresión regular
 * @str: cadena regular
 * @patrón: cadena que podría tener expresiones regulares. y/o expresión regular *
 * Devuelve: 1 si "coinciden", 0 si no.
 */
int regex_match(char const *str, char const *pattern)
{
	int tmp = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			tmp = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || tmp);
	}
	return (0);
}