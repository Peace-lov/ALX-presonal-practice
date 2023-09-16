#include "shell.h"
/**
 * _execve - A function that creates a child process and execute a command
 * @args: An array of commands
 * @environ: Environment variable
 * Return: 0 if execution was successful else -1
 */
int _execve(char **args, char **environ)
{
        pid_t fid;
        char *abs_path = NULL;
        int status;

        fid = fork();
        if (fid == -1)
        {
                perror("Fork error");
                return (status);
        }
        if (fid == 0)
        {
                abs_path = get_abs_path(args[0], environ);
                if (abs_path != NULL)
                {
                        if (execve(abs_path, args, environ) == -1)
                        {
                                perror("Exec error");
                        }
                }
                else
                {
                        perror("Error");
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                wait(&status);
                free(abs_path);
        }
        return (status);
}
/**
 * main - shell
 * @argc: arguement count
 * @argv: arguement vector
 * @environ: environment
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv, char **environ)
{
        char *prompt = "$ ";
        char *command_cache = NULL;
        size_t command_bytes = 0;
        ssize_t command;
        int count = 0, i = 0;
        int result;
        bool mode_switch = 0;

        while (1 && !mode_switch)
        {
                if (!isatty(STDIN_FILENO))
                        mode_switch = 1;
                if (!mode_switch)
                        write(STDOUT_FILENO, prompt, PROMPT_SIZE);

                command = read_comm(&command_cache, &command_bytes);

                if (command == -1)
                {
                        perror("Read command failed");
                        free_up(command_cache);
                        return (-1);
                }

                if (command_cache[command - 1] == '\n')
                {
                        command_cache[command - 1] = '\0';
                }

                result = exe_command(command_cache);

                if (result == -1)
                {
                        free_up(command_cache);
                        return (-1);
                }
                if (_strcmp(command_cache, "exit") == 0)
                        break;

                argv = malloc(sizeof(char *) * (count + 1));
                if (argv == NULL)
                {
                        perror("Malloc failed");
                        free_up(command_cache);
                        return (-1);
                }

                argv = tokenize(command_cache, count, argv);
                if (argv == NULL)
                {
                        perror("Tokenization failed");
                        free_up(command_cache);
                        free_up(*argv);
                        return (-1);
                }

                if (get_func(argv[0]) != NULL)
                        get_func(argv[0])(argv[1]);
                else
                        _execve(argv, environ);
                i = 0;
                while (argv[i] != NULL)
                {
                        free_up(argv[i]);
                        i++;
                }
                free_up(*argv);
        }
        free_up(command_cache);
        return (0);
}
