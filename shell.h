#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>

#define BUFSIZE  1024
#define DELIMETERS " \n\t\r\a"

extern char **environ;

/**
* struct shell_info - structure to handle
*		shell informations
* @status: shell status
*/
struct shell_info
{
	int status;
};

/**
* struct builtin - structure to handle builtin commands
* @cmd: user command
* @builtin_func: function that handle builtin
*/
typedef struct builtin
{
	char *cmd;
	int (*builtin_func)(char **, char *, char **);
} builtin_t;

/*--shell functions prototypes--*/
/****************************/
/*handle user input*/
char *read_line(void);
char **parse_args(char *lineptr);
char *handle_comment(char *lineptr);

/*handle and execute path*/
int cmd_execute(char **tokens, char *lineptr, char **env);
char *_getenv(char *name);
char *check_cmd_in_PATH(char *cmd);
int fullpath_execution(char **tokens, char *lineptr, int path_var_access_flag);
void cmd_error(char *arg);


/*handle built-in*/
int (*Isbuiltin(char *command))(char **, char *, char **);
int exit_cmd(char **tokens, char *lineptr, char **env);
int handle_env(char **tokens, char *lineptr, char **env);
void exit_error(char *arg);



/*--string functions prototypes--*/
char *_strchr(char *str, char c);
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
void _puts(char *str);

/*--more functions--*/
int _isdigit(char *str);
int _atoi(const char *str);
void _free(int count, ...);


#endif
