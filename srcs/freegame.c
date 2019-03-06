/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freegame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:54:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 09:57:51 by lomasse          ###   ########.fr       */
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
	az->game->nwall != NULL ? SDL_DestroyTexture(az->game->nwall) : 0;
	az->game->swall != NULL ? SDL_DestroyTexture(az->game->swall) : 0;
	az->game->ewall != NULL ? SDL_DestroyTexture(az->game->ewall) : 0;
	az->game->wwall != NULL ? SDL_DestroyTexture(az->game->wwall) : 0;
	az->game->door != NULL ? SDL_DestroyTexture(az->game->door) : 0;
	az->game->filler != NULL ? SDL_DestroyTexture(az->game->filler) : 0;
	az->game->enemy != NULL ? SDL_DestroyTexture(az->game->enemy) : 0;
	az->game->ssky != NULL ? SDL_FreeSurface(az->game->ssky) : 0;
	az->game->sground != NULL ? SDL_FreeSurface(az->game->sground) : 0;
	free(az->game);
}
