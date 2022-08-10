#include "shell.h"

/**
 * prompt - prints msg at the startup and every loop
 */
void prompt(void)
{
	static int init = 1;

	if (init)
	{
		system("clear");
		_puts("\n\t******************************");
		_puts("**********************************\n");
		_puts("\n\t****************  ------------");
		_puts("-------------- **********************\n");
		_puts("\t*****************|    Simple bash shell");
		_puts("     | *******************\n");
		_puts("\n\t***************** -----------------");
		_puts("--------- **********************\n");
		_puts("\tDeveloped by Biruk Yonas & Getie \n");
		_puts("\trepo : `https://github.com/buka-pitch/simple_shell`\n\n");
	}
	char dir[256];
	char *buf = "$ ";

	if (getcwd(dir, sizeof(dir)) == NULL)
	perror("getcwd() error");

	init = 0;
	if (isatty(STDIN_FILENO))
	{
		_puts(buf);
		_puts(dir);
		_puts(" >> ");
	}
}

/**
 * _putchar - function puts charachter
 * @c: charachter
 * Return: the int of the writen char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes a string using _putchar
 * @str: string to write
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * fork_excute - excutes the fork function
 * @args: arguments
 * @builtin: int to check builtin
 */
void fork_excute(char *args[], int builtin)
{
	char *path = "", *arg = args[0];
	char *newarg = malloc(strlen(path) + strlen(arg) + 1);

	pid_t pid = fork();

	if (pid == 0)	/* child process */
	{
		strcpy(newarg, path);
		strcat(newarg, arg);
		args[0] = newarg;
		if (builtin == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				_puts("Error: Command not found\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	else     /* parent */
		wait(NULL);
}
