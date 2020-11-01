/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:35:05 by wsallei           #+#    #+#             */
/*   Updated: 2020/11/01 10:35:07 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./get_next_line.h"
# include "../mlx/mlx.h"

typedef	struct			s_conf
{
	int					res[2];
	int					f[3];
	int					c[3];
	char				*n;
	char				*s;
	char				*w;
	char				*e;
}						t_conf;

typedef	struct			s_map
{
	int					count;
	char				**lines;
}						t_map;

typedef	struct			s_pos
{
	double				x;
	double				y;
}						t_pos;

typedef	struct			s_check
{
	int					c;
	int					fo1;
	int					lo1;
	int					fo2;
	int					lo2;
}						t_check;

typedef	struct			s_win
{
	void				*ptr;
	void				*iptr;
	char				*adr;
}						t_w;

typedef	struct			s_dir
{
	double				x;
	double				y;
	double				px;
	double				py;
}						t_d;

typedef	struct			s_beam
{
	int					i;
	int					stpx;
	int					stpy;
	int					crs;
	int					pmx;
	int					pmy;
	int					side;
	double				*psp;
	double				ray_x;
	double				ray_y;
	double				side_distx;
	double				side_disty;
	double				d_distx;
	double				d_disty;
	double				pwd;
	double				camera;
}						t_beam;

typedef	struct			s_draw
{
	int					h;
	int					ds;
	int					de;
	int					bp;
	int					sl;
	int					end;

}						t_draw;

typedef	struct			s_colums
{
	int					x;
	int					y;
	int					ys;
	int					ye;
	int					texx;
}						t_colums;

typedef	struct			s_image
{
	int					hg;
	int					wd;
	int					sl;
	int					bp;
	int					end;
	void				*iptr;
	char				*aptr;
}						t_image;

typedef	struct			s_key
{
	int					mu;
	int					md;
	int					ml;
	int					mr;
	int					ll;
	int					lr;
}						t_key;

typedef	struct			s_sprite
{
	int					x;
	int					y;
	struct s_sprite		*next;
}						t_sprite;

typedef	struct			s_tbspt
{
	int					x;
	int					y;
}						t_tbs;

typedef	struct			s_draw_sprite
{
	int					i;
	int					k;
	int					j;
	int					y;
	int					color;
	int					count;
	int					ssx;
	int					h;
	int					w;
	int					dsx;
	int					dex;
	int					dsy;
	int					dey;
	int					tsx;
	int					tsy;
	double				sx;
	double				sy;
	double				dt;
	double				tx;
	double				ty;
	t_tbs				*tsp;
}						t_ds;

typedef	struct			s_psp
{
	int					hg;
	int					wd;
	int					sl;
	int					bp;
	int					end;
	void				*iptr;
	char				*aptr;
}						t_psp;

typedef	struct			s_val
{
	int					txt;
	int					s;
	int					res;
	int					cf;
}						t_val;

typedef	struct			s_all
{
	int					err;
	int					bmp;
	void				*ptr;
	t_val				val;
	t_psp				*psp;
	t_ds				*ds;
	t_key				key;
	t_image				**img;
	t_colums			col;
	t_draw				dr;
	t_sprite			*spt;
	t_w					w;
	t_d					d;
	t_beam				bm;
	t_conf				config;
	t_map				map;
	t_pos				position;
	t_check				check;
}						t_all;

void					texture(t_all *settings, int i, char *line);
void					ft_val(int fd, t_all *settings);
int						ft_in(t_all *settings);
int						ft_op_textures(t_all *settings);
int						ft_destr(void *param);
int						ft_checkspt(t_all *settings);
void					ft_bmp(t_all *settings);
void					ft_ppx(t_all *settings);
void					ft_pxp(t_all *settings);
void					ft_op(t_all *settings, char *tmp, t_psp *psp);
int						ft_opstp(t_all *settings, char *line, int i);
void					ft_ssp(t_all *settings);
int						ft_loop(void *par);
int						ft_dspt(t_all *settings);
void					ft_pcl(t_all *settings, int cf);
int						ft_key(int key, void *par);
int						ft_upkey(int key, void *par);
void					start_draw(t_all *settings);
void					ft_ptextures(t_all *settings);
int						ft_key_pressed(t_all *settings);
int						ft_sprite(t_all *settings);
int						ft_skiptrash(char *line, int i);
int						ft_check_lines(t_all *settings);
void					ft_check_pars(t_all *settings);
int						ft_ischar(char c);
int						ft_check(char *line, t_all *settings);
void					ft_init_conf(int fd, t_all *settings);
int						ft_isnum(char c);
void					ft_init(int fd, t_all *settings, int f);
int						ft_check_name(char *path, char *name);
int						ft_pathlen(char *line, int i);
char					*ft_calloc(int size, int len);
void					errors(int er);
int						ft_clear(t_all *settings);
int						ft_resolution(char *line, t_all *settings, int i);
int						ft_pars_map(char *line, t_all *settings);
int						ft_check_map(t_all *settings);
char					*ft_textures(t_all *settings, char *line, int i);
int						ft_area(char c, char *line, t_all *settings, int i);
int						ft_img(t_all *settings);

#endif
