/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 22:10:20 by wsallei           #+#    #+#             */
/*   Updated: 2020/08/20 22:10:22 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void 	listdell(s_map **pars)
{
	s_map *tmp;

	while(*pars)
	{
		tmp = *pars;
		*pars = pars->next;
		free(tmp);
	}
}

static 	void map_back(char *line, s_map **pars)
{
	s_map *tmp;
	s_map *tmp2;

	tmp2 = *pars;
	if (!(tmp = malloc(sizeof(s_map))))
	{
		write(2,"ERROR: FAILURE\n",15);
		exit(listdell(pars));
	}
	else
		{
			tmp->line = line;
			tmp->next = NULL;
		}
	while(tmp2->next && tmp2)
		tmp2 = tmp2->next;
	tmp2 = tmp;
	free(line);
	line = NULL;
}

static	void 	parse_c(s_map **pars)
{
	int i;

	i = 0;
	while ()
	if (ft_strchr())
}

void	ft_init_conf(int fd, s_map **pars)
{
	int check;
	char *line;


	check = 0;
	line = NULL;
	while((check = get_next_line(fd, &line)) > 0)
		map_back(line, pars);
	if (check == -1)
	{
		write(2,"ERROR: FAILURE\n",15);
		exit(listdell(pars));
	}
	parse_c(pars);
}
