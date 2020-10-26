#include "cub3d.h"

static int ft_op_textures(t_all *settings)
{
    int i;

    i = 0;
    if (!(settings->img = malloc(sizeof(t_image) * 4)))
    {
        settings->err = -6;
        errors(ft_clear(settings));
    }
    while (i < 4)
    {
        if(!(settings->img[i] = malloc(sizeof(t_image))))
        {
            settings->err = -6;
            errors(ft_clear(settings));
        }
        settings->img[i]->hg = 0;
        i++;
    }
    if (!(settings->img[0]->iptr = mlx_xpm_file_to_image(settings->ptr, settings->config.n, &settings->img[0]->wd, &settings->img[0]->hg)))
        return (-7);
    settings->img[0]->aptr = mlx_get_data_addr(settings->img[0]->iptr, &settings->img[0]->bp, &settings->img[0]->sl, &settings->img[0]->end);
   if (!(settings->img[1]->iptr = mlx_xpm_file_to_image(settings->ptr, settings->config.s, &settings->img[1]->wd, &settings->img[1]->hg)))
        return (-7);
    settings->img[1]->aptr = mlx_get_data_addr(settings->img[1]->iptr, &settings->img[1]->bp, &settings->img[1]->sl, &settings->img[1]->end);
    if (!(settings->img[2]->iptr = mlx_xpm_file_to_image(settings->ptr, settings->config.w, &settings->img[2]->wd, &settings->img[2]->hg)))
        return (-7);
    settings->img[2]->aptr = mlx_get_data_addr(settings->img[2]->iptr, &settings->img[2]->bp, &settings->img[2]->sl, &settings->img[2]->end);
    if (!(settings->img[3]->iptr = mlx_xpm_file_to_image(settings->ptr, settings->config.e, &settings->img[3]->wd, &settings->img[3]->hg)))
        return (-7);
    settings->img[3]->aptr = mlx_get_data_addr(settings->img[3]->iptr, &settings->img[3]->bp, &settings->img[3]->sl, &settings->img[3]->end);
    return (0);
}

static void ft_plane(t_all *settings,double planex, double planey)
{
    settings->d.px = planex;
    settings->d.py = planey;
}

static void ft_dest(t_all *settings)
{
    if (settings->map.lines[settings->bm.pmx][settings->bm.pmy] == 'N')
    {
        settings->d.x = 0;
        settings->d.y = -1;
        ft_plane(settings, 0.6, 0);
    }
    if (settings->map.lines[settings->bm.pmx][settings->bm.pmy] == 'E')
    {
        settings->d.x = 1;
        settings->d.y = 0;
        ft_plane(settings, 0, 0.6);
    }
    if (settings->map.lines[settings->bm.pmx][settings->bm.pmy]  == 'S')
    {
        settings->d.x = 0;
        settings->d.y = 1;
        ft_plane(settings, -0.6, 0);
    }
    if (settings->map.lines[settings->bm.pmx][settings->bm.pmy] == 'W')
    {
        settings->d.x = -1;
        settings->d.y = 0;
        ft_plane(settings, 0, -0.6);
    }
}

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
                settings->position.x = (double)(j - 1) + 0.5;//check
                settings->position.y = (double)i + 0.5;
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
    settings->bm.pmx = (int)settings->position.x;
    settings->bm.pmy = (int)settings->position.y;
    ft_dest(settings);
    if (settings->config.n == NULL || settings->config.s == NULL 
        || settings->config.w == NULL || settings->config.e == NULL)
    {
            settings->err = -8;
            errors(ft_clear(settings));
    }
    if((settings->err = ft_op_textures(settings)) < 0)
        errors(ft_clear(settings));
}