/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:59:36 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 18:46:56 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	draw_ray(t_acz *az)
{
	int i;
	int	newposx;
	int	newposy;

	i = 0;
	while (i < XSCREEN)
	{
		newposx = (az->ray[i]->posx - az->map->persox + XSCREEN / 2);
		newposy = (az->ray[i]->posy - az->map->persoy + YSCREEN / 2);
		SDL_RenderDrawLine(az->main->rend, XSCREEN / 2, YSCREEN / 2,
				newposx, newposy);
		i++;
	}
}

static void	draw_obstacle3(t_acz *az, SDL_Rect *p, SDL_Rect *block)
{
	az->map->map[p->y][p->x] == 0 ? SDL_SetRenderDrawColor(az->main->rend,
						150, 150, 150, 0) : 0;
	az->map->map[p->y][p->x] == 1 ? SDL_SetRenderDrawColor(az->main->rend,
						0, 0, 0, 0) : 0;
	az->map->map[p->y][p->x] == 2 ? SDL_SetRenderDrawColor(az->main->rend,
						150, 0, 150, 0) : 0;
	az->map->map[p->y][p->x] == 3 ? SDL_SetRenderDrawColor(az->main->rend,
						250, 0, 0, 0) : 0;
	az->map->map[p->y][p->x] == 4 ? SDL_SetRenderDrawColor(az->main->rend,
						250, 180, 0, 0) : 0;
	az->map->map[p->y][p->x] == 5 ? SDL_SetRenderDrawColor(az->main->rend,
						0, 250, 0, 0) : 0;
	az->map->map[p->y][p->x] == 6 ? SDL_SetRenderDrawColor(az->main->rend,
						0, 0, 255, 0) : 0;
	az->map->map[p->y][p->x] == 7 ? SDL_SetRenderDrawColor(az->main->rend,
						250, 200, 0, 0) : 0;
	az->map->map[p->y][p->x] == 8 ? SDL_SetRenderDrawColor(az->main->rend,
						200, 200, 255, 0) : 0;
	az->map->map[p->y][p->x] == 9 ? SDL_SetRenderDrawColor(az->main->rend,
						200, 250, 100, 0) : 0;
	az->map->map[p->y][p->x] == ENEMY ? SDL_SetRenderDrawColor(az->main->rend,
						100, 0, 0, 0) : 0;
	block->x = p->w * SBLOCK;
	block->y = p->h * SBLOCK;
	SDL_RenderFillRect(az->main->rend, block);
}

static int	draw_obstacle2(t_acz *az, SDL_Rect *p, SDL_Rect *block)
{
	if (p->y >= 60)
		return (1);
	p->x = (int)az->map->persox - 6;
	p->w = 0;
	while (p->x < (int)az->map->persox + 10 || p->x <= 60)
	{
		while (p->x < 0)
		{
			p->x++;
			p->w++;
		}
		if (p->x >= 60 || p->y >= 60 || p->y < 0)
			break ;
		draw_obstacle3(az, p, block);
		SDL_RenderFillRect(az->main->rend, block);
		p->x++;
		p->w++;
	}
	p->y++;
	p->h++;
	return (0);
}

static void	draw_obstacle(t_acz *az)
{
	SDL_Rect	p;
	SDL_Rect	block;

	block.w = SBLOCK;
	block.h = SBLOCK;
	p.y = (int)az->map->persoy - 5;
	p.h = 0;
	while (p.y < (int)az->map->persoy + 10 || p.y <= 60)
	{
		while (p.y < 0)
		{
			p.y++;
			p.h++;
		}
		if (draw_obstacle2(az, &p, &block))
			break ;
	}
}

void		map(t_acz *az)
{
	SDL_Rect	perso;

	perso.x = XSCREEN / 2 - SBLOCK / 4;
	perso.y = YSCREEN / 2 - SBLOCK / 4;
	perso.w = SBLOCK / 2;
	perso.h = SBLOCK / 2;
	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
	SDL_RenderClear(az->main->rend);
	SDL_SetRenderDrawColor(az->main->rend, 150, 150, 150, 0);
	draw_obstacle(az);
	SDL_SetRenderDrawColor(az->main->rend, 150, 0, 150, 0);
	SDL_RenderFillRect(az->main->rend, &perso);
	SDL_SetRenderDrawColor(az->main->rend, 150, 50, 50, 250);
	draw_ray(az);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}
