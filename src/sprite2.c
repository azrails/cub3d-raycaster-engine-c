
#include "cub3d.h"

void	ft_pxp(t_all *settings)
{
	settings->ds->k = settings->ds->y * settings->psp->sl -
	settings->config.res[1] * (settings->psp->sl / 2) +
	settings->ds->h * settings->psp->sl / 2;
	settings->ds->tsy = ((settings->ds->k * settings->psp->hg) /
	settings->ds->h) / settings->psp->sl;
	settings->ds->color = settings->psp->aptr[settings->ds->tsy *
	settings->psp->sl + settings->ds->tsx * settings->psp->bp / 8] +
	settings->psp->aptr[settings->ds->tsy * settings->psp->sl +
	settings->ds->tsx * settings->psp->bp / 8 + 1] +
	settings->psp->aptr[settings->ds->tsy * settings->psp->sl +
	settings->ds->tsx * settings->psp->bp / 8 + 2];
}

void	ft_ppx(t_all *settings)
{
	settings->w.adr[settings->ds->y * settings->dr.sl + settings->ds->j *
	settings->dr.bp / 8] = settings->psp->aptr[settings->ds->tsy *
	settings->psp->sl + settings->ds->tsx * settings->psp->bp / 8];
	settings->w.adr[settings->ds->y * settings->dr.sl + settings->ds->j *
	settings->dr.bp / 8 + 1] = settings->psp->aptr[settings->ds->tsy *
	settings->psp->sl + settings->ds->tsx * settings->psp->bp / 8 + 1];
	settings->w.adr[settings->ds->y * settings->dr.sl + settings->ds->j *
	settings->dr.bp / 8 + 2] = settings->psp->aptr[settings->ds->tsy *
	settings->psp->sl + settings->ds->tsx * settings->psp->bp / 8 + 2];
}
