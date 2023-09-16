#include "shell.h"
/**
 * initialize_buffer - initializes buffer
 * @_ptr: the pointer
 * @_num: pointer to the number
 * Return: 0
 */
int initialize_buffer(char **_ptr, size_t *_num)
{
        if (*_ptr == NULL || *_num == 0)
        {
                *_ptr = (char *)malloc(INIT_BUF_SZ);
                if (*_ptr == NULL)
                        return (-1);
                *_num = INIT_BUF_SZ;
        }
        return (0);
}
/**
 * read_line - reads the line
 * @_ptr: a pointer
 * @_num: pointer to the number
 * Return: the number
 */
ssize_t read_line(char **_ptr, size_t *_num)
{
        size_t a = 0;
        size_t nwsz;
        int bytrd, i;
        char buf[INIT_BUF_SZ];
        char *nwptr;

        while (1)
        {
                bytrd = read(STDIN_FILENO, buf, INIT_BUF_SZ);
                if (bytrd < 0)
                        return (-1);
                if (bytrd == 0)
                {
                        if (a == 0)
                                return (-1);
                }
        }
        for (i = 0; i < bytrd; i++)
        {
                if (buf[i] == '\n')
                {
                        (*_ptr)[a] = '\0';
                        return (a);
                }
                if (a == (*_num - 1))
                {
                        nwsz = *_num * 2;
                        nwptr = (char *)realloc(*_ptr, nwsz);
                }
                if (nwptr == NULL)
                        return (-1);
                *_ptr = nwptr;
                *_num = nwsz;
        }
        (*_ptr)[a++] = buf[i];

        return (a);
}
