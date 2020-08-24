/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 13:42:49 by wsallei           #+#    #+#             */
/*   Updated: 2020/08/20 13:42:54 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
# define CUB_3D
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

typedef	struct cub_conf
{
	int		res[2];
	int  	f[3];
	int 	c[3];
	unsigned char	*n;
	unsigned char	*s;
	unsigned char	*w;
	unsigned char	*e;
}c_conf;

typedef struct s_map
{
	char *line;
	struct s_map *next;
}t_map;

#endif