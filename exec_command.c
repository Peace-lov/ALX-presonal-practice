#include "shell.h"
/**
 * exe_child - function that executes the child process
 * @av: pointer to the argument count
 * Return: 0 if successful
 */
int exe_child(char *av[])
{
        char* execute;
        int exec;

        execute = check_exec(av[0]);

        if (execute == NULL)
        {
                perror("Executable not found.\n");
                return (-1);
        }

        exec = execve(execute, av, NULL);
        if (exec == -1)
        {
                perror("Execve failed");
                return (-1);
        }

        return (0);
}
/**
 * exe_parent - function to keep parent process on hold until child execute
 * @pid: the child process id
 * Return: 0 if successful, -1 otherwise
 */
int exe_parent(pid_t pid)
{
        int status;
        int wait_res = waitpid(pid, &status, 0);

        if (wait_res == -1)
        {
                perror("waitpid failed");
                return (-1);
        }

        return (0);
}
/**
 * exe_command - function to execute the command entered
 * @comm_cache: command entered by users
 * Return: the pid of the calling process
 */

int exe_command(char *comm_cache)
{
        char *args[MAX_ARGUMENTS];
        pid_t pid;

        if (prep_com_args(comm_cache, args) == -1)
                return (-1);
        if (checks_builtin(args, comm_cache))
        {
                return (0);
        }

        pid = fork();

        if (pid == -1)
        {
                perror("Fork failed");
                return (-1);
        }
        else if (pid == 0)
        {
                return (exe_child(args));
        }
        else
        {
                return (exe_parent(pid));
        }
}
