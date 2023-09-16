#include "shell.h"
/**
 * count_tokens - A functions that counts the number of tokens in a string
 * @lp: The string
 * Return: The number of tokens
 */

int count_tokens(char *lp)
{
        int count = 0;
        char *token = NULL;

        token = strtok(lp, " \n");
        while (token != NULL)
        {
                count++;
                token = strtok(NULL, " \n");
        }
        return (count);
}
/**
 * get_func - A function that checks if a command is built in and assigns the
 *            fuction to execute if it is
 * @token: The command
 * Return: A pointer to the assigned function on success else NULL
 */
int (*get_func(char *token))(char *args)
{
        built_ins bi_f[] = {
        {"cd", change_dir},
        {"pwd", _pwd},
        {"env", _printenv},
        {NULL, NULL}
        };
        int i = 0;

        while (bi_f[i].cmd != NULL)
        {
                if (_strcmp(token, bi_f[i].cmd) != 0)
                        i++;
                else
                        return (bi_f[i].f);
        }
        return (NULL);
}
/**
 * _strcat - A function that concatenates a string to another
 * @str1: the string to be increased
 * @str2: contents will be added to str1 end
 * Return: str1 on success
 */
char *_strcat(char *str1, char *str2)
{
        int i, j = 0;

        if (str2 == NULL)
                return (str1);
        for (i = (strlen(str1)); str2[j] != '\0'; i++)
        {
                str1[i] = str2[j];
                j++;
        }
        str1[i] = '\0';
        return (str1);
}
/**
 * tokenize - A function that breaks a string down to indidual tokens
 * @lp2: The string
 * @count: The number of tokens
 * @args: The string array where the string tokens will be stored
 * Return: The string array
 */
char **tokenize(char *lp2, int count, char **args)
{
        char *token = NULL;
        int i = 0;

        if (lp2 == NULL || args == NULL)
                return (NULL);
        token = strtok(lp2, " \n");
        for (i = 0; i < count; i++)
        {
                args[i] = malloc(sizeof(char) * (_strlen(token)));
                if (args[i] == NULL)
                        return (NULL);
                _strcpy(token, args[i]);
                token = strtok(NULL, " \n");
        }
        args[i] = NULL;
        return (args);
}

/**
 * _putchar - puts one character at a time
 * @c: The character to put
 * Return: 1 on success
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
