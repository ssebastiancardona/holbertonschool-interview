#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * insert_node - insert elements on a listint_t list
 * @head: pointer to head of list
 * @number: value
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newN;
	listint_t *Cn;

	/* defining the start of the list */
	Cn = *head;
	/* Allocate Memory to get a new Node*/
	newN = malloc(sizeof(listint_t));

	/** Validate if newNode isn't Null **/
    
	if (newN)
	{
		newN->n = number;
		newN->next = NULL;
		if (*head == NULL || (*head)->n >= newN->n)
		{
			newN->next = *head;
			*head = newNode;
		}
		else
		{
			while (Cn->next && Cn->next->n < newNode->n)
			{
				Cn = Cn->next;
			}
			newNode->next = Cn->next;
			Cn->next = newN;
		}
		return (newN);
	}
	return (NULL);
}