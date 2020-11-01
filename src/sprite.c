/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:33:54 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:33:56 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int			ft_size_list(t_sprite *list)
{
	int count;

	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

static	t_tbs		*ft_mtxspt(t_all *settings)
{
	int			count;
	t_sprite	*spt;
	t_tbs		*tab;
	int			i;

	i = 0;
	spt = settings->spt;
	count = ft_size_list(settings->spt);
	if (!(tab = malloc(sizeof(t_tbs) * count)))
		return (NULL);
	while (i < count)
	{
		if (spt)
		{
			tab[i].x = spt->x;
			tab[i].y = spt->y;
		}
		spt = spt->next;
		i++;
	}
	settings->ds->count = count;
	return (tab);
}

static	void		ft_value(t_all *settings)
{
	settings->ds->dt = 1.0 / (settings->d.px * settings->d.y
	- settings->d.py * settings->d.x);
	settings->ds->tx = settings->ds->dt * (settings->d.y
	* settings->ds->sx - settings->d.x * settings->ds->sy);
	settings->ds->ty = settings->ds->dt * (settings->d.px
	* settings->ds->sy - settings->d.py * settings->ds->sx);
	settings->ds->ssx = (int)((settings->config.res[0] / 2)
	* (1 + settings->ds->tx / settings->ds->ty));
	settings->ds->h = abs((int)(settings->config.res[1]
	/ settings->ds->ty));
	settings->ds->dsy = ((settings->config.res[1] / 2)
	- settings->ds->h / 2);
	if (settings->ds->dsy < 0)
		settings->ds->dsy = 0;
	settings->ds->dey = settings->ds->h / 2 + settings->config.res[1] / 2;
	if (settings->ds->dey >= settings->config.res[1])
		settings->ds->dey = settings->config.res[1] - 1;
	settings->ds->w = abs((int)(settings->config.res[1] / settings->ds->ty));
	settings->ds->dsx = settings->ds->ssx - settings->ds->w / 2;
	if (settings->ds->dsx < 0)
		settings->ds->dsx = 0;
	settings->ds->dex = settings->ds->w / 2 + settings->ds->ssx;
	if (settings->ds->dex >= settings->config.res[0])
		settings->ds->dex = settings->config.res[0] - 1;
	settings->ds->j = settings->ds->dsx;
}

static	void		ft_psprite(t_all *settings)
{
	settings->ds->sx = settings->ds->tsp[settings->ds->i].x
	- (settings->position.x - 0.5);
	settings->ds->sy = settings->ds->tsp[settings->ds->i].y
	- (settings->position.y - 0.5);
	ft_value(settings);
	while (settings->ds->j < settings->ds->dex)
	{
		settings->ds->tsx = (int)(settings->psp->sl * (settings->ds->j
		- (settings->ds->ssx - settings->ds->w / 2))
			* settings->psp->wd / settings->ds->w) / settings->psp->sl;
		if (settings->ds->ty > 0 && settings->ds->j > 0 && settings->ds->j <
		settings->config.res[0] && settings->ds->ty <
		settings->bm.psp[settings->ds->j])
		{
			settings->ds->y = settings->ds->dsy;
			while (settings->ds->y < settings->ds->dey)
			{
				ft_pxp(settings);
				if (settings->ds->color != 0)
					ft_ppx(settings);
				settings->ds->y++;
			}
		}
		settings->ds->j++;
	}
}

int					ft_dspt(t_all *settings)
{
	if (settings->psp == NULL)
		return (0);
	if (!(settings->ds = malloc(sizeof(t_ds))))
		return (0);
	settings->ds->i = 0;
	if (!(settings->ds->tsp = ft_mtxspt(settings)))
		return (0);
	ft_ssp(settings);
	while (settings->ds->i < settings->ds->count)
	{
		ft_psprite(settings);
		settings->ds->i++;
	}
	free(settings->ds);
	free(settings->bm.psp);
	settings->ds = NULL;
	return (1);
}
