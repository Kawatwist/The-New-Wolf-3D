/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:37:40 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 16:44:34 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		printline2(t_acz *az)
{
	int			i;
	int			j;
	double		value;
	SDL_Texture	*tex;

	i = 0;
	while (i < XSCREEN)
	{
		value = az->info->range / az->ray[i]->obs;
		value < 0 ? value *= -1 : 0;
		value = value / 200;
		tex = pick_texture(az, i);
		j = (YSCREEN / 2) - value - (az->mode * (value / 680)) + (az->vue * 5);
		az->dst.y = j;
		az->dst.x = i;
		az->src.x = az->side[i] % SBLOCK;
		az->src.y = 0;
		az->dst.h = value * 2;
		SDL_RenderCopy(az->main->rend, tex, &az->src, &az->dst);
		i++;
	}
}

void			printline(t_acz *az)
{
	az->dst.w = 1;
	az->src.w = 1;
	az->src.h = 64;
	raycast(az);
	if (az->jump != 0)
	{
		az->acl = az->acl - (0.098 * az->jump);
		az->mode -= az->acl;
	}
	sprite_dist(az);
	sort_sprite(&az->sprite);
	printline2(az);
	draw_sprites(az);
}
