#include"cub3d.h"


int ft_isnum(char c)
{
    return(c <= '9' && c >= '0');
}

char *ft_textures(t_all *settings, char *line, int i)
{
    int end;
    int k;
    int fd;
    char *path;

    k = 0;
    i = ft_skiptrash(line , i);
    end = ft_pathLen(line, i);
    if (!(path = ft_calloc(sizeof(char) , (end - i + 1))))
        return(NULL);
    while(i <= end)
    {
        path[k] = line[i];
        i++;
        k++;
    }
    if((ft_check_name(path,".xpm")) < 0)
        return (NULL);
    if ((fd = open(path, O_RDONLY)) <= 0)
    {
        settings->err = -8;
        return (NULL);
    }
    close(fd);
    return (path);
}

int ft_area(char c ,char *line, t_all *settings, int i)
{
    int nbr;
    int count;

    count = 0;
    while(count < 3)
    {
        nbr = 0;
        i = ft_skiptrash(line,i);
        while(ft_isnum(line[i]))
        {
            nbr *=10;
            nbr += line[i] - '0';
            i++;
        }
        if (nbr > 255 || nbr < 0)
            nbr = 0;
        if(c == 'F')
            settings->config.f[count] = nbr;
        else if (c == 'C')
            settings->config.c[count] = nbr;
        count++;
    }
    return (0);
}