/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:36:24 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:36:26 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_ischar(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int		ft_skiptrash(char *line, int i)
{
	while (!((ft_isnum(line[i])) || (ft_ischar(line[i]) || (line[i] == '.' &&
	line[i + 1] == '/') || line[i] == '~')) && line[i])
		i++;
	return (i);
}

int		ft_check_name(char *path, char *name)
{
	int	i;
	int	j;

	i = ft_strlen(path);
	j = ft_strlen(name);
	if (i > j)
	{
		while (j >= 0)
		{
			if (path[i] != name[j])
				return (-1);
			i--;
			j--;
		}
	}
	else
		return (-1);
	return (0);
}

int		ft_pathlen(char *line, int i)
{
	while (line[i] && line[i] != ' ')
		i++;
	return (i - 1);
}

char	*ft_calloc(int size, int len)
{
	char	*s;
	int		i;
	int		eps;

	s = NULL;
	i = 0;
	eps = size * len;
	s = malloc(eps);
	while (i++ < eps)
		s[i] = 0;
	return (s);
}
