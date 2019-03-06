/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:31:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/06 10:26:32 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		compas2(t_acz *az)
{
	if (az->info->angle > 1.96349375 && az->info->angle <= 2.74889125)
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorSE.png", az);
	else if (az->info->angle > 2.74889125 && az->info->angle <= 3.53428875)
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorS.png", az);
	else if (az->info->angle > 3.53428875 && az->info->angle <= 4.31968625)
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorSW.png", az);
	else if (az->info->angle > 4.31968625 && az->info->angle <= 5.10508375)
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorW.png", az);
	else
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorNW.png", az);
}

void			loadcompas(t_acz *az)
{
	while (az->info->angle > 6.28318)
		az->info->angle -= 6.28318;
	while (az->info->angle < 0)
		az->info->angle += 6.28318;
	if (az->game->compas != NULL)
		SDL_DestroyTexture(az->game->compas);
	if (az->info->angle >= 5.89048125 || az->info->angle <= 0.39269875)
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorN.png", az);
	else if (az->info->angle > 0.39269875 && az->info->angle <= 1.17809625)
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorNE.png", az);
	else if (az->info->angle > 1.1780965 && az->info->angle <= 1.96349375)
		load_texture(az->main->rend, &az->game->compas,
				"texture/cursorE.png", az);
	else
		compas2(az);
}
