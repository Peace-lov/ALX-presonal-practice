#include "shell.h"

/**
 * _strlen - A function
 * @s: string
 * Return: (leng).
 */
int _strlen(char *s)
{
        int leng = 0;

        while (*s != '\0')
        {
                leng++;
                s++;
        }

        return (leng);
}
/**
 * _strchr - function that searches for char
 * @s: the string to search
 * @ch: the charcter to search
 * Return: a pointer
 */
char *_strchr(const char *s, int ch)
{
        if (s == NULL)
        {
                return (NULL);
        }
        for (; *s != '\0'; s++)
        {
                if (*s == ch)
                {
                        return ((char *)s);
                }
        }
        if (ch == '\0')
        {
                return ((char *)s);
        }
        return (NULL);
}
/**
 * _strtok - Function that divides words
 * @s: the string to divide
 * @del: the token to check
 * Return: pointer
 */

char *_strtok(char *s, const char *del)
{
        static char *l_tok = '\0';
        char *tok;

        if (s != NULL)
        {
                l_tok = s;
        }

        if (l_tok == NULL)
        {
                return (NULL);
        }

        tok = l_tok;

        for (tok = l_tok; *l_tok != '\0'; l_tok++)
        {
                if (_strchr(del, *l_tok) != NULL)
                {
                        *l_tok = '\0';
                        l_tok++;
                        return (tok);
                }
        }

        if (*tok == '\0')
        {
                l_tok = NULL;
                return (NULL);
        }

        return (tok);
}
