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
#include "./get_next_line.h"

#include <stdio.h>


typedef	struct s_conf
{
	int		res[2];
	int  	f[3];
	int 	c[3];
	 char	*n;
	 char	*s;
	 char	*w;
	 char	*e;
}t_conf;

typedef struct s_map
{
	int count;
	char **lines;
}t_map;

typedef struct s_pos
{
	int x;
	int y;
}t_pos;

typedef struct s_check
{
	int c;
	int fo1;
	int lo1;
	int fo2;
	int lo2;
}t_check;

typedef struct s_all
{
	t_conf config;
	t_map map;
	int err;
	t_pos position;
	t_check check;
}t_all;

int ft_skiptrash(char *line, int i);
int   ft_check_lines(t_all *settings);
void ft_check_pars(t_all *settings);
int ft_ischar(char c);
void ft_check(char *line, t_all *settings);
void ft_init_conf(int fd, t_all *settings);
int ft_isnum(char c);
void ft_init(int fd, t_all *settings);
int ft_check_name(char *path ,char *name);
int   ft_pathLen(char *line, int i);
char *ft_calloc(int size, int len);
void errors(int er);
int ft_clear(t_all *settings);
int ft_resolution(char *line, t_all *settings, int i);
int ft_pars_map(char *line, t_all *settings );
int ft_check_map(t_all *settings);
int ft_textures(char *line, char *path , int i);
int ft_area(char c ,char *line, t_all *settings, int i);

#endif