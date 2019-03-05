/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:25:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/05 11:18:03 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		mousegame(Uint16 mouse, t_acz *az, int x, int y)
{
	SDL_ShowCursor(az->interface != 1 ? SDL_ENABLE : SDL_DISABLE);
	SDL_CaptureMouse(az->interface == 1 ? 1 : 0);
	az->interface == 1 ? SDL_WarpMouseInWindow(az->main->window
			, XSCREEN / 2, YSCREEN / 2) : 0;
	az->info->angle += (x - 400) * az->sensi;
	if (az->vue < 50 && y < 300)
	{
		az->vue -= ((y - 300) * az->sensi) * 30;
		az->vue > 50 ? az->vue = 50 : 0;
	}
	else if (az->vue > -50 && y > 300)
	{
		az->vue -= ((y - 300) * az->sensi) * 30;
		az->vue > 50 ? az->vue = 50 : 0;
	}
	if (az->inv->rifle == 0)
		rifle0(mouse, az);
	else if (az->inv->rifle == 1)
		rifle1(mouse, az);
	else if (az->inv->rifle == 2)
		rifle2(mouse, az);
	else if (az->inv->rifle == 3)
		rifle3(mouse, az);
	else if (az->inv->rifle == 4)
		rifle4(mouse, az);
}

void		mouseoption(Uint16 mouse, t_acz *az, int x, int y)
{
	x = x * 1600 / XSCREEN;
	y = y * 1200 / YSCREEN;
	if ((x >= 216 && x <= 256) && (y >= 571 && y <= 610))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->fullscreen *= -1 : 0;
	else if ((x >= 216 && x <= 256) && (y >= 689 && y <= 729))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->mute *= -1 : 0;
	else if ((x >= 216 && x <= 256) && (y >= 807 && y <= 847))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->fx *= -1 : 0;
	else if ((x >= 216 && x <= 256) && (y >= 925 && y <= 965))
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->hud *= -1 : 0;
	if (y >= 342 && y <= 366 && x >= 820 && x <= 1375)
		(mouse & SDL_BUTTON_LMASK) == 1 ? az->sensi =
			0.0015 + ((x - 820) * 0.000002) : 0;
}

void		mouseedit(Uint16 mouse, t_acz *az, int x, int y)
{
	if (az->mouse == 1)
	{
		az->info->editx = x;
		az->info->edity = y;
		(mouse & SDL_BUTTON_LMASK) == 1 ?
			az->info->editmap[az->info->edity / 10][az->info->editx / 10] =
			az->info->editbrush : 0;
	}
}

void		mouseinput(t_acz *az)
{
	Uint16			mouse;
	int				x;
	int				y;

	mouse = SDL_GetMouseState(&x, &y);
	az->interface == 1 ? mousegame(mouse, az, x, y) : 0;
	az->interface == 2 ? mouseoption(mouse, az, x, y) : 0;
	az->interface == 3 ? mouseedit(mouse, az, x, y) : 0;
}
