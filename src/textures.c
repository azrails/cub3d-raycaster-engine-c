#include"cub3d.h"


int ft_isnum(char c)
{
    return(c <= '9' && c >= '0');
}

int ft_textures(char *line, char *path , int i)
{
    int end;
    int k;
    int fd;

    k = 0;
    i = ft_skiptrash(line , i);
    end = ft_pathLen(line, i);
    if (!(path = ft_calloc(sizeof(char) , (end - i + 1))))
        return(-3);
    while(i <= end)
    {
        path[k] = line[i];
        i++;
        k++;
    }
    if((ft_check_name(path,".xpm")) < 0)
        return (-1);
    if ((fd = open(path, O_RDONLY)) <= 0)
        return (-1);
    close(fd);
    return (0);
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
        if(c == 'F')
            settings->config.f[count] = nbr;
        else if (c == 'C')
            settings->config.c[count] = nbr;
        count++;
    }
    return (0);
}