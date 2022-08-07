#ifndef _SHELL_H
#define _SHELL_H

#define SUCCESS 0
#define FAILED  1

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void prompt(void);
void _puts(char *str);
int _putchar(char c);
int built_in_checker(char *cmd);

#endif