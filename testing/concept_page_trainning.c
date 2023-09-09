#include "main.h"

extern char **environ;

/**
 * main - Entry point of the program
 *
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env __attribute__((unused)))
{
	/**
	 * printing environment variables using environ global variable
	*/
	printf("address of main/env => %p\n", (void *)env);
	printf("address of global/env => %p\n", (void *)environ);
	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}
	/*
	*/

	/**
	 * printing environment variables using main function
	*/
	/*
	unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
	*/

	/**
	 * checking the status of a file
	*/
	/*
    const char *filename = "/bin/ls";
    struct stat file_info;

    if (stat(filename, &file_info) == 0) {
		printf("FILE FOUND\n");
		printf("FILE INFO:\n");
        printf("File size: %lu bytes\n", file_info.st_size);
        printf("File permissions: %o\n", file_info.st_mode & 0777);
    } else {
        perror("FILE NOT FOUND");
    }
	*/

	/**
	 * forking and waiting
	*/
	/*
    pid_t my_pid, parent;

	printf("Here is the point before forking the current process\n");
    my_pid = fork();
    if (my_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (my_pid == 0)
    {
        printf("I am a child process with pid => %d\n", my_pid);
		parent = getppid();
		printf("My parent pid is %d\n", parent);
        sleep(3);
    }
    else
    {
        wait(NULL);
        printf("I am the parent process waited for the child to terminate\n");
		my_pid = getpid();
		printf("I have the pid => %d\n", my_pid);
    }
	*/

	/**
	 * forking
	*/
	/*
    pid_t parent_pid;
    pid_t my_pid;

    printf("Before fork\n");
    my_pid = fork();
    if (my_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("After fork\n");
	printf("Child pid is %d\n", my_pid);
    parent_pid = getpid();
    printf("Parent pid is %d\n", parent_pid);
	*/

	/**
	 * Executing a program using execve system call
	*/
	/*
	char cmd[] = "/usr/bin/ls";
	char *argv[] = {"ls", "-l", NULL};
	char *envp[] = {NULL};

	printf("Before execve\n");
	if (execve(cmd, argv, envp) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	*/

	/**
	 * string tokens
	*/
	/*
	char string[] = "test1/test2/test3/test4/test5";
	char *token;
	token = strtok(string, "/");
	while (token != NULL)
	{
		printf(" %s\n", token);
		token = strtok(NULL, "/");
	}
	*/

	/**
	 * shell interactive mode example
	*/
	/*
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (nread != EOF) {
		write(STDOUT_FILENO, "$ ", 2);
		nread = getline(&line, &len, stdin);
		write(STDOUT_FILENO, line, nread);
	}
	free(line);
	exit(EXIT_SUCCESS);
	*/
	return (0);
}