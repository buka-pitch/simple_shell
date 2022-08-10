#include "shell.h"

/**
 * isEOF - if end of file detected it will print and exit the shell
 */

void isEOF(void)
{
	_puts("CTRL+D\n");
	_puts("BYE ...\n");
	exit(1);
}


/**
 * built_in_checker - checks for s built in commands int the shell
 * @cmd: pointer for the array of commands or inputed strings
 * */

int built_in_checker(char *cmd, char *cmd2)
{

	if (strcmp(cmd, "exit") == 0)
	{
            return (-1);
	}
	else if (strcmp(cmd, "cd") == 0)
	{
		if(chdir(cmd2) != 0)
		{
			perror("error changing dir :");
		}
		return (1);
	}
	else if (strcmp(cmd, "clear") == 0)
	{
		system("clear");
		return (1);
	} 
	
	else if (strcmp(cmd, "help") == 0)
	{
		_puts("\n\n\t****************************************************************\n");
        _puts("\t***************** |   Simple bash shell    | *******************\n");
        _puts("\t****************************************************************\n");
        _puts("\tDeveloped by Biruk Yonas & Getie \n");
        _puts("\trepo : `https://github.com/buka-pitch/simple_shell`\n\n");
		_puts("\tBuilt-in commands:\n");
		_puts("\t\thelp - display this help\n");
		_puts("\t\tls - display the files in the current directory\n");
		_puts("\t\tmkdir - create directory\n");
		_puts("\t\tpwd - display the current working directory\n");
		_puts("\t\tcd - change directory\n");
		_puts("\t\trm - remove file\n");
		_puts("\t\trmdir - remove directory\n");
		_puts("\t\tenv - display environment\n");
		_puts("\t\tclear - clear the screen\n");
		_puts("\t\texit - exit the shell\n");
		return (1);
	}
	else
	{
		return (0);
	}
}
