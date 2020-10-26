#include "cub3d.h"

static void ft_pimage(t_all *settings,t_image *img)
{
    int y;
    int texy;

    y = settings->col.y * img->sl - settings->config.res[1] * img->sl/2 + settings->dr.h/2;
    texy = ((y * img->hg) / settings->dr.h) / img->sl;
    settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x * settings->dr.bp / 8] = 
        img->aptr[texy * img->sl + settings->col.texx * (img->bp /8)];
    settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x * settings->dr.bp / 8 + 1] = 
        img->aptr[texy * img->sl + settings->col.texx * (img->bp /8) + 1];
    settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x * settings->dr.bp / 8 + 2] = 
        img->aptr[texy * img->sl + settings->col.texx * (img->bp /8) + 2];
    printf("%c",settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x * settings->dr.bp / 8 + 2]);
}

static void ft_pcol(t_all *settings, t_image *img)
{
    int ym;

    if (settings->col.ys < settings->col.ye)
    {
        settings->col.y = settings->col.ys;
        ym = settings->col.ye;
    }
    else
    {
        settings->col.y = settings->col.ye;
        ym = settings->col.ye;
    }
    if (settings->col.y >= 0)
    {
        while (settings->col.y < ym)
        {
            ft_pimage(settings,img);
            settings->col.y++;
        }
    }
    
}

static void ft_dside(t_all *settings, double wx)
{
    int texx;
    t_image *img;

    img = settings->img[0];
    if (settings->bm.side == 1)
        img = settings->img[1];
    else if (settings->bm.side == 2)
        img = settings->img[2];
    else if (settings->bm.side == 3)
        img = settings->img[3];
    texx = (int)(wx * (double)img->wd);
    if ((settings->bm.side == 0 || settings->bm.side == 1) && settings->bm.ray_x > 0)
        texx = img->wd - texx - 1;
    if ((settings->bm.side == 2 || settings->bm.side == 3) && settings->bm.ray_y < 0)
        texx = img->wd - texx - 1;
    settings->col.ys = settings->dr.de;
    settings->col.ye = settings->dr.ds;
    settings->col.texx = texx;
    ft_pcol(settings,img);
}

void ft_ptextures(t_all *settings)
{
    double wx;

    settings->col.x = settings->bm.i;
    if (settings->bm.side == 0 || settings->bm.side == 1)
        wx = settings->position.y + settings->bm.pwd * settings->bm.ray_x;
    else
        wx = settings->position.y + settings->bm.pwd * settings->bm.ray_x;
    wx -= floor(wx);
    if (settings->map.lines[settings->bm.pmy][settings->bm.pmx] == '1')
        ft_dside(settings, wx);
}