#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/history.h>
#include <readline/readline.h>


#define MAXCOM 1024
#define MAXLIST 100

#define clear() printf("\033[H\033[J")


void    init_shell();
int     ft_read_line();
void    ft_print_cwd();
int     ft_strlen(char *str);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_subword(char *str, int start, int end);
char    *ft_strcpy(char *dest, char *src);
int     ft_strchr(char ch, char *sep);
int ft_chr_last(char *str, char sep);
int ft_chr_first(char *str, char sep);
int ft_is_separated(char *str, char *sep);
int ft_wordcount(char *str, char *sep);
int ft_wordcount_space(char *str);
char    **ft_split_space(char *str);
int ft_parse_type(char *line, char **args, char **pipe_args);

int ft_is_piped(char *line, char **sep_line);
char    **ft_split(char *str, char *sep);



#endif