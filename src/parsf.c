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

static int start_draw(t_all *settings)
{
    if(!(settings->w.ptr = mlx_new_window(settings->ptr, 
            settings->config.res[0], settings->config.res[1], "Cub3D")))
        return(-3);
    if (ft_img(settings) < 0)
        return(-3);
    return(0);
}

void ft_init(int fd, t_all *settings)
{
    settings->config.n = NULL;
    settings->config.w = NULL;
    settings->config.s = NULL;
    settings->config.e = NULL;
    settings->map.count = 0;
    settings->map.lines = NULL;
    settings->position.x = 0;
    settings->position.y = 0;
    ft_init_conf(fd, settings);
    if(!(settings->ptr = mlx_init()))
    {
        settings->err = -3;
        errors(ft_clear(settings));
    }
    ft_check_pars(settings);
    if((settings->err = start_draw(settings)) < 0)//clear settings->w.ptr and some pointers
        errors(ft_clear(settings));
    mlx_loop(settings->ptr);
    //if (flag == 1)
}
void ft_check(char *line, t_all *settings)
{
    int i;

    i = 0;
    i = ft_skiptrash(line, i);
    if (line[i] == 'R')
       settings->err = ft_resolution(line,settings,i + 1);
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
