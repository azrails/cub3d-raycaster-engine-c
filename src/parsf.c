/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:33:28 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:33:30 by wsallei          ###   ########.fr       */
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

static	void	ft_start(int fd, t_all *settings)
{
	if (!(settings->ptr = mlx_init()))
	{
		settings->err = -3;
		errors(ft_clear(settings));
	}
	ft_val(fd, settings);
	ft_check_pars(settings);
	if (!(settings->w.ptr = mlx_new_window(settings->ptr,
			settings->config.res[0], settings->config.res[1], "Cub3D")))
	{
		settings->err = -5;
		errors(ft_clear(settings));
	}
	settings->position.x += 1;
	mlx_hook(settings->w.ptr, 2, 0, &ft_key, settings);
	mlx_hook(settings->w.ptr, 3, 0, &ft_upkey, settings);
	mlx_hook(settings->w.ptr, 17, 1L << 17, &ft_destr, settings);
	mlx_loop_hook(settings->ptr, &ft_loop, settings);
	mlx_loop(settings->ptr);
}

void			ft_init(int fd, t_all *settings, int f)
{
	settings->img = NULL;
	settings->ptr = NULL;
	settings->w.ptr = NULL;
	settings->w.adr = NULL;
	settings->w.iptr = NULL;
	settings->ds = NULL;
	settings->psp = NULL;
	settings->key.mu = 0;
	settings->key.mr = 0;
	settings->key.ml = 0;
	settings->key.md = 0;
	settings->config.res[0] = 0;
	settings->config.res[1] = 0;
	settings->config.n = NULL;
	settings->config.w = NULL;
	settings->config.s = NULL;
	settings->config.e = NULL;
	settings->map.count = 0;
	settings->map.lines = NULL;
	settings->position.x = 0;
	settings->position.y = 0;
	settings->spt = NULL;
	settings->bmp = f;
	settings->err = 0;
	settings->m = 0;
	ft_start(fd, settings);
}

int				ft_check(char *line, t_all *settings)
{
	int i;

	i = 0;
	i = ft_skipspc(line, i);
	settings->am = 0;
	if (line[i] == 'R' && line[i + 1] == ' ' && settings->m == 0)
		settings->err = ft_resolution(line, settings, i + 1);
	if (line[i] == 'S' && line[i + 1] == ' ' && settings->m == 0)
		settings->err = ft_opstp(settings, line, i + 1);
	if (((line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ') ||
	(line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ') ||
	(line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ') ||
	(line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')) && settings->m == 0)
	{
		texture(settings, i, line);
		settings->val.txt++;
	}
	if ((line[i] == 'F') && line[i + 1] == ' ' && settings->m == 0)
		settings->err = ft_area('F', line, settings, ++i);
	if ((line[i] == 'C') && line[i + 1] == ' ' && settings->m == 0)
		settings->err = ft_area('C', line, settings, ++i);
	if (line[i] == '1' || line[i] == '0' || line[i] == '2')
		ft_pars_map(line, settings);
	if (settings->m == 1 && line[i] != '\0' && settings->am == 0)
		settings->err = -5;
	if (settings->err < 0)
		return (-1);
	return (0);
}

void			ft_init_conf(int fd, t_all *settings)
{
	char	*line;
	int		err;

	err = 0;
	line = NULL;
	while ((err = (get_next_line(fd, &line))) > 0)
	{
		if (ft_check(line, settings) < 0)
		{
			close(fd);
			free(line);
			errors(ft_clear(settings));
		}
		free(line);
		line = NULL;
		if (err == 0)
			break;
	}	
	err = ft_check(line, settings);
	free(line);
	line = NULL;
	close(fd);
	if (err == -1)
		errors(-5);
}
