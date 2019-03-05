/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:05:27 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 18:42:00 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	freemain(t_acz *az)
{
	az->main->window != NULL ? SDL_DestroyWindow(az->main->window) : 0;
	az->main->rend != NULL ? SDL_DestroyRenderer(az->main->rend) : 0;
	az->main->tbg != NULL ? SDL_DestroyTexture(az->main->tbg) : 0;
	az->main->tother != NULL ? SDL_DestroyTexture(az->main->tother) : 0;
	az->main->sbg != NULL ? SDL_FreeSurface(az->main->sbg) : 0;
	az->main->sother != NULL ? SDL_FreeSurface(az->main->sother) : 0;
	az->main->song != NULL ? Mix_FreeMusic(az->main->song) : 0;
	az->main->effect != NULL ? Mix_FreeChunk(az->main->effect) : 0;
	az->main->portal1 != NULL ? Mix_FreeChunk(az->main->portal1) : 0;
	az->main->portal2 != NULL ? Mix_FreeChunk(az->main->portal2) : 0;
	free(az->main);
}

void	freemap(t_acz *az)
{
	int i;
	int j;

	i = -1;
	if (az->map->map != NULL)
	{
		while (++i < 60)
		{
			j = -1;
			while (++j < 60)
				az->map->map[i][j] ? free(&(az->map->map[i][j])) : 0;
			az->map->map[i] ? free(az->map->map[i]) : 0;
		}
	}
	free(az->map);
}

void	freeinfo(t_acz *az)
{
}
