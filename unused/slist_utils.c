#include "lists.h"

/**
 * free_list - frees each member of the list
 * @head: head of the list we are freeing
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}

/**
 * _strlen - gets length of string
 * @s: string passed;
 * Return: length of string
 */
unsigned int _strlen(const char *s)
{
	unsigned int i = 0;

	while (s[i])
		i++;

	return (i);
}
/**
 * add_node_end - adds node to end of linked list
 * @head: pointer to pointer to start of the list
 * @str: string to add as member
 * Return: returns location of the new node.
 */
list_t *add_node_end(list_t **head, const char *str)
{

	list_t *new_node, *last;

	new_node = malloc(sizeof(list_t));
	last = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = _strlen(str);
	new_node->next = NULL;
	
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return (new_node);
}
