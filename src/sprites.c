#include "cub3d.h"

int ft_opstp(t_all *settings, char *line, int i)
{
    int end;
    char *tmp;
    int k;
    t_psp *psp;

    k = 0;
    i = ft_skiptrash(line, i);
    end = ft_pathLen(line, i);
    if (!(psp = malloc(sizeof(t_psp))))
        return(-6);
    if (!(tmp = ft_calloc(sizeof(char) , (end - i + 1))))
        return(-6);
    while(i <= end)
    {
        tmp[k] = line[i];
        i++;
        k++;
    }
    ft_op(settings, tmp, psp);
    free(tmp);
    return 0;
}

void ft_ssp(t_all *settings)
{
    int i;
    double ds;
    double de;
    t_tbs t;
    

    i = 0;
    while(i < settings->ds->count && i + 1 != settings->ds->count)
    {
        ds = ((settings->position.x - settings->ds->tsp[i].x) * (settings->position.x - settings->ds->tsp[i].x) + 
            (settings->position.y - settings->ds->tsp[i].y) * (settings->position.y - settings->ds->tsp[i].y));
        de = ((settings->position.x - settings->ds->tsp[i + 1].x) * (settings->position.x - settings->ds->tsp[i + 1].x) + 
            (settings->position.y - settings->ds->tsp[i + 1].y) * (settings->position.y - settings->ds->tsp[i + 1].y));
        if (ds < de)
        {
            t = settings->ds->tsp[i];
            settings->ds->tsp[i] = settings->ds->tsp[i + 1];
            settings->ds->tsp[i + 1] = t;
            i = 0;
        }
        else
            i++;
    }
}

void ft_pcl(t_all *settings, int cf)
{
    unsigned char r;
    unsigned char g;
    unsigned char b;

    r = (cf == 0) ? (unsigned char)settings->config.f[0] : (unsigned char)settings->config.c[0];
    g = (cf == 0) ? (unsigned char)settings->config.f[1] : (unsigned char)settings->config.c[1];
    b = (cf == 0) ? (unsigned char)settings->config.f[2] : (unsigned char)settings->config.c[2];
    settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x * settings->dr.bp / 8] = b; 
    settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x * settings->dr.bp / 8 + 1] = g;
    settings->w.adr[settings->col.y * settings->dr.sl + settings->col.x * settings->dr.bp / 8 + 2] = r;
}

static void ft_addspt(t_sprite *spt, t_sprite *old)
{
    while(old->next)
    {
        if (old->x == spt->x && old->y == spt->y)
        {
            free(spt);
            return;
        }
        old = old->next;
    }
    old->next = spt;
}

int ft_sprite(t_all *settings)
{
    t_sprite *spt;
    t_sprite *old;

    old = settings->spt;
    if(!(spt = malloc(sizeof(t_sprite))))
    {
        settings->err = -5;
        errors(ft_clear(settings));
    }
    spt->next = NULL;
    spt->x = settings->bm.pmx;
    spt->y = settings->bm.pmy;
    if (settings->spt == NULL)
        settings->spt = spt;
    else
        ft_addspt(spt, old);
    return 0;
}