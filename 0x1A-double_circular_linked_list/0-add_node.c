#include "list.h"
/**
 * create_node - crea un nodo
 * @str: cadena para copiar en el nuevo nodo
 * Retorno: nuevo nodo o NULL
 */
List *create_node(char *str)
{
	List *nod = NULL;

	nod = malloc(sizeof(List));
	if (!nod)
		return (NULL);

	nod->str = strdup(str);
	if (!nod->str)
	{
		free(nod);
		return (NULL);
	}
	node->next = NULL;
	node->prev = NULL;

	return (node);
}
/**
 * add_node_end: agrega un nuevo nodo al final de una lista enlazada circular doble
 * @list: lista a modificar
 * @str: cadena para copiar en el nuevo nodo
 * Retorno: Dirección del nuevo nodo, o NULL en caso de falla
 */
List *add_node_end(List **list, char *str)
{
	List *nod = NULL;

	nod = create_node(str);
	if (!nod)
		return (NULL);

	if (!(*list))
	{
		nod->next = nod;
		nod->prev = nod;
		*list = nod;
	}
	else
	{
		nod->next = (*list);
		nod->prev = (*list)->prev;
		(*list)->prev->next = nod;
		(*list)->prev = nod;
	}
	return (nod);
}
/**
 * add_node_begin - Agrega un nuevo nodo al principio
 * de una lista enlazada circular doble
 * @list: lista a modificar
 * @str: cadena para copiar en el nuevo nodo
 * Retorno: Dirección del nuevo nodo, o NULL en caso de falla
 */
List *add_node_begin(List **list, char *str)
{
	List *nod = NULL;

	nod = create_node(str);
	if (!nod)
		return (NULL);

	if (!(*list))
	{
		nod->next = nod;
		nod->prev = nod;
		*list = nod;
	}
	else
	{
		nod->next = (*list);
		nod->prev = (*list)->prev;
		(*list)->prev->next = nod;
		(*list)->prev = nod;
		*list = nod;
	}

	return (nod);
}
