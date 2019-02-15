/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:31:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/02/15 15:37:15 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
