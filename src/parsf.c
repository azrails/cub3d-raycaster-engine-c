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

static void ft_check(char *line, t_all *settings)
{
    int i;

    i = 0;
    if (line[1] == "R")
    {
        
    }
    if (line[1] == )
    if (line[1] == )
    if (line[1] == )
}

void ft_init_conf(int fd, t_all *settings)
{
    char *line;
    int err = 0;

    while(err = (get_next_line(fd, &line) > 0))
    {
        ft_check(line,settings);
        free(line);
        line = NULL;        
    }
    if (err == -1)
        errors(-3);
}