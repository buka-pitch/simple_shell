#include "shell.h"

void prompt(){
    char *buf = "$ ";
    if (isatty(STDIN_FILENO))
        _puts(buf);


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