/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:32:20 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:32:23 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ft_plane(t_all *settings, double planex, double planey)
{
	settings->d.px = planex;
	settings->d.py = planey;
}

static	void	ft_dest(t_all *settings)
{
	if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == 'N')
	{
		settings->d.x = 0.0;
		settings->d.y = -1.0;
		ft_plane(settings, 0.6, 0.0);
	}
	if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == 'E')
	{
		settings->d.x = 1.0;
		settings->d.y = 0.0;
		ft_plane(settings, 0.0, 0.6);
	}
	if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == 'S')
	{
		settings->d.x = 0.0;
		settings->d.y = 1.0;
		ft_plane(settings, -0.6, 0.0);
	}
	if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == 'W')
	{
		settings->d.x = -1.0;
		settings->d.y = 0.0;
		ft_plane(settings, 0.0, -0.6);
	}
}

static	int		ft_srch_player(t_all *settings)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (settings->map.lines[i])
	{
		j = 0;
		while (settings->map.lines[i][j])
		{
			if (settings->map.lines[i][j] == 'N' || settings->map.lines[i][j] ==
			'S' || settings->map.lines[i][j] == 'W'
			|| settings->map.lines[i][j] == 'E')
			{
				count++;
				settings->position.x = (double)(j - 1) + 0.5;
				settings->position.y = (double)i + 0.5;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static	void	ft_ch(t_all *settings)
{
	int d;

	ft_chspace(settings);
	if (ft_srch_player(settings) != 1)
	{
		settings->err = -5;
		errors(ft_clear(settings));
	}
	if (ft_ns(settings) > 0 && settings->val.s == 0)
	{
		settings->err = -11;
		errors(ft_clear(settings));
	}
	if ((d = ft_check_lines(settings)) < 0)
	{
		settings->err = -5;
		errors(ft_clear(settings));
	}
}

void			ft_check_pars(t_all *settings)
{
	ft_ch(settings);
	settings->bm.pmx = (int)settings->position.x + 1;
	settings->bm.pmy = (int)settings->position.y;
	ft_dest(settings);
	if (settings->config.n == NULL || settings->config.s == NULL
		|| settings->config.w == NULL || settings->config.e == NULL)
	{
		settings->err = -8;
		errors(ft_clear(settings));
	}
	if ((settings->err = ft_op_textures(settings)) < 0)
		errors(ft_clear(settings));
	if (settings->config.res[0] == 0 || settings->config.res[1] == 0)
	{
		settings->err = -9;
		errors(ft_clear(settings));
	}
	if (settings->config.c[0] == -1 || settings->config.c[1] == -1 ||
		settings->config.c[2] == -1 || settings->config.f[0] == -1 ||
		settings->config.f[1] == -1 || settings->config.f[2] == -1)
	{
		settings->err = -10;
		errors(ft_clear(settings));
	}
}
