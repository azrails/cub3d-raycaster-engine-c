/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otext.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:15:15 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 11:15:18 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_val(int fd, t_all *settings)
{
	settings->val.txt = 0;
	settings->val.s = 0;
	settings->val.res = 0;
	settings->val.cf = 0;
	ft_init_conf(fd, settings);
	if (settings->val.s > 1 || settings->val.txt > 4 || settings->val.res > 1
	|| settings->val.cf > 2)
	{
		settings->err = -1;
		errors(ft_clear(settings));
	}
	if (settings->val.cf == 0 || settings->val.cf == 1)
	{
		settings->err = -9;
		errors(ft_clear(settings));
	}
}

int				ft_opstp(t_all *settings, char *line, int i)
{
	int		end;
	char	*tmp;
	int		k;
	t_psp	*psp;

	k = 0;
	i = ft_skiptrash(line, i);
	end = ft_pathlen(line, i);
	if (!(psp = malloc(sizeof(t_psp))))
		return (-6);
	if (!(tmp = ft_calloc(sizeof(char), (end - i + 1))))
		return (-6);
	while (i <= end)
	{
		tmp[k] = line[i];
		i++;
		k++;
	}
	ft_op(settings, tmp, psp);
	settings->val.s++;
	free(tmp);
	return (0);
}

int				ft_in(t_all *settings)
{
	if (!(settings->w.iptr = mlx_new_image(settings->ptr,
	settings->config.res[0], settings->config.res[1])))
		return (-3);
	if (!(settings->w.adr = mlx_get_data_addr(settings->w.iptr,
	&settings->dr.bp, &settings->dr.sl, &settings->dr.end)))
		return (-3);
	if (!(settings->bm.psp = malloc(sizeof(double) * settings->config.res[0])))
		return (-3);
	return (0);
}

static	int		opt(t_all *settings)
{
	if (!(settings->img[0]->iptr = mlx_xpm_file_to_image(settings->ptr,
	settings->config.n, &settings->img[0]->wd, &settings->img[0]->hg)))
		return (-7);
	settings->img[0]->aptr = mlx_get_data_addr(settings->img[0]->iptr,
	&settings->img[0]->bp, &settings->img[0]->sl, &settings->img[0]->end);
	if (!(settings->img[1]->iptr = mlx_xpm_file_to_image(settings->ptr,
	settings->config.s, &settings->img[1]->wd, &settings->img[1]->hg)))
		return (-7);
	settings->img[1]->aptr = mlx_get_data_addr(settings->img[1]->iptr,
	&settings->img[1]->bp, &settings->img[1]->sl, &settings->img[1]->end);
	if (!(settings->img[2]->iptr = mlx_xpm_file_to_image(settings->ptr,
	settings->config.w, &settings->img[2]->wd, &settings->img[2]->hg)))
		return (-7);
	settings->img[2]->aptr = mlx_get_data_addr(settings->img[2]->iptr,
	&settings->img[2]->bp, &settings->img[2]->sl, &settings->img[2]->end);
	if (!(settings->img[3]->iptr = mlx_xpm_file_to_image(settings->ptr,
	settings->config.e, &settings->img[3]->wd, &settings->img[3]->hg)))
		return (-7);
	settings->img[3]->aptr = mlx_get_data_addr(settings->img[3]->iptr,
	&settings->img[3]->bp, &settings->img[3]->sl, &settings->img[3]->end);
	return (0);
}

int				ft_op_textures(t_all *settings)
{
	int i;

	i = 0;
	if (!(settings->img = malloc(sizeof(t_image) * 4)))
	{
		settings->err = -6;
		errors(ft_clear(settings));
	}
	while (i < 4)
	{
		if (!(settings->img[i] = malloc(sizeof(t_image))))
		{
			settings->err = -6;
			errors(ft_clear(settings));
		}
		settings->img[i]->hg = 0;
		i++;
	}
	if((settings->err = opt(settings)) < 0)
		errors(ft_clear(settings));
	return (0);
}
