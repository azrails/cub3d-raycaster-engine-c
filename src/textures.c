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

int		ft_isnum(char c)
{
	return (c <= '9' && c >= '0');
}

char	*ft_textures(t_all *settings, char *line, int i)
{
	int		end;
	int		k;
	int		fd;
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
	if ((ft_check_name(path, ".xpm")) < 0)
	{
		free(path);
		return (NULL);
	}
	if ((fd = open(path, O_RDONLY)) <= 0)
	{
		free(path);
		settings->err = -8;
		return (NULL);
	}
	close(fd);
	i = ft_skipspc(line, i);
	if (line[i] != '\0')
		return (NULL);
	return (path);
}

int		ft_area(char c, char *line, t_all *settings, int i)
{
	int nbr;
	int count;

	count = 0;
	while (count < 3 && line[i])
	{
		nbr = 0;
		i = ft_skipspc(line, i);
		if (!(ft_isnum(line[i])))
			return (-12);
		while (ft_isnum(line[i]))
		{
			nbr *= 10;
			nbr += line[i] - '0';
			i++;
		}
		if (nbr > 255 || nbr < 0)
			return (-12);
		if (c == 'F')
			settings->config.f[count] = nbr;
		else if (c == 'C')
			settings->config.c[count] = nbr;
		count++;
	}
	i = ft_skipspc(line, i);
	if (line[i] != '\0')
		return (-12);
	settings->val.cf++;
	return (0);
}
