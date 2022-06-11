#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void prompt(void);
ssize_t _getline(char **restrict line, size_t *restrict len, FILE *restrict stream);

#endif
