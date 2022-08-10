#include "shell.h"

/* Simple shell program to excute bash commands ie. ls, cd, pwd */

/**
 * main - main function to run the program
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: 0 on success, 1 on failure
 */
char *_getline(char *cmd, size_t size){
    int line;
	line = getline(&cmd, &size, stdin);
	if (line == EOF)
		isEOF();

	if (line == -1){
		exit(1);
	}
    return (cmd);
}

int main(int argc, char **argv,char **envp)
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
        for (int i = 1; i < 20; i++)        /* split the command line into arguments */
        {
            args[i] = strtok(NULL, " \n");
            if (args[i] == NULL){
                break;
            }
        }
        char *path = "", *arg = args[0],  *newarg = malloc(strlen(path) + strlen(arg) + 1);
	    builtin = built_in_checker(args[0],args[1]);	/* check if built in commands are available */
        pid_t pid = fork();
        if (pid == 0)               /* child process */
        {
            strcpy(newarg, path);
            strcat(newarg, arg);
            args[0] = newarg;
            if (builtin == 0)       /* if built in commands are not available */
            {
                if (execvp(args[0], args) == -1)
                {
                    _puts("Error: Command not found\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
        else     /* parent */
        {
            wait(NULL);
        }
	}
	free(args);
	return (SUCCESS);
}

