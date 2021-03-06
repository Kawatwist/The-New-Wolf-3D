/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:33:20 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/06 10:17:51 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			showsky(t_acz *az)
{
	double new;

	new = (az->info->angle * 100) * 3050 / 600;
	while (new < 0)
		new += 3200;
	while (new > 3200)
		new -= 3200;
	az->game->rsky.x = 0;
	az->game->rsky.y = (az->vue * 5) - 300;
	az->game->rsky.w = 800;
	az->game->rsky.h = 600;
	az->game->rsky2.x = new;
	az->game->rsky2.y = 0;
	az->game->rsky2.w = 800;
	az->game->rsky2.h = 800;
	az->game->rground.x = 0;
	az->game->rground.y = 0;
	az->game->rground.w = 800;
	az->game->rground.h = 800;
}

void			showground(t_acz *az)
{
	double new;

	new = (az->info->angle * 100) * 3050 / 600;
	while (new < 0)
		new += 3200;
	while (new > 3200)
		new -= 3200;
	az->game->rsky.x = 0;
	az->game->rsky.y = (az->vue * 5) - 300;
	az->game->rsky.w = 800;
	az->game->rsky.h = 600;
	az->game->rsky2.x = new;
	az->game->rsky2.y = 0;
	az->game->rsky2.w = 800;
	az->game->rsky2.h = 800;
	az->game->rground.x = 0;
	az->game->rground.y = 0;
	az->game->rground.w = 800;
	az->game->rground.h = 800;
}

void			load_texture(SDL_Renderer *render,
		SDL_Texture **texture, char *path, t_acz *az)
{
	SDL_Surface	*surface;

	surface = IMG_Load(path);
	surface == NULL ? stop_exec("cant load surface\n", az) : 0;
	*texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}

SDL_Texture		*pick_texture(t_acz *az, int i)
{
	if (az->side[i] / SBLOCK == 1)
		return (az->game->nwall);
	if (az->side[i] / SBLOCK == 2)
		return (az->game->swall);
	if (az->side[i] / SBLOCK == 3)
		return (az->game->wwall);
	if (az->side[i] / SBLOCK == 4)
		return (az->game->ewall);
	if (az->side[i] / SBLOCK == 5)
		return (az->game->door);
	return (az->game->filler);
}
