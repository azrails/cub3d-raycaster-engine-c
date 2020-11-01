#include "cub3d.h"

static int ft_canmv(int x, int y, t_all *settings)
{
   if(settings->map.lines[y][x] == '1' || settings->map.lines[y][x] == '2')
        return(0);
    return(1);
}

static void ft_move_udl(t_all *settings, int key)
{
    if(ft_canmv((int)(settings->position.x + (settings->d.x * 0.1)),
         (int)(settings->position.y), settings) && key == 13)
    {
        settings->position.x += settings->d.x * 0.1;
        if(ft_canmv((int)(settings->position.x),
         (int)(settings->position.y + (settings->d.y * 0.1)), settings))
        settings->position.y += settings->d.y * 0.1;
    }
    if(ft_canmv((int)(settings->position.x - (settings->d.px * 0.1)),
         (int)(settings->position.y), settings) && key == 0)
    {
        settings->position.x -= settings->d.px * 0.1;
        if(ft_canmv((int)(settings->position.x),
         (int)(settings->position.y - settings->d.py * 0.1), settings))
            settings->position.y -= settings->d.py * 0.1;
    }
    if(ft_canmv((int)(settings->position.x - (settings->d.x * 0.1)),
         (int)(settings->position.y), settings) && key == 1)
    {
        settings->position.x -= settings->d.x * 0.1;
        if(ft_canmv((int)(settings->position.x),
         (int)(settings->position.y - (settings->d.y * 0.1)), settings))
        settings->position.y -= settings->d.y * 0.1;
    }
}

static void ft_look(t_all *settings, int key)
{
    double oldd;

    oldd = settings->d.x;
    if(ft_canmv((int)(settings->position.x + (settings->d.px * 0.1)),
         (int)(settings->position.y), settings) && key == 2)
    {
        settings->position.x += settings->d.px * 0.1;
        if(ft_canmv((int)(settings->position.x),
         (int)(settings->position.y + settings->d.py * 0.1), settings))
            settings->position.y += settings->d.py * 0.1;
    }
    if(key == 123)
    {
        settings->d.x = oldd * cos(-0.06) - settings->d.y * sin(-0.06);
        settings->d.y = oldd * sin(-0.06) + settings->d.y * cos(-0.06);
        oldd = settings->d.px;
        settings->d.px = oldd * cos(-0.06) - settings->d.py * sin(-0.06);
        settings->d.py = oldd * sin(-0.06) + settings->d.py * cos(-0.06);
    }
    if(key == 124)
    {
        settings->d.x = oldd * cos(0.06) - settings->d.y * sin(0.06);
        settings->d.y = oldd * sin(0.06) + settings->d.y * cos(0.06);
        oldd = settings->d.px;
        settings->d.px = oldd * cos(0.06) - settings->d.py * sin(0.06);
        settings->d.py = oldd * sin(0.06) + settings->d.py * cos(0.06);
    }
}

int ft_key_pressed(t_all *settings)
{
    if (settings->key.mu == 1)
        ft_move_udl(settings, 13);
    if (settings->key.ml == 1)
        ft_move_udl(settings, 0);
    if (settings->key.md == 1)
        ft_move_udl(settings, 1);
    if (settings->key.mr == 1)
        ft_look(settings, 2);
    if (settings->key.ll == 1)
        ft_look(settings, 123);
    if (settings->key.lr == 1)
        ft_look(settings, 124);
    return (0);
}