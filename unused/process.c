#include <stdio.h>
#include <lists.h>
#include <monty.h>

arg_t args;
/**
 * open_up - opens file passed
 *
 */
void open_up(void)
{
	argsbuf[50];
	args.file = fopen(args.argv[1], "r");//open file and saf FD
	if (args.file)//as long as we have a file
	{
		while (fgets(argsbuf, sizeof(argsbuf), args.file))//read line until argbuf is full
		{
			args.counter++; //we have an argument
			args.line = argsbuf; // save line in struct
			get_func(); // parses for argument.
		}
	}
}
/**
 * read_line - read line and call function
 *
 */
void read_line(void)
{
	char *opfunc = NULL;
	int i = 0;

	opfunc = strtok(args.line, " \n");//get bytecode passed
	if (opcode)
	{
		while (ins[i].opcode && opfunc) //iterate through list of func structs and our opcode function
		{
			if (strcmp(ins[i].opcode && opfunc) == 0)//call if we get a match
			{
				//not sure what args.stack does, was in given struct
				ins[i].f(args.stack, args.line);
				return;
			}
		}
	}
	else if (opfunc == NULL) //error
		return;
	exit(EXIT_FAILURE);
}
