#include "monty.h"
/**
 * insert_dnodeint_at_index - insert new node at idx
 * @h: head of dlist
 * @idx: index to search for
 * @n: value to insert
 * Return: newnode
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int count = 0;
	dlistint_t *cpy = *h;
	dlistint_t *newnode = NULL;

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (cpy)
	{
		cpy = cpy->next;
		++count;
	}
	if (count < idx)
		return (NULL);
	if (idx == count)
		return (add_dnodeint_end(h, n));
	cpy = *h;
	while (cpy && cpy->next && idx > 0)
	{
		--idx;
		cpy = cpy->next;
	}
	newnode = malloc(sizeof(dlistint_t));
	if (!newnode)
		return (NULL);

	newnode->n = n;
	cpy->prev->next = newnode;
	newnode->prev = cpy->prev;
	cpy->prev = newnode;
	newnode->next = cpy;

	return (newnode);
}


/**
 * delete_dnodeint_at_index - delete node at given index
 * @head: head of list
 * @idx: index given
 * Return: 1 on success
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int idx)
{
	dlistint_t *cpy = *head;
	unsigned int count = 0;

	if (!head)
		return (-1);
	if (!idx)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(cpy);
		return (1);
	}
	while (cpy)
	{
		cpy = cpy->next;
		++count;
	}
	if (idx >= count)
		return (-1);
	cpy = *head;
	while (cpy && cpy->next && idx > 0)
	{
		--idx;
		cpy = cpy->next;
	}

	cpy->prev->next = cpy->next;
	if (cpy->next)
		cpy->next->prev = cpy->prev;
	free(cpy);
	return (1);
}
