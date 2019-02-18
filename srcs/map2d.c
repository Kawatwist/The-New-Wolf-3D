/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:59:36 by cbilga            #+#    #+#             */
/*   Updated: 2019/02/18 20:04:26 by lomasse          ###   ########.fr       */
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
		newposx = (az->ray[i]->posx - az->map->persox + XSCREEN/2);
		newposy = (az->ray[i]->posy - az->map->persoy + YSCREEN/2);
		SDL_RenderDrawLine(az->main->rend, XSCREEN/2, YSCREEN/2, newposx, newposy);
		i++;
	}
}

static void	draw_obstacle(t_acz *az)
{
	int 		x;
	int 		y;
	int			x1;
	int			y1;
	SDL_Rect	block;
	
	block.w = SBLOCK;
	block.h = SBLOCK;
	y = (int)az->map->persoy -  3;
	y1 = 0;
	while (y < (int)az->map->persoy + 6)
	{
		x = (int)az->map->persox - 5;
		x1 = 0;
		while (x < (int)az->map->persox + 6)
		{
			while (x < 0)
			{
				x++;
				x1++;
			}
			if (x > 60 || y > 60 || y < 0)
				break ;
			az->map->map[y][x] == 0 ? SDL_SetRenderDrawColor(az->main->rend, 150, 150, 150, 0) : 0;
			az->map->map[y][x] == 1 ? SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0) : 0;
			az->map->map[y][x] == 2 ? SDL_SetRenderDrawColor(az->main->rend, 150, 0, 150, 0) : 0;
			az->map->map[y][x] == 3 ? SDL_SetRenderDrawColor(az->main->rend, 250, 0, 0, 0) : 0;
			az->map->map[y][x] == 4 ? SDL_SetRenderDrawColor(az->main->rend, 250, 180, 0, 0) : 0;
			az->map->map[y][x] == 5 ? SDL_SetRenderDrawColor(az->main->rend, 0, 250, 0, 0) : 0;
			az->map->map[y][x] == 6 ? SDL_SetRenderDrawColor(az->main->rend, 0, 0, 255, 0) : 0;
			az->map->map[y][x] == 7 ? SDL_SetRenderDrawColor(az->main->rend, 250, 200, 0, 0) : 0;
			az->map->map[y][x] == 8 ? SDL_SetRenderDrawColor(az->main->rend, 200, 200, 255, 0) : 0;
			az->map->map[y][x] == 9 ? SDL_SetRenderDrawColor(az->main->rend, 200, 250, 100, 0) : 0;
			block.x = x1 * SBLOCK;
			block.y = y1 * SBLOCK;
			SDL_RenderFillRect(az->main->rend, &block);
			x++;
			x1++;
		}
		y++;
		y1++;
	}
}

void	map(t_acz *az)
{
	SDL_Rect	perso;

	perso.x = XSCREEN /2 - 17.5;
	perso.y = YSCREEN /2 - 17.5;
	perso.w = 35;
	perso.h = 35;
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
