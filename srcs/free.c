/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:05:27 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 11:52:18 by lomasse          ###   ########.fr       */
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

	i = -1;
	if (az->map->map != NULL)
	{
		while (++i < 60 && az->map->map[i] != NULL)
			az->map->map[i] != NULL ? free(az->map->map[i]) : 0;
		free(az->map->map);
	}
	free(az->map);
}

void	freeinfo(t_acz *az)
{
	int i;

	i = -1;
	if (az->info->selmap != NULL)
	{
		while (++i < az->info->selsizey && az->info->selmap[i] != NULL)
			az->info->selmap[i] != NULL ? free(az->info->selmap[i]) : 0;
		free(az->info->selmap);
	}
	free(az->info);
}

void	freemenu(t_acz *az)
{
	az->menu->bg != NULL ? SDL_DestroyTexture(az->menu->bg) : 0;
	az->menu->control != NULL ? SDL_DestroyTexture(az->menu->control) : 0;
	az->menu->editor != NULL ? SDL_DestroyTexture(az->menu->editor) : 0;
	az->menu->select != NULL ? SDL_DestroyTexture(az->menu->select) : 0;
	az->menu->choice != NULL ? SDL_DestroyTexture(az->menu->choice) : 0;
	az->menu->background != NULL ? SDL_FreeSurface(az->menu->background) : 0;
	az->menu->choices != NULL ? SDL_FreeSurface(az->menu->choices) : 0;
	az->menu->edit != NULL ? SDL_FreeSurface(az->menu->edit) : 0;
	free(az->menu);
}

void	freeoption(t_acz *az)
{
	az->option->bg != NULL ? SDL_DestroyTexture(az->option->bg) : 0;
	az->option->control != NULL ? SDL_DestroyTexture(az->option->control) : 0;
	az->option->editor != NULL ? SDL_DestroyTexture(az->option->editor) : 0;
	az->option->select != NULL ? SDL_DestroyTexture(az->option->select) : 0;
	az->option->choice != NULL ? SDL_DestroyTexture(az->option->choice) : 0;
	az->option->background != NULL ?
		SDL_FreeSurface(az->option->background) : 0;
	az->option->choices != NULL ? SDL_FreeSurface(az->option->choices) : 0;
	az->option->edit != NULL ? SDL_FreeSurface(az->option->edit) : 0;
	free(az->option);
}
