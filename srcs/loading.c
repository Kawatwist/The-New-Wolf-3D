/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:31:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/02/16 20:55:21 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	loadeditoplay(t_acz *az)
{
	int i;
	int j;

	j = -1;
	while (++j < az->info->y)
		free(az->map->map[j]);
	(az->map->map = (int **)malloc(sizeof(int*) * 60)) == NULL ? stop_exec("MALLLOC FAILED\n") : 0;
	j = -1;
	while (++j < az->info->y)
		(az->map->map[j] = (int *)malloc(sizeof(int) * 60)) == NULL ? stop_exec("MALLLOC FAILED\n") : 0;
	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
		{
			az->map->map[j][i] = az->info->editmap[j][i];
			az->info->editmap[j][i] == 2 ? az->map->persox = i: 0;
			az->info->editmap[j][i] == 2 ? az->map->persoy = j: 0;
		}
	}
	az->info->x = 60;
	az->info->y = 60;
}

void	rectpos(t_acz *az)
{
	az->menu->rselect.x = 629;
	az->menu->rselect.y = 24 + (az->info->editbrush * 41);
	az->menu->rselect.w = 26;
	az->menu->rselect.h = 26;
	az->menu->redit.x = 600;
	az->menu->redit.y = 0;
	az->menu->redit.w = 200;
	az->menu->redit.h = 600;
}

void    loadgame(t_acz *az)
{
    load_texture(az->main->rend, &az->game->sky, "texture/sky.png");
    load_texture(az->main->rend, &az->game->ground, "texture/ground.png");
    load_texture(az->main->rend, &az->game->Nwall, "texture/mur1.jpeg");
    load_texture(az->main->rend, &az->game->Swall, "texture/mur2.jpeg");
    load_texture(az->main->rend, &az->game->Ewall, "texture/mur3.jpeg");
    load_texture(az->main->rend, &az->game->Wwall, "texture/mur4.jpeg");
    load_texture(az->main->rend, &az->game->Filler, "texture/MARBLES.bmp");
}

void	loadedit(t_acz *az)
{
	load_texture(az->main->rend, &az->menu->editor, "texture/editor.png");
	load_texture(az->main->rend, &az->menu->select, "texture/select.png");
}

void	loadoption(t_acz *az)
{
	load_texture(az->main->rend, &az->option->bg, "texture/option.png");
}

void	loadmenu(t_acz *az)
{
	az->main->effect = Mix_LoadWAV("texture/Gun.wav");
//	load_texture(az->main->rend, &az->menu->font, "texture/font.png");
	load_texture(az->main->rend, &az->menu->bg, "texture/bg.png");
	load_texture(az->main->rend, &az->menu->choice, "texture/arrow.png");
}
