/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:59:46 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/08 09:57:12 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			initmatrice(t_mat	*matrice)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 3)
			matrice->mt[y][x] = (x == y ? 1 : 0);
	}
}

void			calcmatrice(t_mat *m, t_mat *b)
{
	double a1;
	double a2;
	double a3;
	double b1;
	double b2;
	double b3;
	double c1;
	double c2;
	double c3;

	a1 = (m->mt[0][0] * b->mt[0][0]) + (m->mt[0][1] * b->mt[1][0]) + (m->mt[0][2] * b->mt[2][0]);
	a2 = (m->mt[0][0] * b->mt[0][1]) + (m->mt[0][1] * b->mt[1][1]) + (m->mt[0][2] * b->mt[2][1]);
	a3 = (m->mt[0][0] * b->mt[0][2]) + (m->mt[0][1] * b->mt[1][2]) + (m->mt[0][2] * b->mt[2][2]);

	b1 = (m->mt[1][0] * b->mt[0][0]) + (m->mt[1][1] * b->mt[1][0]) + (m->mt[1][2] * b->mt[2][0]);
	b2 = (m->mt[1][0] * b->mt[0][1]) + (m->mt[1][1] * b->mt[1][1]) + (m->mt[1][2] * b->mt[2][1]);
	b3 = (m->mt[1][0] * b->mt[0][2]) + (m->mt[1][1] * b->mt[1][2]) + (m->mt[1][2] * b->mt[2][2]);

	c1 = (m->mt[2][0] * b->mt[0][0]) + (m->mt[2][1] * b->mt[1][0]) + (m->mt[2][2] * b->mt[2][0]);
	c2 = (m->mt[2][0] * b->mt[0][1]) + (m->mt[2][1] * b->mt[1][1]) + (m->mt[2][2] * b->mt[2][1]);
	c3 = (m->mt[2][0] * b->mt[0][2]) + (m->mt[2][1] * b->mt[1][2]) + (m->mt[2][2] * b->mt[2][2]);

	m->mt[0][0] = a1;
	m->mt[0][1] = a2;
	m->mt[0][2] = a3;
	m->mt[1][0] = b1;
	m->mt[1][1] = b2;
	m->mt[1][2] = b3;
	m->mt[2][0] = c1;
	m->mt[2][1] = c2;
	m->mt[2][2] = c3;
}

static void		newvalue(t_win *wn, double *x, double *y)
{
	double	x2;
	double	y2;

	x2 = (*x * wn->matrice->mt[0][0]) + (*y * wn->matrice->mt[0][1]);
	y2 = (*x * wn->matrice->mt[1][0]) + (*y * wn->matrice->mt[1][1]);
	*x = (x2 > 0 ? x2 : 0);
	*y = (y2 > 0 ? y2 : 0);
	*x = (x2 < wn->xscreen ? x2 : wn->xscreen);
	*y = (y2 < wn->yscreen ? y2 : wn->yscreen);
}

void			rotatematrice(t_win *wn)
{
	t_mat	*b;
	int		fov;

	if (!(b = (t_mat *)malloc(sizeof(t_mat))))
		exit(0);
	initmatrice(b);
	rotatexy(wn, b);
	initmatrice(wn->matrice);
	calcmatrice(wn->matrice, b);
	free(b);
	fov = 0;
	while (fov < FOV)
	{
	//	newvalue(wn, &wn->perso->vue[fov].x, &wn->perso->vue[fov].y);
		setvue(wn, fov);
		fov++;
	}
}

void			setvue(t_win *wn, int current)
{
	double	ang;

	ang = current * (0.00144) + wn->angx;
	//ang = (0.0174533 * current);
	wn->perso->vue[current].x = (wn->perso->range * cos(ang)) + ((wn->perso->range) * -sin(ang)) + wn->perso->posx;
	wn->perso->vue[current].y = (wn->perso->range * sin(ang) + (wn->perso->range) * cos(ang)) + wn->perso->posy;
	wn->perso->vue[current].obs = current % 20 + (wn->perso->range / 2);//wn->perso->range;
	wn->perso->vue[current].other = 1;
	wn->perso->vue[current].obsother = 0;
	wn->perso->vue[current].ang = ang;
}

void			initvue(t_win *wn, int current)
{
	double	ang;

	ang = current * (0.00144);
	//ang = (0.0174533 * current);
	wn->perso->vue[current].x = (wn->perso->range * cos(ang)) + ((wn->perso->range) * -sin(ang)) + wn->perso->posx;
	wn->perso->vue[current].y = (wn->perso->range * sin(ang) + (wn->perso->range) * cos(ang)) + wn->perso->posy;
	wn->perso->vue[current].obs = current % 20 + (wn->perso->range / 2);//wn->perso->range;
	wn->perso->vue[current].other = 1;
	wn->perso->vue[current].obsother = 0;
	wn->perso->vue[current].ang = ang;
}
