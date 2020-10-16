/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 13:39:51 by wsallei           #+#    #+#             */
/*   Updated: 2020/08/20 13:40:01 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		equal(char *s1, char *s2)
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

static int		error_arg(int argc, char **argv)
{
	int i;

	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'b' && argv[1][i - 2] != 'u' && argv[1][i - 3] != 'c' 
			&& argv[1][i - 4] != '.')
	{
		if (equal(argv[1], "--save") == 0)
			errors(-4);
		else
			write(2,"ERROR: wrong file format\n", 25);
		return(-1);
	}
	if (argc == 3 && equal(argv[2], "--save") != 0)
		{
			write(2,"ERROR: invalid flag\n", 20);
			return (-1);
		}
	return (0);
}

int		main(int argc , char **argv)
{
	int fd;
	t_all settings;

	settings.err = 0;
	if (argc == 2 || argc == 3)
	{
		if (error_arg(argc, argv) == 0)
		{
			if((fd = open(argv[1] ,O_RDONLY)) < 0)
				errors(-3);
			if (argc == 2)
				ft_init(fd, &settings);
			else if (argc == 3)
				ft_init(fd, &settings);
			close(fd);
		}
		else
			return (-1);
	}
	else
		errors(-1);
	return (0);
}
