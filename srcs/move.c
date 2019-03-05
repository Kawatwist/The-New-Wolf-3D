/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:53:27 by cbilga            #+#    #+#             */
/*   Updated: 2019/03/05 19:09:19 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		rotate_perso(t_acz *az)
{
	int		current;
	double	ang;

	current = 0;
	while (current < XSCREEN)
	{
		ang = (current * 0.002) + az->info->angle;
		az->ray[current]->posx = (az->info->range * cos(ang))
			+ (az->info->range * -sin(ang)) + (az->map->persox);
		az->ray[current]->posy = (az->info->range * sin(ang))
			+ (az->info->range * cos(ang)) + (az->map->persoy);
		current++;
	}
}

void		mouvement(t_acz *az, int move)
{
	double tmp;

	if (move == 0 || move == 2)
	{
		az->map->lastmovx = 0;
		az->map->lastmovy = (move == 2 ? 0.1 : -0.1) * az->speed;
	}
	else
	{
		az->map->lastmovx = (move == 3 ? 0.1 : -0.1) * az->speed;
		az->map->lastmovy = 0;
	}
	tmp = (az->map->lastmovx * cos(az->info->angle))
		+ (az->map->lastmovy * -sin(az->info->angle));
	az->map->lastmovy = (az->map->lastmovx * sin(az->info->angle))
		+ (az->map->lastmovy * cos(az->info->angle));
	az->map->lastmovx = tmp;
	az->map->persox += az->map->lastmovx;
	az->map->persoy += az->map->lastmovy;
	collision(az);
}
