/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:57:38 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 17:04:07 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	if (az->inv->rifle == 4)
		akframe(az);
	else
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
	showsky(az);
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
