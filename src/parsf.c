/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 22:10:20 by wsallei           #+#    #+#             */
/*   Updated: 2020/08/20 22:10:22 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 void start_draw(t_all *settings)
{
    if (ft_img(settings) < 0)
        {
        settings->err = -3;
        errors(ft_clear(settings));
    }
}

void ft_init(int fd, t_all *settings, int f)
{
    settings->ptr = NULL;
    settings->w.ptr = NULL;
    settings->w.adr = NULL;
    settings->w.iptr = NULL;
    settings->ds = NULL;
    settings->psp = NULL;
    settings->key.mu = 0;
    settings->key.mr = 0;
    settings->key.ml = 0;
    settings->key.md = 0;
    settings->config.res[0] = 0;
    settings->config.res[1] = 0;
    settings->config.n = NULL;
    settings->config.w = NULL;
    settings->config.s = NULL;
    settings->config.e = NULL;
    settings->map.count = 0;
    settings->map.lines = NULL;
    settings->position.x = 0;
    settings->position.y = 0;
    settings->spt = NULL;
    settings->bmp = f;
    if(!(settings->ptr = mlx_init()))
    {
        settings->err = -3;
        errors(ft_clear(settings));
    }
    ft_init_conf(fd, settings);
    ft_check_pars(settings);
    if(!(settings->w.ptr = mlx_new_window(settings->ptr, 
            settings->config.res[0], settings->config.res[1], "Cub3D")))
    {
        settings->err = -5;
        errors(ft_clear(settings));
    }//clear settings->w.ptr and some pointers
    settings->position.x +=1;
    mlx_hook(settings->w.ptr, 2, 0, &ft_key ,settings);
    mlx_hook(settings->w.ptr, 3, 0, &ft_upkey ,settings);
    mlx_hook(settings->w.ptr, 17, 1L << 17, &ft_destr ,settings);
    mlx_loop_hook(settings->ptr, &ft_loop, settings);
    mlx_loop(settings->ptr);
}
void ft_check(char *line, t_all *settings)
{
    int i;

    i = 0;
    i = ft_skiptrash(line, i);
    if (line[i] == 'R' && line[i + 1] == ' ')
       settings->err = ft_resolution(line,settings,i + 1);
    if (line[i] == 'S' && line[i + 1] == ' ')
        settings->err = ft_opstp(settings, line, i + 1);
    if (line[i] ==  'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
        settings->config.n = ft_textures(settings, line, i + 2);
    if (line[i] ==  'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
        settings->config.s = ft_textures(settings, line, i + 2);
    if (line[i] ==  'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
        settings->config.w = ft_textures(settings, line, i + 2);
    if (line[i] ==  'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
        settings->config.e = ft_textures(settings, line, i + 2);
    if ((line[i] == 'F') && line[i + 1] == ' ')
        ft_area('F' ,line,settings, ++i);
    if ((line[i] == 'C') && line[i + 1] == ' ')
        ft_area('C' ,line,settings, ++i);
    if (line[i] == '1' || line[i] == '0' || line[i] == '2')
        ft_pars_map(line, settings);
    if (settings->err < 0)
    {
        free(line);
        errors(ft_clear(settings));
    }
}

 void ft_init_conf(int fd, t_all *settings)
{
    char *line;
    int err;

    err = 0;
    line = NULL;
    while((err = (get_next_line(fd, &line)) > 0))
    {

        ft_check(line,settings);
        free(line);
        line = NULL;
    }
    ft_check(line,settings);
    free(line);
    line = NULL;
    close(fd);
    if (err == -1)
        errors(-3);
}
