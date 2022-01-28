#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - inserta un nuevo nodo
 * @head: puntero
 * @number: numero
 * Return: NULL
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *actual;
	listint_t *nuevo = malloc(sizeof(listint_t));

	if (!nuevo)
		return (NULL);
	nuevo->n = number;

	if (*head == NULL || (*head)->n >= nuevo->n)
	{
		nuevo->next = *head;
		*head = nuevo;
	}
	else
	{
		actual = *head;
		while (actual->next != NULL && actual->next->n < nuevo->n)
		{
			actual = actual->next;
		}
		nuevo->next = actual->next;
		actual->next = nuevo;
	}
	return (nuevo);
}