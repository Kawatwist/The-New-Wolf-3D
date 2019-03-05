/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:59:00 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 17:03:36 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	printedit(t_acz *az)
{
	SDL_SetRenderDrawColor(az->main->rend, 30, 30, 30, 0);
	SDL_RenderClear(az->main->rend);
	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
	printgrill(az);
	SDL_SetRenderDrawColor(az->main->rend, 250, 120, 0, 0);
	SDL_RenderDrawLine(az->main->rend, az->info->editx,
			YSCREEN, az->info->editx, 0);
	SDL_RenderDrawLine(az->main->rend, 0, az->info->edity,
			600, az->info->edity);
	rectpos(az);
	SDL_RenderCopy(az->main->rend, az->menu->editor, NULL, &az->menu->redit);
	SDL_RenderCopy(az->main->rend, az->menu->select, NULL, &az->menu->rselect);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

void	showslider(t_acz *az)
{
	SDL_Rect	pos;

	pos.x = 800 * XSCREEN / 1600 + ((az->sensi - 0.0015) * 250000);
	pos.y = 330 * YSCREEN / 1200;
	pos.w = 30;
	pos.h = 30;
	SDL_RenderCopy(az->main->rend, az->option->choice, NULL, &pos);
}

void	showvalide(t_acz *az)
{
	SDL_Rect	pos;

	pos.x = 216 * XSCREEN / 1600;
	pos.y = 571 * YSCREEN / 1200;
	pos.w = 20;
	pos.h = 20;
	if (az->fullscreen == 1)
		SDL_RenderCopy(az->main->rend, az->option->select, NULL, &pos);
	if (az->mute == 1)
	{
		pos.y = 689 * YSCREEN / 1200;
		SDL_RenderCopy(az->main->rend, az->option->select, NULL, &pos);
	}
	if (az->fx == 1)
	{
		pos.y = 807 * YSCREEN / 1200;
		SDL_RenderCopy(az->main->rend, az->option->select, NULL, &pos);
	}
	if (az->hud == 1)
	{
		pos.y = 925 * YSCREEN / 1200;
		SDL_RenderCopy(az->main->rend, az->option->select, NULL, &pos);
	}
}

void	showhp(t_acz *az)
{
	SDL_Rect	pos;
	SDL_Rect	high;

	high.x = 0;
	high.y = 140 - (az->inv->health * 140 / 100);
	high.w = 81;
	high.h = 140 - high.y;
	pos.x = 3;
	pos.y = YSCREEN - 190 + high.y;
	pos.w = 81;
	pos.h = 140 - high.y;
	SDL_RenderCopy(az->main->rend, az->game->health, &high, &pos);
	high.y = 140 - (az->inv->shield * 140 / 100);
	high.h = 140 - high.y;
	pos.x = XSCREEN - 84;
	pos.y = YSCREEN - 190 + high.y;
	pos.h = 140 - high.y;
	SDL_RenderCopy(az->main->rend, az->game->shield, &high, &pos);
}

void	showhud(t_acz *az)
{
	SDL_Rect	pos;

	pos.x = 0;
	pos.y = YSCREEN - 200;
	pos.w = XSCREEN;
	pos.h = 200;
	SDL_RenderCopy(az->main->rend, az->game->hud, NULL, &pos);
	pos.x = 115;
	pos.y = YSCREEN - 105;
	pos.w = 100;
	pos.h = 100;
	loadcompas(az);
	SDL_RenderCopy(az->main->rend, az->game->compas, NULL, &pos);
	pos.x = 33;
	pos.y = YSCREEN - 104;
	pos.w = 101;
	pos.h = 90;
	if (az->map->blue[0] > 4 && az->map->blue[0] < 9)
		SDL_RenderCopy(az->main->rend, az->game->portal1, NULL, &pos);
	if (az->map->orange[0] > 4 && az->map->orange[0] < 9)
		SDL_RenderCopy(az->main->rend, az->game->portal2, NULL, &pos);
}
