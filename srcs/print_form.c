/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:39:42 by lomasse           #+#    #+#             */
/*   Updated: 2019/02/28 12:18:39 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			printselect(t_acz *az)
{
	int x;
	int y;

	if (az->info->selmap == NULL)
		return ;
	y = 0;
	while (y < az->info->selsizey)
	{
		x = 0;
		while (x < az->info->selsizex)
		{
			if ((y + az->info->edity / 10) > 60 ||
					(x + az->info->editx / 10) > 60)
				break ;
			az->info->editmap[y + (az->info->edity / 10)]
				[x + (az->info->editx / 10)] = az->info->selmap[y][x];
			x++;
		}
		y++;
	}
}

void			printline(t_acz *az)
{
	int			i;
	int			j;
	double		value;
	SDL_Texture *tex;

	az->dst.w = 1;
	az->src.w = 1;
	az->src.h = 64;
	i = 0;
	raycast(az);
	if (az->jump != 0)
	{
		az->acl = az->acl - (0.098 * az->jump);
		az->mode -= az->acl;
	}
	//spritedist
	sprite_dist(az);
	while (i < XSCREEN)
	{
		value = az->info->range / az->ray[i]->obs;
		value < 0 ? value *= -1 : 0;
		value = value / 200;
		tex = pick_texture(az, i);
		j = (YSCREEN / 2) - value - (az->mode * (value / 680)) + ( az->vue * 5/* * 680 / 90*/);
		az->dst.y = j;
		az->dst.x = i;
		az->src.x = az->side[i] % SBLOCK;
		az->src.y = 0;
		az->dst.h = value * 2;
		SDL_RenderCopy(az->main->rend, tex, &az->src, &az->dst);
		//printf("Drawsprites\n");
		i++;
	}
	draw_sprites(az);
}

static void		printgrill2(t_acz *az)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 60)
	{
		x = -1;
		while (++x < 60)
		{
			SDL_SetRenderDrawColor(az->main->rend, 0, 0, 0, 0);
			SDL_RenderDrawLine(az->main->rend, y * 10, 0, y * 10, 600);
			SDL_RenderDrawLine(az->main->rend, 0, y * 10, 600, y * 10);
		}
	}
}

void			printgrill(t_acz *az)
{
	int			j;
	int			i;
	SDL_Rect	square;

	square.w = 10;
	square.h = 10;
	j = -1;
	while (++j < 60)
	{
		i = -1;
		while (++i < 60)
		{
			if (az->info->editmap[j][i] != 0)
			{
				square.x = j * 10;
				square.y = i * 10;
				az->info->editmap[j][i] == 1 ?
					SDL_SetRenderDrawColor(az->main->rend, 255, 255, 255, 0) : 0;
				az->info->editmap[j][i] == 2 ?
					SDL_SetRenderDrawColor(az->main->rend, 255, 0, 255, 0) : 0;
				az->info->editmap[j][i] == 3 ?
					SDL_SetRenderDrawColor(az->main->rend, 255, 0, 0, 0) : 0;
				az->info->editmap[j][i] == 4 ?
					SDL_SetRenderDrawColor(az->main->rend, 255, 150, 0, 0) : 0;
				az->info->editmap[j][i] == 5 ?
					SDL_SetRenderDrawColor(az->main->rend, 50, 100, 50, 0) : 0;
				az->info->editmap[j][i] == 8 ?
					SDL_SetRenderDrawColor(az->main->rend, 255, 200, 100, 0) : 0;
				az->info->editmap[j][i] == 9 ?
					SDL_SetRenderDrawColor(az->main->rend, 100, 100, 255, 0) : 0;
				az->info->editmap[j][i] == ENEMY ?
					SDL_SetRenderDrawColor(az->main->rend, 100, 0, 0, 0) : 0;
				SDL_RenderFillRect(az->main->rend, &square);
			}
		}
	}
	printgrill2(az);
}
