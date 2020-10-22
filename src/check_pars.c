#include "cub3d.h"

static int ft_srch_player(t_all *settings)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while(settings->map.lines[i])
    {
        j = 0;
        while(settings->map.lines[i][j])
        {
            if(settings->map.lines[i][j] == 'N' || settings->map.lines[i][j] == 'S' 
                || settings->map.lines[i][j] == 'W' || settings->map.lines[i][j] == 'E')
            {
                count++;
                settings->position.x = i;
                settings->position.y = j;
            }
            j++;
        }
        i++;
    }
    return(count);
}

void ft_check_pars(t_all *settings)
{
    int d;
    if(ft_srch_player(settings) != 1)
    {
        settings->err = -5;
        errors(ft_clear(settings));
    }
    if((d = ft_check_lines(settings)) < 0)
    {
        settings->err = -5;
        errors(ft_clear(settings));
    }
}