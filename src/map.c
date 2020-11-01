/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:35:34 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:35:36 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_resolution(char *line, t_all *settings, int i)
{
	int nbr;
	int count;

	count = 0;
	while (count < 2)
	{
		nbr = 0;
		i = ft_skiptrash(line, i);
		while (ft_isnum(line[i]))
		{
			nbr *= 10;
			nbr += line[i] - '0';
			i++;
		}
		settings->config.res[count] = nbr;
		count++;
	}
	if (settings->config.res[0] > 1920)
		settings->config.res[0] = 1920;
	if (settings->config.res[1] > 1080)
		settings->config.res[1] = 1080;
	settings->val.res++;
	return (0);
}

int	ft_pars_map(char *line, t_all *settings)
{
	char	**matrix;
	int		it;

	it = 0;
	if (!(matrix = malloc(sizeof(char *) * (settings->map.count + 2))))
		return (-3);
	while (it < settings->map.count)
	{
		matrix[it] = settings->map.lines[it];
		it++;
	}
	matrix[settings->map.count + 1] = NULL;
	if (!(matrix[settings->map.count] = ft_strdup(line)))
		return (-3);
	free(settings->map.lines);
	settings->map.lines = matrix;
	settings->map.count += 1;
	return (0);
}
