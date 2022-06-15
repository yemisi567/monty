#include <stdio.h>

/**
 *
 *
 *
 */
int main(int ac, char **argv) //args prob not from cmd line but file io
{
	//parse each line for function call
	instruction_t list[] = {
		{'push', push(stack_t **stack_pointer, /*value*/)}
		// push opcode and push function in struct
	}
	//the value passed with a function call gets added to stack struct.
	// but probably this can happen inside push function also.


	//we also have to keep track of line number, could be through count iteration
}

//push function example
// really just add_dnode_int_end from C - 0x17
//probably belongs in own file
stack_t push(stack_t **st_pt, int line_number)
{
	stack_t *tmp;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (!*st_pt)
	{
		new->prev = NULL;
		*st_pt = new;
		return (new);
	}
	tmp = *st_pt;
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
