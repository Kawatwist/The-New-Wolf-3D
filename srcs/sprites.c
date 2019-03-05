/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:32:30 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 11:27:10 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	initsurf(SDL_Rect *rect1, SDL_Rect *rect2, t_sprite *tmp, t_acz *az)
{
	double value;

	value = az->info->range / tmp->dist;
	rect1->x = 0;
	rect1->y = 0;
	rect1->h = tmp->sizey;
	rect1->w = tmp->sizex;
	rect2->x = -tmp->sizex / 2;
	rect2->y = ((YSCREEN - rect2->h) / 2)
		- (az->mode * (value / 10000)) + (az->vue * 5);
	rect2->h = YSCREEN / tmp->dist;
	rect2->w = XSCREEN / (tmp->dist * 2);
}

void		draw_sprites(t_acz *az)
{
	t_sprite	*tmp;
	SDL_Rect	rect1;
	SDL_Rect	rect2;
	int			i;

	tmp = az->sprite;
	while (tmp != NULL)
	{
		i = 0;
		while (i < XSCREEN)
		{
			initsurf(&rect1, &rect2, tmp, az);
			rect2.x = i;
			if (az->zbuffer[i] > tmp->dist)
			{
				if (isvisible(az, tmp, i))
				{
					SDL_RenderCopy(az->main->rend, tmp->tex, &rect1, &rect2);
					az->zbuffer[i] = tmp->dist;
				}
			}
			i++;
		}
		tmp = tmp->next;
	}
}
