#include "shell.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *buffer = NULL;
    ssize_t len = 0;
    size_t size = 0;
    while((int)len != EOF)
    {
        prompt();
        len = getline(&buffer,&size,stdin);
        printf("%d\n",(int)len);
        _puts(buffer);
    }
    return (SUCCESS);
}