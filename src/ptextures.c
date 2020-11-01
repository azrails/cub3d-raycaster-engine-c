/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptextures.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:33:40 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:33:43 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void		ft_pimage(t_all *settings, t_image *img)
{
	int y;
	int texy;

	y = settings->col.y * img->sl - settings->config.res[1]
	* img->sl / 2 + settings->dr.h * img->sl / 2;
	texy = ((y * img->hg) / settings->dr.h) / img->sl;
	settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x
	* settings->dr.bp / 8] =
		img->aptr[texy * img->sl + settings->col.texx * (img->bp / 8)];
	settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x
	* settings->dr.bp / 8 + 1] =
		img->aptr[texy * img->sl + settings->col.texx * (img->bp / 8) + 1];
	settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x
	* settings->dr.bp / 8 + 2] =
		img->aptr[texy * img->sl + settings->col.texx * (img->bp / 8) + 2];
}

static	void		ft_pcol(t_all *settings, t_image *img)
{
	int ym;

	if (settings->col.ys < settings->col.ye)
	{
		settings->col.y = settings->col.ys;
		ym = settings->col.ye;
	}
	else
	{
		settings->col.y = settings->col.ye;
		ym = settings->col.ys;
	}
	if (settings->col.y >= 0)
	{
		while (settings->col.y < ym)
		{
			ft_pimage(settings, img);
			settings->col.y++;
		}
	}
}

static	void		ft_dside(t_all *settings, double wx)
{
	int			texx;
	t_image		*img;

	img = settings->img[3];
	if (settings->bm.side == 1)
		img = settings->img[2];
	else if (settings->bm.side == 2)
		img = settings->img[1];
	else if (settings->bm.side == 3)
		img = settings->img[0];
	texx = (int)(wx * (double)img->wd);
	if ((settings->bm.side == 0 || settings->bm.side == 1)
	&& settings->bm.ray_x > 0)
		texx = img->wd - texx - 1;
	if ((settings->bm.side == 2 || settings->bm.side == 3)
	&& settings->bm.ray_y < 0)
		texx = img->wd - texx - 1;
	settings->col.ys = settings->dr.de;
	settings->col.ye = settings->dr.ds;
	settings->col.texx = texx;
	ft_pcol(settings, img);
}

static	void		ft_pcolor(t_all *settings, int cf)
{
	int ym;

	if (settings->col.ys < settings->col.ye)
	{
		settings->col.y = settings->col.ys;
		ym = settings->col.ye;
	}
	else
	{
		settings->col.y = settings->col.ye;
		ym = settings->col.ys;
	}
	if (settings->col.y >= 0)
	{
		while (settings->col.y < ym)
		{
			ft_pcl(settings, cf);
			settings->col.y++;
		}
	}
}

void				ft_ptextures(t_all *settings)
{
	double wx;

	wx = 0.0;
	settings->col.x = settings->bm.i;
	if (settings->bm.side == 0 || settings->bm.side == 1)
		wx = settings->position.y + settings->bm.pwd * settings->bm.ray_y;
	else
		wx = settings->position.x + settings->bm.pwd * settings->bm.ray_x;
	wx -= floor(wx);
	if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == '1')
		ft_dside(settings, wx);
	settings->col.ys = 0;
	settings->col.ye = settings->dr.ds;
	ft_pcolor(settings, 0);
	settings->col.ys = settings->config.res[1];
	settings->col.ye = settings->dr.de;
	ft_pcolor(settings, 1);
}
