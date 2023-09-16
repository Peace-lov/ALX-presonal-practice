#include "shell.h"
/**
 * prep_com_args - prepare the command arguments.
 * @com_cache: command entered
 * @args: array to store command arguments.
 * Return: 0 if successful, -1 if an error occurs.
 */

int prep_com_args(char *com_cache, char **args)
{
        char *delim = " ";
        char *token;
        int arg_index = 0;

        token = strtok(com_cache, delim);
        while (token != NULL)
        {
                args[arg_index++] = token;
                token = strtok(NULL, delim);

                if (arg_index >= MAX_ARGUMENTS - 1)
                {
                        perror("Too many command arguments.\n");
                        return (-1);
                }
        }
        args[arg_index] = NULL;

        return (0);
}
