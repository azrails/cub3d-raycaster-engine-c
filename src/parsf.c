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

void ft_init(int fd, t_all *settings)
{
    settings->config.n = NULL;
    settings->config.w = NULL;
    settings->config.s = NULL;
    settings->config.e = NULL;
    settings->map.count = 0;
    settings->map.lines = NULL;
    ft_init_conf(fd, settings);
    if((settings->err = ft_check_map(settings)) < 0)
        errors(ft_clear(settings));
    int i =0;
    while(settings->map.lines[i])
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
        settings->err = ft_textures(line,settings->config.n, i + 2);
    if (line[i] ==  'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
        settings->err = ft_textures(line,settings->config.s, i + 2);
    if (line[i] ==  'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
        settings->err = ft_textures(line,settings->config.w, i + 2);
    if (line[i] ==  'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
        settings->err = ft_textures(line,settings->config.e, i + 2);
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
    if (err == -1)
        errors(-3);
}