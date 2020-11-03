/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:32:33 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:32:36 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_clear(t_all *settings)
{
	if (settings->w.ptr != NULL)
		mlx_destroy_window(settings->ptr, settings->w.ptr);
	if (settings->img != NULL)
		free(settings->img);
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
	return (settings->err);
}

void	errors(int er)
{
	if (er == -12)
		write(1, "ERROR: invalid color\n", 21);
	if (er == -11)
		write(1, "ERROR: sprite set but not path\n", 31);
	if (er == -10)
		write(1, "ERROR: invalid color\n", 21);
	if (er == -9)
		write(1, "ERROR: invalid resolution\n", 26);
	if (er == -8)
		write(1, "ERROR: invalid texture path\n", 28);
	if (er == -7)
		write(1, "ERROR: in open textures\n", 24);
	if (er == -6)
		write(1, "ERROR:malloc is dead\n", 21);
	if (er == -5)
		write(1, "ERROR: wrong map\n", 17);
	if (er == -4)
		write(2, "ERROR: no map\n", 14);
	if (er == -3)
		write(1, "ERROR:OoOpS\n", 12);
	if (er == -2)
		write(1, "ERROR: no such file or directory\n", 33);
	if (er == -1)
		write(2, "ERROR: invalid input\n", 21);
	exit(0);
}
