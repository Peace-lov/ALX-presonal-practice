#include "shell.h"
/**
 * change_dir - A built in function that changes directories
 * @args: The directory to be entered
 * Return: 0 on success else -1
 */
int change_dir(char *args)
{
        int len;
        char cwd[PATH_MAX], *home, *token;

        if (args == NULL)
        {
                home = _getenv("HOME", environ);
                token = strtok(home, "=");
                token = strtok(NULL, "\n");
                chdir(token);
                return (0);
        }
        if (_strcmp(args, "-") == 0)
        {
                getcwd(cwd, sizeof(cwd));
                len = _strlen(cwd);
                while (cwd[len - 1] != '/')
                {
                        cwd[len - 1] = '\0';
                        len--;
                }
                cwd[len - 1] = '\0';
                chdir(cwd);
                return (0);
        }
        if (chdir(args) == -1)
        {
                perror("chdir error:");
                return (-1);
        }
        return (0);
}
/**
 * _pwd - A function that prints the currend working directory
 * @args: The argument
 * Return: 0 on success else -1
 */
int _pwd(char *args)
{
        char cwd[PATH_MAX];
        int i = 0;

        (void)args;
        (void)environ;
        getcwd(cwd, sizeof(cwd));
        if (cwd == NULL)
        {
                perror("pwd error");
                return (-1);
        }
        while (cwd[i] != '\0')
        {
                _putchar(cwd[i]);
                i++;
        }
        _putchar('\n');
        return (0);
}
/**
 * _printenv - A function that prints the environment
 * @args: The argument
 * Return: 0 on success
 */
int _printenv(char *args)
{
        size_t i = 0, j;
        char *env = NULL;

        (void)args;
        while (environ[i] != NULL)
        {
                env = environ[i];
                j = 0;
                while  (env[j] != '\0')
                {
                        _putchar(env[j]);
                        j++;
                }
                _putchar('\n');
                i++;
        }
        return (0);
}
/**
 * _getenv - A funtion that gets the values of an environment variable
 * @name: name of the environment variable
 * @environ: The string array of environ variables
 * Return: The retrieved value of the env var
 */
char *_getenv(char *name, char **environ)
{
        char *env = NULL, *token;
        int i = 0, j = 0;

        while (environ[i] != NULL)
        {
                env = environ[i];
                while (env[j] == name[j] && env[j] != '=' && name[j] != '\0')
                        j++;
                if (name[j] == '\0')
                {
                        token = strtok(env, "=");
                        token = strtok(NULL, "\n");
                        return (token);
                }
                i++;
        }
        return (NULL);
}
/**
 * get_abs_path - A function that gets the absolute path of a command
 * @cmd: The command
 * @environ: The string array of environ variables
 * Return: The abs path if it exists else NULL
 */
char *get_abs_path(char *cmd, char **environ)
{
        char *path = NULL, *abs_path = NULL, *token = NULL;
        struct stat buffer;

        path = _getenv("PATH", environ);
        token = strtok(path, ":");
        while (token != NULL)
        {
                abs_path = malloc((_strlen(token)) + (_strlen(cmd)) + 2);
                _strcpy(token, abs_path);
                _strcat(abs_path, "/");
                _strcat(abs_path, cmd);
                if (stat(abs_path, &buffer) == 0)
                        return (abs_path);
                free(abs_path);
                token = strtok(NULL, ":");
        }
        if (stat(cmd, &buffer) == 0)
                return (cmd);
        return (NULL);
}
