#include "shell.h"

/**
 * read_comm - reads command given
 * @comm_cache: the memory
 * @comm_bytes: the memory size
 * Return: pointer
 */

ssize_t read_comm(char **comm_cache, size_t *comm_bytes)
{
        ssize_t command = getline(comm_cache, comm_bytes, stdin);

        return (command);
}
