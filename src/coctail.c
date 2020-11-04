/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coctail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:18:59 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/04 19:19:01 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			start_draw(t_all *settings)
{
	if (ft_img(settings) < 0)
	{
		settings->err = -3;
		errors(ft_clear(settings));
	}
}

static	void	init(int fd, t_all *settings)
{
	settings->img = NULL;
	settings->ptr = NULL;
	settings->w.ptr = NULL;
	settings->w.adr = NULL;
	settings->w.iptr = NULL;
	settings->ds = NULL;
	settings->psp = NULL;
	settings->config.n = NULL;
	settings->config.w = NULL;
	settings->config.s = NULL;
	settings->config.e = NULL;
	settings->spt = NULL;
	settings->map.lines = NULL;
	ft_start(fd, settings);
}

void			ft_init(int fd, t_all *settings, int f)
{
	settings->config.c[0] = -1;
	settings->config.c[1] = -1;
	settings->config.c[2] = -1;
	settings->config.f[0] = -1;
	settings->config.f[1] = -1;
	settings->config.f[2] = -1;
	settings->key.mu = 0;
	settings->key.mr = 0;
	settings->key.ml = 0;
	settings->key.md = 0;
	settings->config.res[0] = 0;
	settings->config.res[1] = 0;
	settings->map.count = 0;
	settings->position.x = 0;
	settings->position.y = 0;
	settings->bmp = f;
	settings->err = 0;
	settings->m = 0;
	settings->aftm = 0;
	init(fd, settings);
}

static	int		cycle(int i, int *end, char *tmp, char *line)
{
	int		k;

	k = 0;
	while (i <= *end)
	{
		tmp[k] = line[i];
		i++;
		k++;
	}
	return (i);
}

int				ft_opstp(t_all *settings, char *line, int i)
{
	int		end;
	char	*tmp;
	t_psp	*psp;

	i = ft_skipspc(line, i);
	end = ft_pathlen(line, i);
	if (!(psp = malloc(sizeof(t_psp))))
		return (-6);
	if (!(tmp = ft_calloc(sizeof(char), (end - i + 1))))
	{
		free(psp);
		return (-6);
	}
	i = cycle(i, &end, tmp, line);
	ft_op(settings, tmp, psp);
	settings->val.s++;
	free(tmp);
	i = ft_skipspc(line, i);
	if (line[i] != '\0')
		return (-8);
	return (0);
}
