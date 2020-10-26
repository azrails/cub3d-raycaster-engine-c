#include "cub3d.h"

static void ft_wall_size(t_all *settings)
{
    if (settings->bm.side == 0 || settings->bm.side == 1)
        settings->bm.pwd = (settings->bm.pmx - settings->position.x 
            + (1 - settings->bm.stpx) / 2);
    else
        settings->bm.pwd = (settings->bm.pmy - settings->position.y 
            + (1 - settings->bm.stpy) / 2);
    settings->dr.h = (int)(settings->config.res[0] / settings->bm.pwd);
    settings->dr.ds = (-settings->dr.h / 2 + ((settings->config.res[0]/2)));//check
    if (settings->dr.ds < 0)
        settings->dr.ds = 0;
    settings->dr.de = (settings->dr.h / 2 + (settings->config.res[0] / 2)); //check
    if (settings->dr.de >= settings->config.res[0])
        settings->dr.de = settings->config.res[0] - 1;
}

static void ft_crs(t_all *settings)
{
    while (settings->bm.crs == 0)
    {
        if (settings->bm.side_distx < settings->bm.side_disty)
        {
            settings->bm.side_distx += settings->bm.d_distx;
            settings->bm.pmx += settings->bm.stpx;
            settings->bm.side = (settings->bm.stpx == 1) ? 0:1;
        }
        else
        {
           settings->bm.side_disty += settings->bm.d_disty;
            settings->bm.pmy += settings->bm.stpy;
            settings->bm.side = (settings->bm.stpx == 1) ? 2:3;
        }
        if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == '1')
        {
            settings->bm.crs = 1;
        }
        if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == '2')
            ft_sprite(settings);
    }
}

static void ft_sdist(t_all *settings)
{
    if (settings->bm.ray_x < 0)
    {
        settings->bm.stpx = -1;
        settings->bm.side_distx = (settings->position.x - settings->bm.pmx) * settings->bm.d_distx;
    }
    else
    {
        settings->bm.stpx = 1;
        settings->bm.side_distx = (settings->bm.pmx + 1.0 - settings->position.x) * settings->bm.d_distx;
    }
    if (settings->bm.ray_y < 0)
    {
        settings->bm.stpx = -1;
        settings->bm.side_disty = (settings->position.y - settings->bm.pmy) * settings->bm.d_disty;
    }
    else
    {
        settings->bm.stpx = 1;
        settings->bm.side_disty = (settings->bm.pmy + 1.0 - settings->position.y) * settings->bm.d_disty;
    }
}

static void ft_putimg(t_all *settings)
{
    while (settings->bm.i < settings->config.res[0])
    {
        settings->bm.crs = 0;
        settings->bm.camera = (2 * settings->bm.i) / (double)settings->config.res[1] - 1;
        settings->bm.ray_x = settings->d.x + settings->d.px * settings->bm.camera;
        settings->bm.ray_y = settings->d.y + settings->d.py * settings->bm.camera;
        settings->bm.pmx = (int)settings->position.x;
        settings->bm.pmy = (int)settings->position.y;
        settings->bm.d_distx = fabs(1 / settings->bm.ray_x);
        settings->bm.d_distx = fabs(1 / settings->bm.ray_x);
        ft_sdist(settings);
        ft_crs(settings);
        ft_wall_size(settings);
        ft_ptextures(settings);
        settings->bm.i++;
    }
}

int ft_img(t_all *settings)
{

    settings->bm.i = 0;
    if (!(settings->w.iptr = mlx_new_image(settings->ptr,settings->config.res[0],settings->config.res[1])))
        return (-3);
    if (!(settings->w.adr = mlx_get_data_addr(settings->w.iptr, &settings->dr.bp, &settings->dr.sl, &settings->dr.end)))
        return (-3);
    ft_putimg(settings);
    mlx_put_image_to_window(settings->ptr,settings->w.ptr,settings->w.iptr,0,0);
    free(settings->w.iptr);
    free(settings->w.adr);
    return (0);
}