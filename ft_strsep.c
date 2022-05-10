#include "minishell.h"

int ft_strchr(char ch, char *sep)
{
    int i = 0;

    while (sep[i])
    {
        if (sep[i] == ch)
            return (1);
        i++;    
    }
    return (0);
}

int ft_chr_first(char *str, char sep)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == sep)
            return (i);
        i++;
    }
    return (-1);
}

int ft_chr_last(char *str, char sep)
{
    int len = ft_strlen(str);

    len--;
    while (len >= 0)
    {
        if (str[len] == sep)
            return (len);
        len--;
    }
    return (-1);
}

int ft_sepcount(char *str, char *sep)
{
    int i = 0;
    int wc = 0;
    int flag = 1;

    while (str[i])
    {
        if ((!ft_strchr(str[i], sep)) && flag == 1)
        {
            wc++;
            flag = 0;
        }
        else if (ft_strchr(str[i], sep))
            flag = 1;
        i++;
    }
    return (wc);
}


char    **ft_strsep(char *str, char *sep)
{
    int i = 0;
    int j = 0;
    int index = -1;
    char **split;
    int wc = ft_sepcount(str, sep);

    split = malloc(sizeof(char*) * (wc + 1));
    if (!split)
        return (NULL);
    while (i <= ft_strlen(str))
    {
        if (!ft_strchr(str[i], sep) && index < 0)
            index = i;
        else if ((ft_strchr(str[i], sep) || i == ft_strlen(str) || str[i] == '\n') && index >= 0)
        {
            split[j++] = ft_subword(str, index, i);
            index = -1;
        }
        i++;
    }
    split[j] = 0;
    return (split);
}

int ft_is_separated(char *str, char *sep)
{
    int i = 0;
    int j;
    while (str[i])
    {
        j = 0;
        while (sep[j])
        {
            if (sep[j] == str[i])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

