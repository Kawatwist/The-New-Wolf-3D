/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:33:20 by cbilga            #+#    #+#             */
/*   Updated: 2019/02/25 13:45:40 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				letter(SDL_Rect *find, char c)
{
/*
	if (c < '0'|| c > 'z' || (c > '9' && c < 'A') || (c >'Z' && c < 'a'))
	{
		ft_putstr("char invalid\n");
		return (0);
	}
	find->x = c - '0' * 20 % 13;
	find->y = c - '0' / 13;
	find->w = NULL;
	find->h = NULL;
	return (1);
*/
	return (1);
}

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

void			load_texture(SDL_Renderer *render,
		SDL_Texture **texture, char *path)
{
	SDL_Surface	*surface;

	surface = IMG_Load(path);
	surface == NULL ? stop_exec("cant load surface\n") : 0;
	*texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}

SDL_Texture		*pick_texture(t_acz *az, int i)
{
	if (az->side[i] / SBLOCK == 1)
		return (az->game->Nwall);
	if (az->side[i] / SBLOCK == 2)
		return (az->game->Swall);
	if (az->side[i] / SBLOCK == 3)
		return (az->game->Wwall);
	if (az->side[i] / SBLOCK == 4)
		return (az->game->Ewall);
	if (az->side[i] / SBLOCK == 5)
		return (az->game->door);
	return (az->game->Filler);
}
