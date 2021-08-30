
#include "cub3d.h"

int		ft_clear(t_all *settings)
{
	if (settings->w.ptr != NULL)
		mlx_destroy_window(settings->ptr, settings->w.ptr);
	if (settings->img != NULL)
		free(settings->img);
	if (settings->config.e)
		free(settings->config.e);
	if (settings->config.w)
		free(settings->config.w);
	if (settings->config.s)
		free(settings->config.s);
	if (settings->config.n)
		free(settings->config.n);
	if (settings->map.lines)
		free(settings->map.lines);
	return (settings->err);
}

void	errors(int er)
{
	if (er == -12)
		write(1, "ERROR\ninvalid color\n", 20);
	if (er == -11)
		write(1, "ERROR\nsprite set but not path\n", 30);
	if (er == -10)
		write(1, "ERROR\ninvalid color\n", 20);
	if (er == -9)
		write(1, "ERROR\ninvalid resolution\n", 25);
	if (er == -8)
		write(1, "ERROR\ninvalid texture path\n", 27);
	if (er == -7)
		write(1, "ERROR\nin open textures\n", 23);
	if (er == -6)
		write(1, "ERROR\nmalloc is dead\n", 21);
	if (er == -5)
		write(1, "ERROR\nwrong map\n", 16);
	if (er == -4)
		write(2, "ERROR\nno map\n", 13);
	if (er == -3)
		write(1, "ERROR\nOoOpS\n", 12);
	if (er == -2)
		write(1, "ERROR\nno such file or directory\n", 32);
	if (er == -1)
		write(2, "ERROR\ninvalid input\n", 20);
	exit(0);
}
