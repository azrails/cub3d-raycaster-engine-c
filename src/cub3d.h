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
#include <math.h>
#include "./get_next_line.h"
#include "../mlx/mlx.h"

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
	double x;
	double y;
}t_pos;

typedef struct s_check
{
	int c;
	int fo1;
	int lo1;
	int fo2;
	int lo2;
}t_check;

typedef struct s_win
{
	void *ptr;
	void *iptr;
	char *adr;
}t_w;

typedef struct s_dir
{
	double x;
	double y;
	double px;
	double py;
}t_d;

typedef struct s_beam
{
	int i;
	int stpx;
	int stpy;
	int crs;
	int pmx;
	int pmy;
	int side;
	double ray_x;
	double ray_y;
	double side_distx;
	double side_disty;
	double d_distx;
	double d_disty;
	double pwd;
	double camera;
}t_beam;

typedef struct s_s
{
	int c;
}t_sprite;

typedef struct s_draw
{
	int h;
	int ds;
	int de;
	int bp;
    int sl;
    int end;

}t_draw;

typedef struct s_colums
{
	int x;
	int y;
	int ys;
	int ye;
	int texx;
}t_colums;

typedef struct s_image
{
	int hg;
	int wd;
	int sl;
	int bp;
	int end;
	void *iptr;
	char *aptr;
}t_image;

typedef struct s_all
{
	int err;
	void *ptr;
	t_image **img;
	t_colums col;
	t_draw dr;
	t_sprite spt;
	t_w w;
	t_d d;
	t_beam bm;
	t_conf config;
	t_map map;
	t_pos position;
	t_check check;
}t_all;

void ft_ptextures(t_all *settings);
void ft_sprite(t_all *settings);
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
char *ft_textures(t_all *settings,char *line, int i);
int ft_area(char c ,char *line, t_all *settings, int i);
int ft_img(t_all *settings);

#endif