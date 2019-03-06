/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:31:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/06 10:34:29 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	rectpos(t_acz *az)
{
	az->menu->rselect.x = 629;
	az->menu->rselect.y = 24 + (az->info->editbrush * 41);
	if (az->info->editbrush >= 8)
		az->menu->rselect.y = (az->info->editbrush == 8 ? 270 : 311);
	az->menu->rselect.w = 26;
	az->menu->rselect.h = 26;
	az->menu->redit.x = 600;
	az->menu->redit.y = 0;
	az->menu->redit.w = 200;
	az->menu->redit.h = 600;
}

void	loadgame(t_acz *az)
{
	load_texture(az->main->rend, &az->game->sky, "texture/sky3.png", az);
	load_texture(az->main->rend, &az->game->ground, "texture/ground.png", az);
	load_texture(az->main->rend, &az->game->hud, "texture/hud.png", az);
	load_texture(az->main->rend, &az->game->gun, "texture/portalgun.png", az);
	load_texture(az->main->rend, &az->game->ak, "texture/ak47_png.png", az);
	load_texture(az->main->rend, &az->game->portal1, "texture/portal1.png", az);
	load_texture(az->main->rend, &az->game->portal2, "texture/portal2.png", az);
	load_texture(az->main->rend, &az->game->health, "texture/health.png", az);
	load_texture(az->main->rend, &az->game->shield, "texture/shield.png", az);
	load_texture(az->main->rend, &az->game->nwall, "texture/wall1.jpeg", az);
	load_texture(az->main->rend, &az->game->swall, "texture/wall2.jpeg", az);
	load_texture(az->main->rend, &az->game->ewall, "texture/wall3.jpeg", az);
	load_texture(az->main->rend, &az->game->wwall, "texture/wall4.jpeg", az);
	load_texture(az->main->rend, &az->game->door, "texture/door.jpeg", az);
	load_texture(az->main->rend, &az->game->filler, "texture/MARBLES.bmp", az);
	load_texture(az->main->rend, &az->game->enemy, "texture/enemy.png", az);
}

void	loadoption(t_acz *az)
{
	load_texture(az->main->rend, &az->option->bg, "texture/option.png", az);
	load_texture(az->main->rend, &az->option->control,
			"texture/control.png", az);
	load_texture(az->main->rend, &az->option->select, "texture/valid.png", az);
	load_texture(az->main->rend, &az->option->choice, "texture/slider.png", az);
}

void	loadmenu(t_acz *az)
{
	az->main->effect = Mix_LoadWAV("texture/Gun.wav");
	az->main->portal1 = Mix_LoadWAV("texture/portalshoot1.wav");
	az->main->portal2 = Mix_LoadWAV("texture/portalshoot2.wav");
	load_texture(az->main->rend, &az->menu->bg, "texture/bg.png", az);
	load_texture(az->main->rend, &az->menu->choice, "texture/arrow.png", az);
}
