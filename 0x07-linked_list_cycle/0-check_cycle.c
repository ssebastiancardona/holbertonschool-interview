#include "lists.h"
/**
 * check - comprueba si una lista enlazada individualmente tiene un ciclo.
  * @list: lista a revisar.
  * Devuelve: 0 si no hay ciclo, 1 si hay ciclo.
 */
int check_cycle(listint_t *list)
{
	listint_t *pera, *donatello;

	pera = donatello = list;

	while (pera && pera->next)
	{
		pera = pera->next->next;
		donatello = donatello->next;
		if (pera == donatello)
			return (1);
	}
	return (0);
}