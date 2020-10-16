/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:28:50 by wsallei           #+#    #+#             */
/*   Updated: 2020/08/20 16:28:52 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_clear(t_all *settings)
{
    if (settings->config.e)
        free(settings->config.e);
    if (settings->config.w)
        free(settings->config.w);
    if (settings->config.s)
        free(settings->config.s);
    if (settings->config.n)
        free(settings->config.n);
    if (settings->map.lines)
        free(settings->map.lines);
    return(settings->err);
}

void errors(int er)
{
    if (er == -5)
        write(1,"ERROR: wrong map\n", 17);
    if (er == -4)
        write(2,"ERROR: no map\n", 14);
    if (er == -3)
        write(1,"ERROR:OoOpS\n",12);
    if (er == -2)
        write (1, "ERROR: no such file or directory\n",33);
    if (er == -1)
        write(2,"ERROR: invalid input\n",21);

    exit(-1);
}
