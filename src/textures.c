/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:34:08 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:34:10 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_isnum(char c)
{
	return (c <= '9' && c >= '0');
}

static	int		che(char *path, t_all *settings)
{
	int		fd;

	if ((ft_check_name(path, ".xpm")) < 0)
	{
		free(path);
		return (0);
	}
	if ((fd = open(path, O_RDONLY)) <= 0)
	{
		free(path);
		settings->err = -8;
		return (0);
	}
	close(fd);
	return (1);
}

char			*ft_textures(t_all *settings, char *line, int i)
{
	int		end;
	int		k;
	char	*path;

	k = 0;
	i = ft_skipspc(line, i);
	end = ft_pathlen(line, i);
	if (!(path = ft_calloc(sizeof(char), (end - i + 1))))
		return (NULL);
	while (i <= end)
	{
		path[k] = line[i];
		i++;
		k++;
	}
	if (!(che(path, settings)))
		return (NULL);
	i = ft_skipspc(line, i);
	if (line[i] != '\0')
		return (NULL);
	return (path);
}

static	int		ch(char *line, int i, int *nbr)
{
	if (!(ft_isnum(line[i])))
		return (-12);
	while (ft_isnum(line[i]))
	{
		if (*nbr <= 10000)
		{
			*nbr *= 10;
			*nbr += line[i] - '0';
		}
		i++;
	}
	if (*nbr > 255 || *nbr < 0)
		return (-12);
	return (i);
}

int				ft_area(char c, char *line, t_all *settings, int i)
{
	int nbr;
	int count;

	count = 0;
	while (count < 3 && line[i])
	{
		nbr = 0;
		if (line[i] == ',')
			i++;
		i = ft_skipspc(line, i);
		if ((i = ch(line, i, &nbr)) == -12)
			return (-12);
		if (c == 'F')
			settings->config.c[count] = nbr;
		else if (c == 'C')
			settings->config.f[count] = nbr;
		i = ft_skipspc(line, i);
		count++;
	}
	i = ft_skipspc(line, i);
	if (line[i] != '\0')
		return (-12);
	settings->val.cf++;
	return (0);
}
