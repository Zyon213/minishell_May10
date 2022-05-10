
#include "minishell.h"

char sep[] = "<>|";


void    init_shell()
{
    clear();
    printf(" >> ");
}


int  ft_read_line(char *str)
{
    char *line = (char*)NULL;

    if (line)
        free(line);
    line = (char*)NULL;

    line = readline("");
    if (line)
    {
        add_history(line);
        ft_strcpy(str, line);
        return (0);
    }
    else
        return (1);
}

void    ft_print_cwd()
{
    char *dir = (char*)NULL;
    size_t bufsize = 1000;

    dir = getcwd(dir, bufsize);
    printf("%s", dir);
}

int ft_is_piped(char *line, char **sep_line)
{
    if (ft_is_separated(line, sep) != 0)
    {
        sep_line = ft_split(line, sep);
        if (sep_line[1] == NULL)
            return (0);
        else
            return (1);
    }
    return (0);
}

int ft_parse_type(char *line, char **args, char **pipe_args)
{
    char *parsed_line[2];
    int parse_type = 0;

    parse_type = ft_is_piped(line, parsed_line);
    int i = 0;
    while (i < 2)
        printf("%s\n",parsed_line[i++]);
/*
    if (parse_type == 1)
    {
       args = ft_split_space(parsed_line[0]);
       pipe_args = ft_split_space(parsed_line[1]);
       printf("yes\n");
       return (1);
    }
    else
    {
        args = ft_split_space(parsed_line[0]);
        printf("no\n");
        return (0);
    }
    */
    return (1);
}
/*
    if (parse_type == 0)
    {
        ft_built_fun(args);
        return (0);
    }
    else
        return (1);

    if (parse_type == 0)
    {
        int i = 0;
        while (i < ft_wordcount_space(parsed_line[0]))
            printf("%s\n", args[i++]);
        return (0);
    }
    else
        return (1);
*/


int main(int argc, char **argv, char **envr)
{
    char line[MAXCOM];
    char *args[MAXLIST];
    char *pipe_args[MAXLIST];
    int i = 0;

    int exec_type = 0;
    init_shell();

    while (1)
    {
        if (ft_read_line(line))
            continue;

        ft_parse_type(line, args, pipe_args);     
    }


    free(args);
    free(line);
    return (0);
}
