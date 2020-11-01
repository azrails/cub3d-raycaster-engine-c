#include "cub3d.h"
static void ft_putdata(t_all *settings, int fd)
{
    int i;

    i = settings->config.res[0] * settings->config.res[1] - 1;
    while (i >= 0)
    {
            write(fd, &settings->w.adr[i * settings->dr.bp / 8], 4);
            i--;
    }
}

static void ft_put(t_all *settings, int i, int j, int k)
{
    char s;
    int r;

    r = 3;
    while (r >= 0)
    {
        s = settings->w.adr[j + (i * settings->dr.sl)];
        settings->w.adr[j + (i * settings->dr.sl)] = settings->w.adr[k - r + (i * settings->dr.sl - 1)];
        settings->w.adr[k - r + (i * settings->dr.sl - 1)] = s;
        r--;
        j += 1;
    }
}

static void ft_ppbmp(t_all *settings)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < settings->config.res[1])
    {
        j = 0;
        k = settings->dr.sl;
        while (j < k && j != k)
        {
            ft_put(settings, i, j, k);
            k -= 4;
        }
        i++;
    }
}

static void ft_hinfo(t_all *settings, int fd)
{
    int ihs;
    int p;
    int i;

    ihs = 40;
    p = 1;
    write(fd, &ihs, 4);
    write(fd, &settings->config.res[0], 4);
    write(fd, &settings->config.res[1], 4);
    write(fd, &p, 2);
    write(fd, &settings->dr.bp, 2);
    i = 0;
    while (i < 28)
    {
        write(fd, "\0", 1);
        i++;
    }
}

void ft_bmp(t_all *settings)
{
    int fd;
    int fs;
    int pp;

    fd = open("cub.bmp", O_CREAT | O_WRONLY | O_TRUNC , S_IRWXU);
    fs = 58 + (settings->config.res[0] * settings->config.res[1]) * 4;
    pp = 58;
    write(fd, "BM", 2);
    write(fd, &fs, 4);
    write(fd, "\0\0\0\0", 4);
    write(fd, &pp, 4);
    ft_hinfo(settings, fd);
    ft_ppbmp(settings);
    ft_putdata(settings, fd);
    close(fd);
    errors(ft_clear(settings));
}