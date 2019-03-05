/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:31:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 17:54:47 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	loadcompas(t_acz *az)
{
	while (az->info->angle > 6.28318)
		az->info->angle -= 6.28318;
	while (az->info->angle < 0)
		az->info->angle += 6.28318;
	if (az->game->compas != NULL)
		SDL_DestroyTexture(az->game->compas);
	if (az->info->angle >= 5.89048125 || az->info->angle <= 0.39269875)
		load_texture(az->main->rend, &az->game->compas, "texture/cursorN.png");
	else if (az->info->angle > 0.39269875 && az->info->angle <= 1.17809625)
		load_texture(az->main->rend, &az->game->compas, "texture/cursorNE.png");
	else if (az->info->angle > 1.1780965 && az->info->angle <= 1.96349375)
		load_texture(az->main->rend, &az->game->compas, "texture/cursorE.png");
	else if (az->info->angle > 1.96349375 && az->info->angle <= 2.74889125)
		load_texture(az->main->rend, &az->game->compas, "texture/cursorSE.png");
	else if (az->info->angle > 2.74889125 && az->info->angle <= 3.53428875)
		load_texture(az->main->rend, &az->game->compas, "texture/cursorS.png");
	else if (az->info->angle > 3.53428875 && az->info->angle <= 4.31968625)
		load_texture(az->main->rend, &az->game->compas, "texture/cursorSW.png");
	else if (az->info->angle > 4.31968625 && az->info->angle <= 5.10508375)
		load_texture(az->main->rend, &az->game->compas, "texture/cursorW.png");
	else
		load_texture(az->main->rend, &az->game->compas, "texture/cursorNW.png");
}

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
	load_texture(az->main->rend, &az->game->sky, "texture/sky3.png");
	load_texture(az->main->rend, &az->game->ground, "texture/ground.png");
	load_texture(az->main->rend, &az->game->hud, "texture/hud.png");
	load_texture(az->main->rend, &az->game->gun, "texture/portalgun.png");
	load_texture(az->main->rend, &az->game->ak, "texture/ak47_png.png");
	load_texture(az->main->rend, &az->game->portal1, "texture/portal1.png");
	load_texture(az->main->rend, &az->game->portal2, "texture/portal2.png");
	load_texture(az->main->rend, &az->game->health, "texture/health.png");
	load_texture(az->main->rend, &az->game->shield, "texture/shield.png");
	load_texture(az->main->rend, &az->game->Nwall, "texture/wall1.jpeg");
	load_texture(az->main->rend, &az->game->Swall, "texture/wall2.jpeg");
	load_texture(az->main->rend, &az->game->Ewall, "texture/wall3.jpeg");
	load_texture(az->main->rend, &az->game->Wwall, "texture/wall4.jpeg");
	load_texture(az->main->rend, &az->game->door, "texture/door.jpeg");
	load_texture(az->main->rend, &az->game->Filler, "texture/MARBLES.bmp");
	load_texture(az->main->rend, &az->game->enemy, "texture/enemy.png");
}

void	loadoption(t_acz *az)
{
	load_texture(az->main->rend, &az->option->bg, "texture/option.png");
	load_texture(az->main->rend, &az->option->control, "texture/control.png");
	load_texture(az->main->rend, &az->option->select, "texture/valid.png");
	load_texture(az->main->rend, &az->option->choice, "texture/slider.png");
}

void	loadmenu(t_acz *az)
{
	az->main->effect = Mix_LoadWAV("texture/Gun.wav");
	az->main->portal1 = Mix_LoadWAV("texture/portalshoot1.wav");
	az->main->portal2 = Mix_LoadWAV("texture/portalshoot2.wav");
	load_texture(az->main->rend, &az->menu->bg, "texture/bg.png");
	load_texture(az->main->rend, &az->menu->choice, "texture/arrow.png");
}
