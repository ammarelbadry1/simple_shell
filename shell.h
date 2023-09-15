#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE  1024
#define DELIMETERS " \n\t\r\a"



/*shell functions prototypes*/
int main(int argc, char **argv);
char *read_line(void);
char **parse_args(char *line_ptr);
int cmd_execute(char **tokens, char *lineptr);
int fullpath_execution(char **tokens, char *lineptr);
void cmd_error(char *arg);
char *_getenv(char *name);
char *check_cmd_in_PATH(char *cmd);






/*string functions prototypes*/
char *_strchr(char *str, char c);
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);

#endif
