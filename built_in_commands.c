#include "shell.h"

/***/
int built_in_checker(char *cmd)
{
	if (strcmp(cmd, "exit\n") == 0)
	{

            exit(0);
	}
	 if (strcmp(cmd, "help\n") == 0)
	{
		_puts("Built-in commands:\n");
		_puts("help - display this help\n");
		_puts("ls - display the files in the current directory\n");
		_puts("mkdir - create directory\n");
		_puts("pwd - display the current working directory\n");
		_puts("cd - change directory\n");
		_puts("rm - remove file\n");
		_puts("rmdir - remove directory\n");
		_puts("env - display environment\n");
		_puts("clear - clear the screen\n");
		_puts("exit - exit the shell\n");
		return (1);
	}
	return (0);
}