#include "shell.h"
/**
 * free_up - cleans up the memory allocated
 * @comm_cache: the memory to free
 * Return: nothing
 */
void free_up(char *comm_cache)
{
        free(comm_cache);
}
