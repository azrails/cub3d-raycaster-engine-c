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

int 	ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}
int 	errors(void)
{
	return -1;
}

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
			write(2,"ERROR: no map\n", 14);
		else
			write(2,"ERROR: wrong map format\n", 24);
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
	s_map *pars;
	c_conf *config;

	if (argc == 2 || argc == 3)
	{
		if (error_arg(argc, argv) == 0)
		{
			fd = open(argv[1] ,O_RDONLY);
			ft_init_conf(fd, &pars);
		}
		else
			return (errors());
	}
	else
	{
		write(2,"ERROR: invalid input\n",21);
		return (errors());
	}
	return (0);
}