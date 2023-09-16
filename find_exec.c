#include "shell.h"

/**
 * check_exec - Find the executable part of the command.
 * @com_cache: The command input.
 * Return: Pointer to the executable part of the command.
 */
char *check_exec(char *com_cache)
{
        char *delim = " ";

        return (strtok(com_cache, delim));
}
