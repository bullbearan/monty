#include "monty.h"
/**
 * main - check the code
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_line(argv[1]);
	return (0);
}
