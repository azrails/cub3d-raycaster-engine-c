/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:33:10 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:33:12 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_loop(void *par)
{
	t_all *settings;

	settings = (t_all *)par;
	start_draw(settings);
	ft_key_pressed(settings);
	return (0);
}

static	int		equal(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

static	int		error_arg(int argc, char **argv)
{
	int i;

	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'b' && argv[1][i - 2] != 'u' && argv[1][i - 3] != 'c'
			&& argv[1][i - 4] != '.')
	{
		if (equal(argv[1], "--save") == 0)
			errors(-4);
		else
			write(2, "ERROR: wrong file format\n", 25);
		return (-1);
	}
	if (argc == 3)
	{
		i = ft_strlen(argv[2]);
		if (equal(argv[2], "--save") != 0 || i != 6)
		{
			write(2, "ERROR: invalid flag\n", 20);
			return (-1);
		}
	}
	return (0);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_all	settings;

	settings.err = 0;
	if (argc == 2 || argc == 3)
	{
		if (error_arg(argc, argv) == 0)
		{
			if ((fd = open(argv[1], O_RDONLY)) < 0)
				errors(-1);
			if (argc == 2)
				ft_init(fd, &settings, 0);
			else if (argc == 3)
				ft_init(fd, &settings, 1);
		}
		else
			return (-1);
	}
	else
		errors(-1);
	return (0);
}
