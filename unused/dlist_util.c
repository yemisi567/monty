#include "monty.h"
/**
 * print_dlistint - print dlist
 * @h: head of list
 * Return: num nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *cpy = h;
	size_t count = 0;

	while (cpy != NULL)
	{
		printf("%d\n", cpy->n);
		cpy = cpy->next;
		++count;
	}
	return (count);
}

/**
 * add_dnodeint - add node to start of dlist
 * @head: pointer to start of head
 * @n: value assigned to new node
 * Return: new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;
	return (new);
}

/**
 * add_dnodeint_end - add node to end of list
 * @head: head of list
 * @n: value to add
 * Return: newnode
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tmp;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);
	new->next = NULL;
	new->n = n;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			new->prev = tmp;
			return (new);
		}
		tmp = tmp->next;
	}
	return (new);
}


/**
 * get_dnodeint_at_index - get node at idx
 * @head: head of list
 * @index: index to search
 * Return: node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head)
	{
		if (count == index)
			return (head);
		head = head->next;
		++count;
	}
	return (NULL);
}

/**
 * free_dlistint - free dlist
 * @head: head of list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *cpy;

	while (head)
	{
		cpy = head->next;
		free(head);
		head = cpy;
	}
}
