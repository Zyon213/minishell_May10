#include "minishell.h"


int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

char *ft_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int ft_wordcount(char *str, char *sep)
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

char *ft_subword(char *str, int start, int end)
{
    int i = 0;
    char *word;

    word = malloc(sizeof(char) * ((end - start) + 1));
    if (!word)
        return (NULL);
    while (start < end)
        word[i++] = str[start++];
    word[i] = '\0';
    return (word);
}
//int     ft_split(char *str, char **split, char *sep)
char    **ft_split(char *str, char *sep)
{
    int i = 0;
    int j = 0;
    int index = -1;
    int wc = ft_wordcount(str, sep);
    char **split;
    split = malloc(sizeof(char*) * (wc + 1));
    if (!split)
        return (0);
    if (str == NULL)
        return (0);
    while (i <= ft_strlen(str))
    {
        if ((!ft_strchr(str[i], sep)) && index < 0)
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
