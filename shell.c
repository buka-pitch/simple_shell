#include "shell.h"

/* Simple shell program to excute bash commands ie. ls, cd, pwd */

/**
 * main - main function to run the program
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv,char **envp)
{
    char *cmd,command[100], *args[20];
    size_t size = 0;
    int builtin = 0, line;
    while (line != EOF)
    {
        prompt();
        line = getline(&cmd, &size, stdin);
	if (line == -1){
		exit(0);
        }
        builtin = built_in_checker(cmd);    /* check if built in commands are available */
        strcpy(command, cmd);
        args[0] = strtok(command, " \n"); 
        for (int i = 1; i < 20; i++)        /* split the command line into arguments */    
        {
            args[i] = strtok(NULL, " \n");
            if (args[i] == NULL){
                break;
            }
        }
        pid_t pid = fork();
        
        if (pid == 0)               /* child process */
        {
            char *path = "";
            char *arg = args[0];
            char *newarg = malloc(strlen(path) + strlen(arg) + 1);
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
	    free(newarg);
        }
        else                        /* parent */
        {
            wait(NULL);
        } 
    }
    return (SUCCESS);
}





