/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:40:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/08 17:04:26 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		initeditmap(int	map[60][60])
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

static void		init_sdl(t_acz *az)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	az->main->window = SDL_CreateWindow("Wolf3D", 0, SDL_WINDOWPOS_CENTERED, XSCREEN, YSCREEN, SDL_WINDOW_SHOWN);
	az->main->rend = SDL_CreateRenderer(az->main->window, -1, SDL_RENDERER_PRESENTVSYNC);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

static void		init_info(t_info *info)
{
	info->x = 1;
	info->y = 1;
	info->editx = 5;
	info->edity = 5;
	info->editbrush = 1;
}

static void		call_init(t_acz *az)
{
	init_info(az->info);
	init_sdl(az);
	initeditmap(az->info->editmap);
	loadmenu(az);
	loadoption(az);
	az->interface = 0;
}

void			initialization(t_acz **az)
{
	int	i;

	((*az) = (t_acz *)malloc(sizeof(t_acz))) == NULL ? stop_exec("Dosnt malloc az struct\n") : 0;
	((*az)->main = (t_window *)malloc(sizeof(t_window))) == NULL ? stop_exec("Dosnt malloc main window struct\n") : 0;
	((*az)->map = (t_map *)malloc(sizeof(t_map))) == NULL ? stop_exec("Dosnt malloc map struct\n") : 0;
	((*az)->inv = (t_inv *)malloc(sizeof(t_inv))) == NULL ? stop_exec("Dosnt malloc inv struct\n") : 0;
	i = -1;
	while (++i < 800)
		((*az)->ray[i] = (t_ray *)malloc(sizeof(t_ray))) == NULL ? stop_exec("Dosnt malloc ray struct\n") : 0;
	((*az)->menu = (t_menu *)malloc(sizeof(t_menu))) == NULL ? stop_exec("Dosnt malloc menu struct\n") : 0;
	((*az)->option = (t_menu *)malloc(sizeof(t_menu))) == NULL ? stop_exec("Dosnt malloc option struct\n") : 0;
	((*az)->info = (t_info *)malloc(sizeof(t_info))) == NULL ? stop_exec("Dosnt malloc info struct\n") : 0;
	call_init(*az);
}
