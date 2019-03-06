/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:40:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 10:53:09 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		initray(t_acz *az)
{
	int		current;
	double	ang;

	current = 0;
	while (current < XSCREEN)
	{
		ang = (current - (XSCREEN / 2)) * 0.00144;
		az->ray[current]->obs = -1;
		az->ray[current]->posx = (az->info->range * cos(ang)) +
			(az->info->range * -sin(ang)) + (az->map->persox * SBLOCK);
		az->ray[current]->posy = (az->info->range * sin(ang)) +
			(az->info->range * cos(ang)) + (az->map->persoy * SBLOCK);
		current++;
	}
}

void		initeditmap(int map[60][60])
{
	int i;
	int j;

	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
			map[j][i] = 0;
	}
}

void		init_sdl(t_acz *az)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	az->main->window = SDL_CreateWindow("Wolf3D", 0,
			SDL_WINDOWPOS_CENTERED, XSCREEN, YSCREEN, SDL_WINDOW_SHOWN);
	az->main->rend = SDL_CreateRenderer(az->main->window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	Mix_OpenAudio(17050, MIX_DEFAULT_FORMAT, 2, 4096);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

void		init_info(t_info *info)
{
	info->x = 1;
	info->y = 1;
	info->editx = 5;
	info->edity = 5;
	info->selectx = 0;
	info->selecty = 0;
	info->editbrush = 1;
	info->range = 6000;
	info->angle = 0;
}

void		initinv(t_acz *az)
{
	az->inv->frame = 1;
	az->inv->framesens = 1;
	az->inv->key = 0;
	az->inv->rifle = 0;
	az->inv->health = 100;
	az->inv->shield = 50;
}
