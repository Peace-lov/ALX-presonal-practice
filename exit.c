#include "shell.h"
/**
 * my_exit - exit a process
 * @com_cache: the command entered
 * @status: stores the command
 * Return: nothing
 */
void my_exit(char *com_cache, int status)
{
        char error_msg[20];

        free_up(com_cache);

        if (com_cache != NULL && com_cache[0] != '\0')
        {
                status = _atoi(com_cache);

                if (status == 0 && com_cache[0] != '0')
                {
                        _strcpy(error_msg, "Exit with error: ");
                        write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
                        write(STDERR_FILENO, com_cache, _strlen(com_cache));
                        write(STDERR_FILENO, "\n", 1);
                        exit(1);
                }
                exit(status);
        }
        exit(0);
}
/**
 * checks_builtin - checks for builtin command
 * @args: the argument count
 * @com_cache: the command entered
 * Return: 1 if it's built-in, 0 otherwise
 */
int checks_builtin(char *args[], char *com_cache)
{
        int status;

        if (_strcmp(args[0], "exit") == 0)
        {
                status = (args[1] != NULL && args[1][0] != '\0');
                my_exit(com_cache, status);
                return (1);
        }

        return (0);
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0')
    {
        return (0);
    }
    else if (*s1 == '\0')
    {
        return (-1);
    }
    else
    {
        return (1);
    }
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 * Return: A integer
 */
int _atoi(char *s)
{

        int c = 0;
        unsigned int ni = 0;
        int min = 1;
        int isi = 0;

        while (s[c])
        {
                if (s[c] == 45)
                {
                        min *= -1;
                }
        while (s[c] >= 48 && s[c] <= 57)
        {
                isi = 1;
                ni = (ni * 10) + (s[c] - '0');
                c++;
        }
        if (isi == 1)
        {
                break;
        }
        c++;
        }
        ni *= min;
        return (ni);
}
/**
 *   _strcpy - Copy a string
 *   @dest: Destination value
 *   @src: Source value
 *   Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
        int i;

        for (i = 0; src[i] != '\0'; i++)
        {
                dest[i] = src[i];
        }
        dest[i++] = '\0';
        return (dest);
}
