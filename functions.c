#include "shell.h"

void prompt(){
    static int init = 1;
    if (init)
    {
        system("clear");
        _puts("\n\t****************************************************************\n");
        _puts("\n\t****************  -------------------------- **********************\n");
        _puts("\t*****************|    Simple bash shell     | *******************\n");
        _puts("\n\t***************** -------------------------- **********************\n");
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

int _putchar(char c)
{
    return (write(1,&c,1));
}

void _puts(char *str)
{
    int i = 0;

    while(str[i])
    {
        _putchar(str[i]);
        i++;
    }
}
