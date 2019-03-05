/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freegame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:54:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 21:03:36 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	freeaz(t_acz *az)
{
	int	i;

	i = -1;
	while (++i < XSCREEN)
		az->ray[i] != NULL ? free(az->ray[i]) : 0;
	az->name_save ? free(az->name_save) : 0;
}

void	freesprite(t_sprite *sprite)
{
	if (sprite->next != NULL)
		freesprite(sprite->next);
	sprite != NULL ? free(sprite) : 0;
}

void	freegame(t_acz *az)
{
	az->game->sky != NULL ? SDL_DestroyTexture(az->game->sky) : 0;
	az->game->ground != NULL ? SDL_DestroyTexture(az->game->ground) : 0;
	az->game->hud != NULL ? SDL_DestroyTexture(az->game->hud) : 0;
	az->game->compas != NULL ? SDL_DestroyTexture(az->game->compas) : 0;
	az->game->gun != NULL ? SDL_DestroyTexture(az->game->gun) : 0;
	az->game->ak != NULL ? SDL_DestroyTexture(az->game->ak) : 0;
	az->game->sword != NULL ? SDL_DestroyTexture(az->game->sword) : 0;
	az->game->portal1 != NULL ? SDL_DestroyTexture(az->game->portal1) : 0;
	az->game->portal2 != NULL ? SDL_DestroyTexture(az->game->portal2) : 0;
	az->game->health != NULL ? SDL_DestroyTexture(az->game->health) : 0;
	az->game->shield != NULL ? SDL_DestroyTexture(az->game->shield) : 0;
	az->game->Nwall != NULL ? SDL_DestroyTexture(az->game->Nwall) : 0;
	az->game->Swall != NULL ? SDL_DestroyTexture(az->game->Swall) : 0;
	az->game->Ewall != NULL ? SDL_DestroyTexture(az->game->Ewall) : 0;
	az->game->Wwall != NULL ? SDL_DestroyTexture(az->game->Wwall) : 0;
	az->game->door != NULL ? SDL_DestroyTexture(az->game->door) : 0;
	az->game->Filler != NULL ? SDL_DestroyTexture(az->game->Filler) : 0;
	az->game->enemy != NULL ? SDL_DestroyTexture(az->game->enemy) : 0;
	az->game->ssky != NULL ? SDL_FreeSurface(az->game->ssky) : 0;
	az->game->sground != NULL ? SDL_FreeSurface(az->game->sground) : 0;
	free(az->game);
}
