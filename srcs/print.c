/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:34:32 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/06 16:07:34 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	setupmap(t_win *wn)
{
	int	i;
	int	j;

	i = 0;
	while (i < wn->y)
	{
		j = 0;
		while (j < wn->x)
		{
			wn->map[i][j] == 0 ? setrect(&wn, j, i, 0) : 0;
			wn->map[i][j] == 2 ? setrect(&wn, j, i, 2) : 0;
			wn->map[i][j] == 4 ? setrect(&wn, j, i, 4) : 0;
			wn->map[i][j] == 5 ? setrect(&wn, j, i, 5) : 0;
			j++;
		}
		i++;
	}
}

void	drawfov(t_win *wn)
{
	int i;

	i = 0;
	while(i < FOV)
	{
		if (i != 0)
			SDL_SetRenderDrawColor(wn->debug->rend, 0, 0, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(wn->debug->rend, wn->perso->posx, wn->perso->posy, wn->perso->vue[i].x + wn->perso->posx, wn->perso->vue[i].y + wn->perso->posy);
		i++;
	}
}

static void	otherdraw(t_win *wn, int ray, int raypos, int middle)
{
	if (ray > 0 && (wn->perso->vue[ray - 1].facex != wn->perso->vue[ray].facex || wn->perso->vue[ray - 1].facey != wn->perso->vue[ray].facey))
	{
		SDL_SetRenderDrawColor(wn->game->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(wn->game->rend, raypos, middle - OBS[ray].obs, raypos, middle + OBS[ray].obs);
	}
	if (wn->perso->vue[ray].other != 1)
	{
		wn->perso->vue[ray].other == 2 ? SDL_SetRenderDrawColor(wn->game->rend, 255, 0, 0, SDL_ALPHA_OPAQUE) : 0;
		wn->perso->vue[ray].other == 3 ? SDL_SetRenderDrawColor(wn->game->rend, 255, 0, 255, SDL_ALPHA_OPAQUE) : 0;
		wn->perso->vue[ray].other == 4 ? SDL_SetRenderDrawColor(wn->game->rend, 255, 255, 0, SDL_ALPHA_OPAQUE) : 0;
		wn->perso->vue[ray].other == 5 ? SDL_SetRenderDrawColor(wn->game->rend, 0, 255, 0, SDL_ALPHA_OPAQUE) : 0;
		SDL_RenderDrawLine(wn->game->rend, raypos, middle - 5, raypos, middle + 5);
	}
}

static void	splitscreen(t_win *wn, int ray, int raypos, int middle)
{
	int	diff;
	int	diff2;

	diff = OBS[ray].facex - OBS[ray + 1].facex;
	diff2 = OBS[ray].facey - OBS[ray + 1].facey;
	diff < 0 ? diff *= -1 : 0;
	diff2 < 0 ? diff2 *= -1 : 0;
	if ((diff > 1 && diff2 >= 1) || diff > 1 || diff2 > 1 || (diff >= 1 && diff2 > 1))
	{
		SDL_RenderDrawLine(wn->game->rend, raypos, middle - OBS[ray].obs, raypos, middle + OBS[ray].obs);
		if (OBS[ray].obs > OBS[ray + 1].obs)
		{
			SDL_RenderDrawLine(wn->game->rend, raypos, middle - OBS[ray + 1].obs, raypos + (wn->xscreen / FOV), middle - OBS[ray + 1].obs);
			SDL_RenderDrawLine(wn->game->rend, raypos, middle + OBS[ray + 1].obs, raypos + (wn->xscreen / FOV), middle + OBS[ray + 1].obs);
		}
		else
		{
			SDL_RenderDrawLine(wn->game->rend, raypos, middle - OBS[ray].obs, raypos + (wn->xscreen / FOV), middle - OBS[ray].obs);
			SDL_RenderDrawLine(wn->game->rend, raypos, middle + OBS[ray].obs, raypos + (wn->xscreen / FOV), middle + OBS[ray].obs);
		}
	}
	else
	{
		SDL_RenderDrawLine(wn->game->rend, raypos, middle - OBS[ray].obs, raypos + (wn->xscreen / FOV), middle - OBS[ray + 1].obs);
		SDL_RenderDrawLine(wn->game->rend, raypos, middle +  OBS[ray].obs, raypos + (wn->xscreen / FOV), middle +  OBS[ray + 1].obs);
	}
}

void	drawscreen(t_win *wn)
{
	int ray;
	int	raypos;
	int	middle;

	ray = 0;
	middle = wn->yscreen / 2;
	raycast(wn);
	while (ray < FOV)
	{
		raypos = ray * (wn->xscreen / (FOV - 3));
		SDL_SetRenderDrawColor(wn->game->rend, 0, 0, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(wn->game->rend, raypos, middle -  OBS[ray].obs, raypos, 0);
		SDL_SetRenderDrawColor(wn->game->rend, 0, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(wn->game->rend, raypos, middle +  OBS[ray].obs, raypos, wn->yscreen);
		SDL_SetRenderDrawColor(wn->game->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
		splitscreen(wn, ray, raypos, middle);
		otherdraw(wn, ray, raypos, middle);
		ray++;
	}
}

void	printdebug(t_win *wn)
{
	SDL_SetRenderDrawColor(wn->debug->rend, 120, 120, 120, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(wn->debug->rend);
	SDL_SetRenderDrawColor(wn->debug->rend, 0, 255, 255, SDL_ALPHA_OPAQUE);
	setupmap(wn);
	SDL_SetRenderDrawColor(wn->debug->rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
	raycast(wn);
	SDL_RenderPresent(wn->debug->rend);
	SDL_UpdateWindowSurface(wn->debug->wind);
}

void	printscreen(t_win *wn)
{
	SDL_SetRenderDrawColor(wn->game->rend, 120, 120, 120, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(wn->game->rend);
	drawscreen(wn);
	SDL_RenderPresent(wn->game->rend);
	setuprect(&wn->game->screen, 0, wn);
	setuprect(&wn->game->keys, 1, wn);
	SDL_BlitSurface(wn->game->key, NULL, wn->game->win, &wn->game->screen);
	SDL_UpdateWindowSurface(wn->game->wind);
	wn->dbug == 1 ? printdebug(wn) : 0;
}
