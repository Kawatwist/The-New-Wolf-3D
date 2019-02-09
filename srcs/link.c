/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <madda.in@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:01:54 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/07 15:18:17 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void initdda(t_dda *dda)
{
	dda->pasx = 0;
	dda->pasy = 0;
	dda->distx = 0;
	dda->disty = 0;
	dda->dist = 0;
	dda->side = 0;
	dda->dx = 0;
	dda->dy = 0;
	dda->e = 0;
	dda->pente = 0;
}

/*
static int	get_side(t_dda *dda, t_win *wn)
{
	// 1 - Nord , 2 - Sud , 3 - Ouest , 4 -Est , 0 - coin
	if (((wn->map[(dda->y - 1) * wn->y / wn->yscreen][r->x * wn->x / wn->xscreen]) == BOX) &&
		((wn->map[(dda->y + 1) * wn->y / wn->yscreen][r->x * wn->x / wn->xscreen]) == BOX))
	{
		if (dda->pasx == -1)
			return (3);
		return (4);
	}
	if (((wn->map[dda->y * wn->y / wn->yscreen][(r->x - 1) * wn->x / wn->xscreen]) == BOX) &&
		((wn->map[dda->y * wn->y / wn->yscreen][(r->x + 1) * wn->x / wn->xscreen]) == BOX))
	{
		if (dda->pasy == -1)
			return (1);
		return (2);
	}
	return (0);
}*/

void	raycast(t_acz *az)
{
	t_dda dda;

	dda.i = 0;
	while (dda.i < XSCREEN)
	{
		initdda(&dda);
		dda.x = (int)az->map->persox;
		dda.y = (int)az->map->persoy;
		dda.pasx = (dda.dx = (int)az->ray[dda.i]->posx - dda.x) < 0 ? -1 : 1;
		dda.pasy = (dda.dy = (int)az->ray[dda.i]->posy - dda.y) < 0 ? -1 : 1;
		dda.dx = ft_abs(dda.dx);
		dda.dy = ft_abs(dda.dy);
		if (dda.dx > dda.dy)
		{
			dda.pente = 1;
			dda.e = dda.dx;
		}
		else
			dda.e = dda.dy;
		dda.dx = dda.dx * 2;
		dda.dy = dda.dy * 2;
		while (dda.dist < az->info->range)
		{
			if (dda.pente == 1)
			{
				dda.distx++;
				dda.x += dda.pasx;
				dda.e = dda.e - dda.dy;
				if (dda.e < 0)
				{
					dda.disty++;
					dda.y += dda.pasy;
					dda.e += dda.dx;
				}
			}
			else
			{
				dda.disty++;
				dda.y += dda.pasy;
				dda.e = dda.e - dda.dx;
				if (dda.e < 0)
				{
					dda.distx++;
			                dda.x+= dda.pasx;
                    			dda.e += dda.dy;
				}
			}
			dda.dist = sqrt((dda.distx * dda.distx) + (dda.disty * dda.disty));
			if ((az->map->map[dda.y][dda.x]) != 0)
			{
				if ((az->map->map[dda.y][dda.x]) == 1)
				{
					dda.dist = (dda.dist * cos((dda.i - (XSCREEN / 2)) * (1 / 60) * 0.00144 ));
					dda.dist = (dda.dist != 0 ? (75 / dda.dist * 255) : 0);
					az->ray[dda.i]->facey = dda.y * 60 / YSCREEN;
					az->ray[dda.i]->facex = dda.x * 60 / YSCREEN;
					az->ray[dda.i]->obs = dda.dist;
					break ;
				}
				/*else if (az->ray[dda.i]->other == -1)
				{
					dda.convdist = (dda.dist * cos((dda.i - (XSCREEN / 2)) * (1 / 66)));
					dda.convdist = (dda.dist != 0 ? (75 / dda.dist * 255) : 0);
					az->ray[dda.i]->other = az->map->map[dda.y * 60 / YSCREEN][dda.x * 60 / XSCREEN];
					az->ray[dda.i]->obsother = dda.convdist;
				}*/ 
			}
		}
		if (dda.dist == az->info->range)
			az->ray[dda.i]->obs = dda.dist;
		dda.i += 1;
	}
}
