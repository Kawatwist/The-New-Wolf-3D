/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:01:54 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/08 09:59:24 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void initray(t_ray *r)
{
	r->pasx = 0;
	r->pasy = 0;
	r->distx = 0;
	r->disty = 0;
	r->dist = 0;
	r->side = 0;
	r->dx = 0;
	r->dy = 0;
	r->e = 0;
	r->pente = 0;
}

static int	get_side(t_ray *r, t_win *wn)
{
	// 1 - Nord , 2 - Sud , 3 - Ouest , 4 -Est , 0 - coin
	if (((wn->map[(r->y - 1) * wn->y / wn->yscreen][r->x * wn->x / wn->xscreen]) == BOX) &&
		((wn->map[(r->y + 1) * wn->y / wn->yscreen][r->x * wn->x / wn->xscreen]) == BOX))
	{
		if (r->pasx == -1)
			return (3);
		return (4);
	}
	if (((wn->map[r->y * wn->y / wn->yscreen][(r->x - 1) * wn->x / wn->xscreen]) == BOX) &&
		((wn->map[r->y * wn->y / wn->yscreen][(r->x + 1) * wn->x / wn->xscreen]) == BOX))
	{
		if (r->pasy == -1)
			return (1);
		return (2);
	}
	return (0);
}
void	raycast(t_win *wn)
{
	t_ray r;

	r.i = 0;
	while (r.i < FOV)
	{
		//printf("Target %d %d\n", (int)wn->perso->vue[r.i].x, (int)wn->perso->vue[r.i].y);
		initray(&r);
		r.x = (int)wn->perso->posx;
		r.y = (int)wn->perso->posy;
		r.pasx = (r.dx = (int)wn->perso->vue[r.i].x - r.x) < 0 ? -1 : 1;
		r.pasy = (r.dy = (int)wn->perso->vue[r.i].y - r.y) < 0 ? -1 : 1;
		r.dx = ft_abs(r.dx);
		r.dy = ft_abs(r.dy);
		if (r.dx > r.dy)
		{
			r.pente = 1;
			r.e = r.dx;
		}
		else
			r.e = r.dy;
		r.dx = r.dx * 2;
		r.dy = r.dy * 2;
		while (r.dist < wn->perso->range)
		{
			if (r.pente == 1)
			{
				r.distx++;
				r.x += r.pasx;
				r.e = r.e - r.dy;
				if (r.e < 0)
				{
					r.disty++;
					r.y += r.pasy;
					r.e += r.dx;
				}
			}
			else
			{
				r.disty++;
				r.y += r.pasy;
				r.e = r.e - r.dx;
				if (r.e < 0)
				{
					r.distx++;
                    r.x+= r.pasx;
                    r.e += r.dy;
				}
			}
			r.dist = sqrt((r.distx * r.distx) + (r.disty * r.disty));
			if (wn->dbug == 1)
			{
				SDL_SetRenderDrawColor(wn->debug->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderDrawPoint(wn->debug->rend, r.x, r.y);
			}
			if (r.i == FOV/2 && wn->dbug == 1)
			{
				SDL_SetRenderDrawColor(wn->debug->rend, 255, 0, 255, SDL_ALPHA_OPAQUE);
				SDL_RenderDrawPoint(wn->debug->rend, r.x, r.y);
			}
			if ((wn->map[r.y * wn->y / wn->yscreen][r.x * wn->x / wn->xscreen]) != GROUND)
			{
				if ((wn->map[r.y * wn->y / wn->yscreen][r.x * wn->x / wn->xscreen]) == BOX)
				{
					//on calcule side 
					r.side = get_side(&r, wn);
					//printf("%d ", r.side);
					r.dist = (r.dist * cos((r.i - (FOV / 2)) * 0.00144));
					r.dist = (r.dist != 0 ? (75 / r.dist * 255) : 0);
					wn->perso->vue[r.i].facey = r.y * wn->y / wn->yscreen;
					wn->perso->vue[r.i].facex = r.x * wn->x / wn->yscreen;
					wn->perso->vue[r.i].obs = r.dist;
					break ;
				}
				else if (wn->perso->vue[r.i].other == GROUND)
				{
					r.convdist = (r.dist * cos((r.i - (FOV / 2)) * 0.00144));
					r.convdist = (r.dist != 0 ? (75 / r.dist * 255) : 0);
					wn->perso->vue[r.i].other = wn->map[r.y * wn->y / wn->yscreen][r.x * wn->x / wn->xscreen];
					wn->perso->vue[r.i].obsother = r.convdist;
				} 
			}
		}
		//printf("\n");
		if (r.dist == wn->perso->range)
			wn->perso->vue[r.i].obs = r.dist;
		r.i += 1;
	}
	//printf("\n");
}
