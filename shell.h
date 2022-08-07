#ifndef _SHELL_H
#define _SHELL_H

#define SUCCESS 0
#define FAILED  1

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void prompt(void);
void _puts(char *str);
int _putchar(char c);

#endif