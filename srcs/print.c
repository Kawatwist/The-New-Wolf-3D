/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:57:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/02/24 13:58:41 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	printedit(t_acz *az)
{
	SDL_SetRenderDrawColor(az->main->rend, 30, 30, 30, 0);
	SDL_RenderClear(az->main->rend);
	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
	printgrill(az);
	SDL_SetRenderDrawColor(az->main->rend, 250, 120, 0, 0);
	SDL_RenderDrawLine(az->main->rend, 0, az->info->editx,
			YSCREEN, az->info->editx);
	SDL_RenderDrawLine(az->main->rend, az->info->edity,
			0, az->info->edity, 600);
	rectpos(az);
	SDL_RenderCopy(az->main->rend, az->menu->editor, NULL, &az->menu->redit);
	SDL_RenderCopy(az->main->rend, az->menu->select, NULL, &az->menu->rselect);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

static void	showslider(t_acz *az)
{
	SDL_Rect	pos;

	pos.x = 800 * XSCREEN / 1600 + ((az->sensi - 0.0015) * 250000);
	pos.y = 330 * YSCREEN / 1200;
	pos.w = 30;
	pos.h = 30;
	SDL_RenderCopy(az->main->rend, az->option->choice, NULL, &pos);
}

static void	showvalide(t_acz *az)
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

static void	showhp(t_acz *az)
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

static void	showhud(t_acz *az)
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

static void	showgun(t_acz *az)
{
	SDL_Rect	pos;

	pos.w = 300;
	pos.h = 300;
	pos.x = 420 - (az->inv->frame * 2);
	az->inv->frame < 15 ? pos.y = 310 - (az->inv->frame % 20 * 2) : 0;
	az->inv->frame >= 15 ? pos.y = 285 + ((az->inv->frame - 15) % 16 * 2) : 0;
	az->inv->rifle == 2 ? pos.x -= 130 : 0;
	az->inv->rifle == 2 ? pos.y -= 80 : 0;
	az->inv->rifle == 3 ? pos.x = 0 : 0;
	az->inv->rifle == 3 ? pos.y = 0 : 0;
	az->inv->rifle == 3 ? pos.w = 800 : 0;
	az->inv->rifle == 3 ? pos.h = 600 : 0;
	SDL_RenderCopy(az->main->rend, az->game->gun, NULL, &pos);
	az->inv->frame == 30 ? az->inv->framesens *= -1 : 0;
	az->inv->frame == 0 ? az->inv->framesens *= -1 : 0;
	if (az->inv->frame < 30 && az->inv->framesens == 1)
		az->inv->frame += 1;
	else if (az->inv->frame > 0 && az->inv->framesens == -1)
		az->inv->frame -= 1;
}

static void	printoption(t_acz *az)
{
	SDL_SetRenderDrawColor(az->main->rend, 100, 100, 100, 0);
	SDL_RenderClear(az->main->rend);
	if (az->interface == 2)
	{
		SDL_RenderCopy(az->main->rend, az->option->bg, NULL, NULL);
		showvalide(az);
		showslider(az);
	}
	else
		SDL_RenderCopy(az->main->rend, az->option->control, NULL, NULL);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

static void	printgame(t_acz *az)
{
	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
	SDL_RenderClear(az->main->rend);
	showsky(az);
	SDL_RenderCopy(az->main->rend, az->game->ground,
			NULL, &az->game->rground);
	SDL_RenderCopy(az->main->rend, az->game->sky,
			&az->game->rsky2, &az->game->rsky);
	printline(az);
	SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
	az->hud == 1 ? showgun(az) : 0;
	az->hud == 1 ? showhud(az) : 0;
	az->hud == 1 ? showhp(az) : 0;
	SDL_RenderDrawLine(az->main->rend, XSCREEN / 2, (YSCREEN / 2) - 8,
			XSCREEN / 2, (YSCREEN / 2) + 8);
	SDL_RenderDrawLine(az->main->rend, (XSCREEN / 2) - 8, YSCREEN / 2,
			(XSCREEN / 2) + 8, YSCREEN / 2);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

static void	printmenu(t_acz *az)
{
	az->menu->rchoice.x = (az->menu->mode == 0 ||
			az->menu->mode == 2 ? 35 : 350);
	az->menu->rchoice.y = (az->menu->mode == 0 ||
			az->menu->mode == 1 ? 230 : 415);
	az->menu->rchoice.w = 75;
	az->menu->rchoice.h = 75;
	SDL_RenderCopy(az->main->rend, az->menu->bg, NULL, NULL);
	SDL_RenderCopy(az->main->rend, az->menu->choice, NULL, &az->menu->rchoice);
	SDL_RenderPresent(az->main->rend);
	SDL_UpdateWindowSurface(az->main->window);
}

void		print(t_acz *az)
{
	az->interface == 0 ? printmenu(az) : 0;
	az->interface == 1 ? printgame(az) : 0;
	az->interface == 2 ? printoption(az) : 0;
	az->interface == 3 ? printedit(az) : 0;
	az->interface == 4 ? printoption(az) : 0;
}
