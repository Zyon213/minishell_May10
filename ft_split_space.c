#include "minishell.h"

int ft_wordcount_space(char *str)
{
    int i = 0;
    int wc = 0;
    int flag = 1;
    
    while (str[i])
    {
        if ((str[i] != ' ') && flag == 1)
        {
            wc++;
            flag = 0;
        }
        else if (str[i] == ' ')
            flag = 1;
        i++;
    }
    return (wc);
}

char    **ft_split_space(char *str)
{
    int i = 0;
    int j = 0;
    int index = -1;
    char **split;
    int wc = ft_wordcount_space(str);

    split = malloc(sizeof(char*) * (wc + 1));
    if (!split)
        return (NULL);
    while (i <= ft_strlen(str))
    {
        if ((str[i] != ' ') && index < 0)
            index = i;
        else if (((str[i] == ' ') || i == ft_strlen(str) || str[i] == '\n') && index >= 0)
        {
            split[j++] = ft_subword(str, index, i);
            index = -1;
        }
        i++;
    }
    split[j] = 0;
    return (split);
}
