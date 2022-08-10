#include "shell.h"

/* Simple shell program to excute bash commands ie. ls, cd, pwd */

/**
 * _getline - function to read input from user
 * @cmd: command
 * @size: size
 * Return: cmd
 */

char *_getline(char *cmd, size_t size)
{
	int line;

	line = getline(&cmd, &size, stdin);
	if (line == EOF)
		isEOF();
	if (line == -1)
		exit(1);
	return (cmd);
}


/**
 * main - main function to run the program
 * @argc: number of arguments
 * @argv: command line arguments
 * @envp: environment variables
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv, char **envp)
{
	char *cmd, command[100], *args[20];
	size_t size = 0;
	int builtin = 0;

	while (1)
	{
		prompt();
		cmd = _getline(cmd, size);
		strcpy(command, cmd);
		args[0] = strtok(command, " \n");
		/* split the command line into arguments */
		for (int i = 1; i < 20; i++)
		{
			args[i] = strtok(NULL, " \n");
			if (args[i] == NULL)
			{
				break;
			}
		}

		/* check if built in commands are available */
		builtin = built_in_checker(args[0], args[1]);
		fork_excute(args, builtin);
	}
	free(args);
	return (SUCCESS);
}

