
#include "cub3d.h"

void			texture(t_all *settings, int i, char *line)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		settings->config.n = ft_textures(settings, line, i + 2);
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		settings->config.s = ft_textures(settings, line, i + 2);
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		settings->config.w = ft_textures(settings, line, i + 2);
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		settings->config.e = ft_textures(settings, line, i + 2);
}

int				ft_destr(void *param)
{
	t_all *settings;

	settings = (t_all *)param;
	errors(ft_clear(settings));
	return (1);
}

void			ft_op(t_all *settings, char *tmp, t_psp *psp)
{
	int fd;

	if ((ft_check_name(tmp, ".xpm")) < 0)
		settings->err = -7;
	if ((fd = open(tmp, O_RDONLY)) <= 0)
		settings->err = -8;
	if (settings->err < 0)
		errors(ft_clear(settings));
	close(fd);
	psp->sl = 2;
	if (!(psp->iptr =
		mlx_xpm_file_to_image(settings->ptr, tmp, &psp->wd, &psp->hg)))
	{
		settings->err = -7;
		errors(ft_clear(settings));
	}
	psp->aptr = mlx_get_data_addr(psp->iptr, &psp->bp, &psp->sl, &psp->end);
	settings->psp = psp;
}

int				ft_ns(t_all *settings)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (settings->map.lines[i])
	{
		j = 0;
		while (settings->map.lines[i][j])
		{
			if (settings->map.lines[i][j] == '2')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int				ft_skipspc(char *line, int i)
{
	while ((line[i] == '\t' || line[i] == '\n' || line[i] == '\r' ||
		line[i] == '\v' || line[i] == '\f' || line[i] == ' ') && line[i])
		i++;
	return (i);
}
