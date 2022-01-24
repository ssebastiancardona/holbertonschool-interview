#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* is_palindrome - checks if singly linked list is a palindrome.
* @head: head
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	listint_t *c, *a;

	if (*head == NULL || (*head)->next == NULL)
	return (1);

	a = *head;
	while (a->next)
	{
		a = a->next;
	}
	c = *head;
	while (a >= c)
	{
		if (c->n == a->n)
		{
			c = c->next;
			a -= 2;
		}
		else
			return (0);
	}
	return (1);
}