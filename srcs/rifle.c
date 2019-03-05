/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rifle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 11:19:39 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		rifle0(Uint16 mouse, t_acz *az)
{
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	az->shoot = (mouse & SDL_BUTTON_LMASK) == 1 ? 1 : 0;
	if (az->fx == 1)
		az->shoot == 1 ? Mix_PlayChannel(-1, az->main->portal1, 0) : 0;
	az->shoot1 = (mouse & SDL_BUTTON_RMASK) == 4 ? 1 : 0;
	if (az->fx == 1)
		az->shoot1 == 1 ? Mix_PlayChannel(-1, az->main->portal2, 0) : 0;
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	if (mouse & SDL_BUTTON_LMASK)
		load_texture(az->main->rend, &az->game->gun
				, "texture/portalshoot1.png");
	else if (mouse & SDL_BUTTON_RMASK)
		load_texture(az->main->rend, &az->game->gun
				, "texture/portalshoot2.png");
	else
		load_texture(az->main->rend, &az->game->gun
				, "texture/portalgun.png");
}

void		rifle1(Uint16 mouse, t_acz *az)
{
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	if (mouse & SDL_BUTTON_LMASK || mouse & SDL_BUTTON_RMASK)
		load_texture(az->main->rend, &az->game->gun, "texture/sword2.png");
	else
		load_texture(az->main->rend, &az->game->gun, "texture/sword.png");
}

void		rifle2(Uint16 mouse, t_acz *az)
{
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	if (mouse & SDL_BUTTON_LMASK || mouse & SDL_BUTTON_RMASK)
		load_texture(az->main->rend, &az->game->gun, "texture/P2.png");
	else
		load_texture(az->main->rend, &az->game->gun, "texture/P1.png");
}

void		rifle3(Uint16 mouse, t_acz *az)
{
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	if (mouse & SDL_BUTTON_LMASK || mouse & SDL_BUTTON_RMASK)
		load_texture(az->main->rend, &az->game->gun, "texture/box2.png");
	else
		load_texture(az->main->rend, &az->game->gun, "texture/box.png");
}

void		rifle4(Uint16 mouse, t_acz *az)
{
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	if (az->inv->akframe != 0 && az->inv->akframe < 96)
		az->inv->akframe += 1;
	else if ((mouse & SDL_BUTTON_LMASK || mouse & SDL_BUTTON_RMASK)
			&& az->inv->akframe == 0)
		az->inv->akframe = 1;
	else if (az->inv->akframe >= 96)
		az->inv->akframe = 0;
}
