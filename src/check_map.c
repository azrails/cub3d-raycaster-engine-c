/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:34:23 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:34:26 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		ft_len_map(t_all *settings)
{
	int count;

	count = 0;
	while (settings->map.lines[count])
		count++;
	return (count);
}

static	int		tr(t_all *settings, int i, int j)
{
	if (settings->map.lines[i][j] == '0' || settings->map.lines[i][j] ==
		'2' || settings->map.lines[i][j] == 'N' || settings->map.lines[i][j] ==
		'S' || settings->map.lines[i][j] == 'W' || settings->map.lines[i][j] ==
		'E' || settings->map.lines[i][j] == '1')
		return (1);
	return (0);
}

static	int		checker(t_all *settings, int i, int j)
{
	int y;

	if (settings->map.lines[i][j] == '0' || settings->map.lines[i][j] == '2'
		|| settings->map.lines[i][j] == 'N' || settings->map.lines[i][j] == 'S'
		|| settings->map.lines[i][j] == 'W' || settings->map.lines[i][j] == 'E')
	{
		if (!(tr(settings, i, j - 1)) || !(tr(settings, i, j + 1)))
			return (0);
		y = ft_strlen(settings->map.lines[i + 1]);
		if (j > y || (j < y && (!(tr(settings, i + 1, j - 1)
		|| (j < y && (!(tr(settings, i + 1, j + 1))))
		|| (j < y && (!(tr(settings, i + 1, j))))))))
			return (0);
		y = ft_strlen(settings->map.lines[i - 1]);
		if (j > y || (j < y && (!(tr(settings, i - 1, j - 1))
		|| !(tr(settings, i - 1, j + 1)) || !(tr(settings, i - 1, j)))))
			return (0);
	}
	return (1);
}

int				ft_check_lines(t_all *settings)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = ft_len_map(settings);
	while (settings->map.lines[i])
	{
		j = 0;
		y = ft_strlen(settings->map.lines[i]);
		while (settings->map.lines[i][j])
		{
			if ((i == 0 || i == (x - 1) || j == 0 || j == (y - 1))
			&& (settings->map.lines[i][j] != '1'
			&& settings->map.lines[i][j] != ' '))
				return (-3);
			if (!(checker(settings, i, j)))
				return (-3);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_chspace(t_all *settings)
{
	int i;
	int	j;
	int end;
	int	start;
	int	x;

	start = 0;
	i = 0;
	x = ft_len_map(settings);
	while (settings->map.lines[i])
	{
		j = 0;
		while (settings->map.lines[i][j])
		{
			start = ose(settings, i, 0);
			end = ose(settings, i, 1);
			if (settings->map.lines[i][j] == ' ' && j > start && j < end
				&& i != 0 && i != x)
				settings->map.lines[i][j] = '1';
			j++;
		}
		i++;
	}
}
