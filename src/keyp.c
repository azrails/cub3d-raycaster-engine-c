
#include "cub3d.h"

int		ft_key(int key, void *par)
{
	t_all *settings;

	settings = (t_all *)par;
	if (key == 13 && settings->key.mu == 0)
		settings->key.mu = 1;
	if (key == 1 && settings->key.md == 0)
		settings->key.md = 1;
	if (key == 0 && settings->key.ml == 0)
		settings->key.ml = 1;
	if (key == 2 && settings->key.mr == 0)
		settings->key.mr = 1;
	if (key == 2 && settings->key.mr == 0)
		settings->key.mr = 1;
	if (key == 123 && settings->key.ll == 0)
		settings->key.ll = 1;
	if (key == 124 && settings->key.lr == 0)
		settings->key.lr = 1;
	return (0);
}

int		ft_upkey(int key, void *par)
{
	t_all *settings;

	settings = (t_all *)par;
	if (key == 13 && settings->key.mu == 1)
		settings->key.mu = 0;
	if (key == 1 && settings->key.md == 1)
		settings->key.md = 0;
	if (key == 0 && settings->key.ml == 1)
		settings->key.ml = 0;
	if (key == 2 && settings->key.mr == 1)
		settings->key.mr = 0;
	if (key == 123 && settings->key.ll == 1)
		settings->key.ll = 0;
	if (key == 124 && settings->key.lr == 1)
		settings->key.lr = 0;
	if (key == 53)
		errors(ft_clear(settings));
	return (0);
}
